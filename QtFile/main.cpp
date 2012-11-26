#include "qtfile.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtFile w;
	w.show();
	return a.exec();
}
