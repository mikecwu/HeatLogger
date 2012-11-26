#include "ConAPI.h"

ConAPI::ConAPI()
{
	int idStatus = 0;
	usertype = 1;
	if (!FInit()) {
		printf("An error occured while initializing the application\n");
		EXIT();
	}

	if (!DpcOpenData(&hif, szDefDvc, &erc, &trid)) {
		printf("DpcOpenData failed.\n");
		EXIT();
	}
}

ConAPI::~ConAPI()
{
	EXIT();
}


byteData ConAPI::read(char a, char b) 
{
	
	BYTE	idReg;
	BYTE	firstData;
	BYTE	secondData;
	char *	szStop;
	szFirstParam[0] = '1';
	szFirstParam[1] = a;
	idReg = (BYTE) strtol(szFirstParam, &szStop, 10);

	if (!DpcGetReg(hif, idReg, &firstData, &erc, NULL)) {
		printf("DpcGetReg failed1.\n");
		EXIT();
	}
	
	szFirstParam[0] = '1';
	szFirstParam[1] = b;
	idReg = (BYTE) strtol(szFirstParam, &szStop, 10);

	if (!DpcGetReg(hif, idReg, &secondData, &erc, NULL)) {
		printf("DpcGetReg failed2.\n");
		EXIT();
	}
	return byteData(firstData,secondData);
}

void ConAPI::write(char a, char b,unsigned int t, unsigned int d,unsigned int s) 
{
	BYTE	idReg;
	char *	szStop;
	usertype = optUserType(usertype);
	byteData temp = byteData(t,d,s,usertype);
	//cout << "byteData temp written:" << endl;
	//cout << temp;
	szFirstParam[0] = a;
	idReg = (BYTE) strtol(szFirstParam, &szStop, 10);
	if (!DpcWaitForTransaction(hif, trid, &erc)) {
		printf("DpcOpenData failed.\n");
		EXIT();
	}
	if (!DpcPutReg(hif, idReg, temp.getFirst(), &erc, NULL)) {
		printf("DpcGetReg failed.\n");
		EXIT();
	}

	szFirstParam[0] = b;
	idReg = (BYTE) strtol(szFirstParam, &szStop, 10);
	if (!DpcWaitForTransaction(hif, trid, &erc)) {
		printf("DpcOpenData failed.\n");
		EXIT();
	}
	if (!DpcPutReg(hif, idReg, temp.getSecond(), &erc, NULL)) {
		printf("DpcGetReg failed.\n");
		EXIT();
	}
}

void ConAPI::EXIT()
{
	DpcCloseData(hif, &erc);
	DpcTerm();
}

BOOL ConAPI::FInit() 
{
	ERC erc;
	int idDvc;
	if (!DpcInit(&erc)) {
		return fFalse;
	}
	/* DPCUTIL API CALL : DvmgGetDefaultDev
	*/
	idDvc = DvmgGetDefaultDev(&erc);
	if (idDvc == -1) {
		printf("No default device\n");
		return fTrue;
	}
	else {
		/* DPCUTIL API CALL : DvmgGetDevName
		*/
		DvmgGetDevName(idDvc,szDefDvc, &erc);
		strcpy(szDefDvc, szDefDvc);
		return fTrue;
	}
}

bool ConAPI::check(){
	BYTE	idReg;
	BYTE	firstData;
	char *	szStop;
	szFirstParam[0] = '1';
	szFirstParam[1] = '6';
	idReg = (BYTE) strtol(szFirstParam, &szStop, 10);

	if (!DpcGetReg(hif, idReg, &firstData, &erc, NULL)) {
		printf("DpcGetReg failed.\n");
		EXIT();
	}
	szFirstParam[0] = 0;
	szFirstParam[1] = 0;
	int result = firstData;
	if(result == 1){
		return true;
	}else{
		return false;
	}
}

void ConAPI::finishReading() {
	BYTE	idReg;
	BYTE    data = 0;
	char *	szStop;
	szFirstParam[0] = '1';
	szFirstParam[1] = '6';
	idReg = (BYTE) strtol(szFirstParam, &szStop, 10);
	if (!DpcWaitForTransaction(hif, trid, &erc)) {
		printf("DpcOpenData failed.\n");
		EXIT();
	}
	if (!DpcPutReg(hif, idReg, data, &erc, NULL)) {
		printf("DpcGetReg failed.\n");
		EXIT();
	}
	szFirstParam[0] = 0;
	szFirstParam[1] = 0;
}

void ConAPI::ready() {
	BYTE	idReg;
	BYTE    data = 1;
	char *	szStop;
	szFirstParam[0] = '2';
	szFirstParam[1] = '2';
	idReg = (BYTE) strtol(szFirstParam, &szStop, 10);
	if (!DpcWaitForTransaction(hif, trid, &erc)) {
		printf("DpcOpenData failed.\n");
		EXIT();
	}
	if (!DpcPutReg(hif, idReg, data, &erc, NULL)) {
		printf("DpcGetReg failed.\n");
		EXIT();
	}
	szFirstParam[0] = 0;
	szFirstParam[1] = 0;
}

unsigned int ConAPI::optUserType(unsigned int userType) {
	if(userType == 0){
		return 1;
	}else if(userType == 1) {
		return 0;
	}
}
