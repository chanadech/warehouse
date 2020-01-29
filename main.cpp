//#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include "newmainnew.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

NewMainNew n;
n.setWindowTitle("Welcome To Warehouse System");
n.show();



    return a.exec();
}
