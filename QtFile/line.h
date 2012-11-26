#ifndef TESTOVERLAY_H
#define TESTOVERLAY_H

#include <QtGui/QMainWindow>
#include <QWidget>
 
class line : public QWidget
{
public:
    line(QWidget *parent=0);

protected:
    void paintEvent(QPaintEvent *event);
public:
	unsigned int highPos;
	unsigned int lowPos;
};

#endif // TESTOVERLAY_H
