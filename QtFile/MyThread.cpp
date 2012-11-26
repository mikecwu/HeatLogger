#include "MyThread.h"


MyThread::MyThread(QObject *parent) :
	QThread(parent)
{
	stopped = false;
}

void MyThread::stop()
{
	stopped = true;
}

void MyThread::run()
{
	int count = 0;
	int tempType = -1;
	msleep(600);
	while(true){
		msleep(30);
		QMutex mutex;
		mutex.lock();
		if(stopped)
			break;
		mutex.unlock();
		emit numberChanged(count);
		count++;
	}
}