#include "stdafx.h"
#include "rdlivesdkdemo.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);



	RDLiveSdkDemo w;
	w.show();
	return a.exec();
}
