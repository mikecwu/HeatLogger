#include "qtfile.h"
#include <qfont.h>

QtFile::QtFile(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	setupUi(this);
	dataIndex = 0;
	idStatus = 0;
	usertype = 1;
	checkTempType = -1;
	countReadings = 0;
	temperatureMax = 0;
	humMax = 0;
	if (!FInit()) {
		printf("An error occured while initializing the application\n");
		EXIT();
	}

	if (!DpcOpenData(&hif, szDefDvc, &erc, &trid)) {
		printf("DpcOpenData failed.\n");
		EXIT();
	}
	counterTemp = -1;
	init=clock();
	QFont newFont("Roboto-Light",12,QFont::Normal,false);
	setFont(newFont);
	hasAlarmGoneOff =false;
	//highlightedLine = new line(qCustomGraph);
	Timer = new MyThread(this);
	Timer->start();
	Temp_Radio->setChecked(true);
	qCustomGraph->addGraph();
	qCustomGraph->addGraph();
	qCustomGraph->addGraph();
	// give the axes some labels:
	qCustomGraph->xAxis->setLabel("Time");
	qCustomGraph->yAxis->setLabel("Temp");
	// set axes ranges, so we see all data:
	lineValue.push_back(-1000);
	lineValue.push_back(1000);
	tempLow.push_back(0);
	tempLow.push_back(0);
	tempHigh.push_back(80);
	tempHigh.push_back(80);
	humLow.push_back(0);
	humLow.push_back(0);
	humHigh.push_back(90);
	humHigh.push_back(90);
	qCustomGraph->xAxis->setRange(0, 30);
	qCustomGraph->yAxis->setRange(10, 50);
	qCustomGraph->graph(0)->setPen(QPen(Qt::blue));
	qCustomGraph->graph(1)->setPen(QPen(Qt::red));
	qCustomGraph->graph(2)->setPen(QPen(Qt::red));
	qCustomGraph->setRangeDrag(Qt::Horizontal | Qt::Vertical);
	qCustomGraph->setRangeZoom(Qt::Horizontal | Qt::Vertical);
	//qCustomGraph->setInteraction(QCustomPlot::iSelectPlottables);
	qCustomGraph->replot();
	
	ready();
	QObject::connect(Suppress_Button, SIGNAL(clicked()), this, SLOT(Suppress_Function()));
	QObject::connect(Timer, SIGNAL(numberChanged(int)), this, SLOT(onNumberChanged(int)));
	QObject::connect(Temp_Radio, SIGNAL(clicked()), this, SLOT(Temp_Button_Function(void)));
	QObject::connect(Hum_Radio, SIGNAL(clicked()), this, SLOT(Hum_Button_Function(void)));
	QObject::connect(Single_Mode, SIGNAL(clicked()), this, SLOT(Single_Mode_Function(void)));
	QObject::connect(Continious_Mode, SIGNAL(clicked()), this, SLOT(Continious_Mode_Function(void)));
}

QtFile::~QtFile()
{
	reset();
	Timer->stop();
	delete Timer;
	delete item;
	EXIT();
}

void QtFile::Test_Function(void)
{
	//QString qStr = QString::number(my_vector.at(my_vector.size()-1));
	//Temp_Label->setText(qStr);
	
}
unsigned int QtFile::optUserType(unsigned int userType){
	if(userType == 0){
		return 1;
	}else if(userType == 1) {
		return 0;
	}
}
void QtFile::write(char a, char b,unsigned int t, double d,unsigned int s) 
{
	BYTE	idReg;
	char *	szStop;
	szFirstParam[0] = 0;
	szFirstParam[1] = 0;
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
void QtFile::ready() 
{
	BYTE	idReg;
	char *	szStop;
	BYTE temp = 1;
	szFirstParam[0] = '2';
	szFirstParam[1] = '2';
	idReg = (BYTE) strtol(szFirstParam, &szStop, 10);
	if (!DpcWaitForTransaction(hif, trid, &erc)) {
		printf("DpcOpenData failed.\n");
		EXIT();
	}
	if (!DpcPutReg(hif, idReg, temp, &erc, NULL)) {
		printf("DpcGetReg failed.\n");
		EXIT();
	}
}
void QtFile::reset() 
{
	BYTE	idReg;
	char *	szStop;
	BYTE temp = 0;
	szFirstParam[0] = '2';
	szFirstParam[1] = '2';
	idReg = (BYTE) strtol(szFirstParam, &szStop, 10);
	if (!DpcWaitForTransaction(hif, trid, &erc)) {
		printf("DpcOpenData failed.\n");
		EXIT();
	}
	if (!DpcPutReg(hif, idReg, temp, &erc, NULL)) {
		printf("DpcGetReg failed.\n");
		EXIT();
	}
}
void QtFile::EXIT()
{
	DpcCloseData(hif, &erc);
	DpcTerm();
}
bool QtFile::FInit() 
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
byteData QtFile::tempRead(char a1,char a2, char b1, char b2) 
{
	BYTE	idReg;
	BYTE	firstData;
	BYTE	secondData;
	char *	szStop;

	szFirstParam[0] = a1;
	szFirstParam[1] = a2;
	idReg = (BYTE) strtol(szFirstParam, &szStop, 10);

	if (!DpcGetReg(hif, idReg, &firstData, &erc, NULL)) {
		printf("DpcGetReg failed1.\n");
		EXIT();
	}
	
	szFirstParam[0] = b1;
	szFirstParam[1] = b2;
	idReg = (BYTE) strtol(szFirstParam, &szStop, 10);

	if (!DpcGetReg(hif, idReg, &secondData, &erc, NULL)) {
		printf("DpcGetReg failed2.\n");
		EXIT();
	}
	return byteData(firstData,secondData);
}

void QtFile::Take_Function(void)
{
	if(Single_Mode->isChecked()){
		if(alarmEnable){
			write('8','9',1,0,1);
		}else {
			write('8','9',1,0,0);
		}
	}else {
		if(alarmEnable){
			write('8','9',1,0,3);
		}else {
			write('8','9',1,0,2);
		}
	}
}

void QtFile::Suppress_Function(void) {
	hasAlarmGoneOff = true;
	if(Single_Mode->isChecked()){
		write('8','9',0,0,3);
	}else {
		write('8','9',0,0,2);
	}
}

void QtFile::onNumberChanged(int a){
	byteData d = tempRead('1','0','1','1');
	byteData g = tempRead('1','2','1','3');
	if(checkTempType != g.getType()) {
		countReadings++;
		checkTempType = g.getType();
		QTime time = QTime::currentTime();
		To_Label->setText(time.toString());
		QTime lastTime = time.addSecs(-(abs(countReadings*0.2)));
		From_Label->setText(lastTime.toString());
		double tempHum = float(g.getHum())/10;
		if(g.getUserType() == 1){
			counterTemp++;
			//final=clock();
			//final = final - init;
			//double readTime = (double)final / ((double)CLOCKS_PER_SEC);
			item=new QTableWidgetItem (QString::number(counterTemp*0.2));
			item1=new QTableWidgetItem (QString::number( d.getData()));
			item2=new QTableWidgetItem (QString::number(tempHum));
			if((tableWidget->rowCount()) - 1 == counterTemp){
				tableWidget->setRowCount(tableWidget->rowCount()*3/2);
			}
			tableWidget->setItem(counterTemp,0,item);
			tableWidget->setItem(counterTemp,1,item1);
			tableWidget->setItem(counterTemp,2,item2);
			tableWidget->setCurrentCell(counterTemp,0,QItemSelectionModel::Deselect);
			timeVector.push_back(counterTemp*0.2);
			tempVector.push_back(d.getData());
			humVector.push_back(tempHum);
			tempMeanVector.push_back(d.getData());
			humMeanVector.push_back(tempHum);
			std::sort(tempMeanVector.begin(),tempMeanVector.end());
			std::sort(humMeanVector.begin(),humMeanVector.end());
			if(tempMeanVector.size() % 2 == 0) {
				temperatureMedian = (tempMeanVector.at(tempMeanVector.size()/2 - 1)+ tempMeanVector.at(tempMeanVector.size()/2)) / 2;
				humMedian = (humMeanVector.at(humMeanVector.size()/2 - 1)+ humMeanVector.at(humMeanVector.size()/2)) / 2;
			}else {
				temperatureMedian = tempMeanVector.at(tempMeanVector.size()/2);
				humMedian =humMeanVector.at(humMeanVector.size()/2);
			}
			if(temperatureMax < d.getData()){
				temperatureMax = d.getData();
			}
			if(temperatureMin > d.getData()){
				temperatureMin = d.getData();
			}
			if(tempVector.size() < 2) {
				temperatureMean = tempVector.at(0);
			}else {
				temperatureMean = (temperatureMean + d.getData())/2;
			}
			if(humMax < tempHum){
				humMax = tempHum;
			}
			if(humMin > tempHum){
				humMin = tempHum;
			}
			if(humVector.size() < 2) {
				humMean = humVector.at(0);
			}else {
				humMean = (humMean + tempHum)/2;
			}
			double sq_sum_temp = std::inner_product(tempMeanVector.begin(), tempMeanVector.end(), tempMeanVector.begin(), 0.0);
			double sq_sum_hum = std::inner_product(humMeanVector.begin(), humMeanVector.end(), humMeanVector.begin(), 0.0);
			temperatureSTD = std::sqrt(sq_sum_temp / tempMeanVector.size() - abs(temperatureMean * temperatureMean));
			humSTD = std::sqrt(sq_sum_hum / humMeanVector.size() - abs(humMean * humMean));
			Temp_Label->setText(QString::number(temperatureMean));
			Temp_Median->setText(QString::number(temperatureMedian));
			Temp_STD->setText(QString::number(temperatureSTD));
			Temp_Max->setText(QString::number(temperatureMax));
			Temp_Min->setText(QString::number(temperatureMin));
			Hum_Mean->setText(QString::number(humMean));
			Hum_Median->setText(QString::number(humMedian));
			Hum_STD->setText(QString::number(humSTD));
			Hum_Max->setText(QString::number(humMax));
			Hum_Min->setText(QString::number(humMin));
		}
		QString TempDisplay = QString::number(d.getData());
		QChar degreeSymbol(0xB0);
		TempDisplay.append(degreeSymbol);
		QString HumDisplay = QString::number(tempHum);
		QChar percentSymbol(0x25);
		HumDisplay.append(percentSymbol);
		Disp_Temp->setText(TempDisplay);
		Disp_Hum->setText(HumDisplay);
		byteData tempHighBound = tempRead('1','4','1','5');
		byteData tempLowBound = tempRead('1','6','1','7');
		byteData humHighBound = tempRead('1','8','1','9');
		byteData humLowBound = tempRead('2','0','2','1');
		if(Temp_Radio->isChecked()){
			qCustomGraph->yAxis->setLabel("Temperature");
			tempLow.clear();
			tempHigh.clear();
			tempLow.push_back(tempLowBound.getData());
			tempLow.push_back(tempLowBound.getData());
			tempHigh.push_back(tempHighBound.getData());
			tempHigh.push_back(tempHighBound.getData());
			qCustomGraph->graph(0)->setData(timeVector, tempVector);
			qCustomGraph->graph(1)->setData(lineValue,tempLow);
			qCustomGraph->graph(2)->setData(lineValue, tempHigh);
			//qCustomGraph->yAxis->setRange(0, 80);
		}else{
			qCustomGraph->yAxis->setLabel("Humidity");
			humLow.clear();
			humHigh.clear();
			double HumHigh = float(humHighBound.getHum())/10;
			double HumLow = float(humLowBound.getHum())/10;
			humLow.push_back(HumLow);
			humLow.push_back(HumLow);
			humHigh.push_back(HumHigh);
			humHigh.push_back(HumHigh);
			qCustomGraph->graph(0)->setData(timeVector, humVector);
			qCustomGraph->graph(1)->setData(lineValue,humLow);
			qCustomGraph->graph(2)->setData(lineValue, humHigh);
			//qCustomGraph->yAxis->setRange(0, 100);
		}
		qCustomGraph->replot();
		switch(g.getState()){
			case 0: {alarmEnable = true; 
				Alarm_Status->setText(QString("On"));
				Continious_Mode->setChecked(true);
				Single_Mode->setChecked(false);
				break;}
			case 1: {alarmEnable = true; 
				Alarm_Status->setText(QString("On"));
				Single_Mode->setChecked(true);
				Continious_Mode->setChecked(false);
				//write('8','9',0,0,1);
				break;}
			case 2: {alarmEnable = false; 
				Alarm_Status->setText(QString("Off"));
				Continious_Mode->setChecked(true);
				Single_Mode->setChecked(false);
				break;}
			case 3: {alarmEnable = false; 
				Alarm_Status->setText(QString("Off"));
				Single_Mode->setChecked(true);
				Continious_Mode->setChecked(false);
				//write('8','9',0,0,3);
				break;}
		}
		if((tempLowBound.getData() < d.getData() && d.getData() < tempHighBound.getData()) &&
			(humLowBound.getData() < g.getData() && g.getData() < humHighBound.getData()) && !alarmEnable && hasAlarmGoneOff){
			hasAlarmGoneOff = false;
			if(Single_Mode->isChecked()){
				write('8','9',0,0,1);
			}else {
				write('8','9',0,0,0);
			}
		}
	}
}

void QtFile::Temp_Button_Function(void){
	Hum_Radio->setChecked(false);
	qCustomGraph->yAxis->setLabel("Temperature");
	qCustomGraph->graph(0)->setData(timeVector, tempVector);
	qCustomGraph->yAxis->setRange(0, 80);
	qCustomGraph->replot();
}

void QtFile::Hum_Button_Function(void){
	Temp_Radio->setChecked(false);
	qCustomGraph->yAxis->setLabel("Humidity");
	qCustomGraph->graph(0)->setData(timeVector, humVector);
	qCustomGraph->yAxis->setRange(0, 100);
	qCustomGraph->replot();
}

void QtFile::Single_Mode_Function(void) {
	Single_Mode->setChecked(true);
	Continious_Mode->setChecked(false);
	if(alarmEnable){
		write('8','9',1,0,1);
	}else {
		write('8','9',1,0,3);
	}
}

void QtFile::Continious_Mode_Function(void) {
	Continious_Mode->setChecked(true);
	Single_Mode->setChecked(false);
	if(alarmEnable){
		write('8','9',0,0,0);
	}else {
		write('8','9',0,0,2);
	}
}

