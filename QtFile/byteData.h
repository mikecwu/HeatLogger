#ifndef BYTEDATA_H
#define BYTEDATA_H
#include "gendefs.h"


class byteData 
{
public:
	byteData();
    byteData(BYTE,BYTE);
	byteData(unsigned int,double,int,unsigned int);
	~byteData();
	BYTE getFirst();
	BYTE getSecond();
	double getData();
	unsigned int getHum();
	unsigned int getType();
	unsigned int getState();
	unsigned int getUserType();
	void  printByte(BYTE temp);
	friend std::ostream& operator << (std::ostream& out, const byteData&);
	double decimalConvert(int);

private:
	BYTE firstByte;
	BYTE secondByte;
	unsigned int type;
	unsigned int data;
	double Ddata;
	unsigned int state;
	unsigned int userType;
};

#endif