#include "byteData.h"


byteData::byteData()
{

}

byteData::byteData(BYTE first,BYTE second)
{
	firstByte = first;
	secondByte = second;
	//printByte(first);
	//printByte(second);
	//std::cout << "--------" << std::endl;
	BYTE temp = first >> 7;
	type = temp;
	//std::cout << "type: " << type << std::endl;
	int temp1 = second >> 3;
	temp = first << 1;
	//std::cout << "firstdata: " << data << std::endl;
	data = temp << 4 | temp1;
	BYTE lastFour = second << 1;
	lastFour = lastFour >> 4;
	int out = lastFour;
	Ddata = (data>>4) + decimalConvert(out);
	//std::cout << "seconddata: " << temp1 << std::endl;
	temp = second << 5;
	state = temp >> 6;
	BYTE mask = 1;//255;
	userType = second & mask;
	//userType = tempUser >> 7;
	//std::cout << "state: " << state << std::endl;
}

byteData::byteData(unsigned int t,double d,int s,unsigned int u)
{
	unsigned char mask = 1;
	type = t;
	Ddata = d;
	data = d;
	state = s;
	userType = u;
	firstByte = data>>5 | type << 7;
	secondByte = data<<3 | state<<1 | u;
	std::cout << "first:" << std::endl;
	printByte(firstByte);
	std::cout << "second:" << std::endl;
	printByte(secondByte);
}

byteData::~byteData(){

}

BYTE byteData::getFirst() {
	return firstByte;
}

BYTE byteData::getSecond() {
	return secondByte;
}

double byteData::getData() {
	return Ddata;
}

unsigned int byteData::getHum() {
	return data;
}
unsigned int byteData::getType() {
	return type;
}

unsigned int byteData::getUserType() {
	return userType;
}
std::ostream& operator<<(std::ostream& out, const byteData& m)
{
	out << "type: " << m.type << " data: " << m.data << " state: " << m.state << std::endl;
	unsigned int bits[8];
	unsigned int mask = 1;
	out << "first byte: " << m.firstByte << " = ";
	for(int i = 7; i >= 0; i--){
		bits[i] = (m.firstByte & (mask << i)) != 0;
		out << bits[i];
	}
	out << std::endl <<  "second byte: "  << m.secondByte << " = ";
	for(int i = 7; i >= 0; i--){
		bits[i] = (m.secondByte & (mask << i)) != 0;
		out << bits[i];
	}
	out << std::endl;
	return out;
}
double byteData::decimalConvert(int lastFour) {
	switch(lastFour){
	case 0: return 0.0;
	case 1: return 0.1;
	case 2: return 0.1;
	case 3: return 0.2;
	case 4: return 0.3;
	case 5: return 0.3;
	case 6: return 0.4;
	case 7: return 0.4;
	case 8: return 0.5;
	case 9: return 0.6;
	case 10: return 0.6;
	case 11: return 0.7;
	case 12: return 0.8;
	case 13: return 0.8;
	case 14: return 0.9;
	case 15: return 0.9;
	}
}
unsigned int byteData::getState() {
	return state;
}
void  byteData::printByte(BYTE temp) {
	unsigned char bits[8];
	unsigned char mask = 1;
	for(int i = 7; i >= 0; i--){
		bits[i] = (temp & (mask << i)) != 0;
	}
	for(int i = 7; i >= 0; i--) {
		printf("%d",bits[i]);
	}
	printf("\n");
}