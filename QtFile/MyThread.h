#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <time.h>
#include <memory>
#include <QVector>
#include <QtCore>
#include <qthread.h>

class MyThread : public QThread
{
	Q_OBJECT
public:
	explicit MyThread(QObject *parent = 0);
	void stop();
protected:
	void run();
signals:
	void numberChanged(int);
private:
	bool stopped;
	double tempData;
	int typetemp;

};

#endif // QTFILE_H
