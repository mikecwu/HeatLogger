#ifndef QTFILE_H
#define QTFILE_H

#include <QtGui/QMainWindow>
#include "ui_qtfile.h"
#include "line.h"
#include "gendefs.h"
#include "byteData.h"
#include "ConAPI.h"
#include "MyThread.h"
#include <algorithm>
#include <functional>
#include <numeric>
#include <QVector>

class QtFile : public QMainWindow, private Ui::QtFileClass
{
	Q_OBJECT

public:
	QtFile(QWidget *parent = 0, Qt::WFlags flags = 0);
	~QtFile();
	//MyThread *theThread;
	QTableWidgetItem *item;
	QTableWidgetItem *item1;
	QTableWidgetItem *item2;

private:
	Ui::QtFileClass ui;
	//line *highlightedLine;
	QVector<double> timeVector, tempVector,humVector, tempMeanVector, humMeanVector;
	QVector<double> tempLow, tempHigh, humLow, humHigh,lineValue;
	unsigned int dataIndex;
	clock_t init, final;
	MyThread *Timer;

	ERC		erc;
	HANDLE	hif;
	TRID trid;
	char			szFirstParam[8];
	char			szDefDvc[cchShortString+1];
	byteData tempRead(char, char, char, char);
	int idStatus;
	unsigned int usertype,checkTempType,countReadings;
	bool alarmEnable, hasAlarmGoneOff;
	double temperatureMean, temperatureMedian, temperatureSTD;
	double humMean, humMedian, humSTD;
	int temperatureMax, temperatureMin, humMax, humMin;
protected:
	void ready();
	void reset(); 
	void EXIT();
	bool FInit();
	void write(char a, char b,unsigned int t, double d,unsigned int s);
	unsigned int optUserType(unsigned int userType);
	int counterTemp;

private slots:
	void Take_Function(void);
	void Suppress_Function(void);
	void Test_Function(void);
	void onNumberChanged(int);
	void Temp_Button_Function(void);
	void Hum_Button_Function(void);
	void Single_Mode_Function(void);
	void Continious_Mode_Function(void);
};

#endif // QTFILE_H
