#include "line.h"
#include <QPainter>
#include <QPen>
 
line::line(QWidget *parent)
    : QWidget(parent)
{
    setPalette(Qt::transparent);
    setAttribute(Qt::WA_TransparentForMouseEvents);
	highPos = width()/8;
}
 
void line::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(Qt::red));
    //painter.drawLine(xPos, height(), 5*xPos, height());
    //painter.drawLine(0, 0, width(), height());
	painter.drawLine(25, highPos, width()/2, highPos);
	painter.drawLine(25, lowPos, width()/2, lowPos);
}