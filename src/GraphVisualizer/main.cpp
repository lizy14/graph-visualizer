/*
�ļ���: 
�衡��: 

������: ������, �廪��ѧ���ѧԺ, lizy14@yeah.net
������: 

������: Visual Studio 2012 (MSVC++ 11.0)
*/
#include "graphvisualizer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GraphVisualizer w;
	w.show();
	return a.exec();
}
