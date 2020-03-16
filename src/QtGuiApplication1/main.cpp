#include "WebEngineTest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	WebEngineTest w;
	w.show();
	return a.exec();
}
