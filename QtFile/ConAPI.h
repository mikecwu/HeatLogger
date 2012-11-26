#ifndef CONAPI_H
#define CONAPI_H

#include "gendefs.h"
#include "byteData.h"

using namespace std;

class ConAPI 
{
	//typedef Temperature = 
	
public:
    ConAPI();
	~ConAPI();
	byteData read(char, char);
	void write(char, char,unsigned int, unsigned int,unsigned int);
	bool check();
	void finishReading();
	void ready();
	unsigned int optUserType(unsigned int);
	
private:
	BOOL FInit(); 
	void EXIT();
	ERC		erc;
	HANDLE	hif;
	TRID trid;
	char			szFirstParam[8];
	char			szDefDvc[cchShortString+1];
	unsigned int usertype;
};

#endif // TESTOVERLAY_H