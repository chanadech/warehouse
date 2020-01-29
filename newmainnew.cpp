#include "newmainnew.h"
#include "ui_newmainnew.h"
#include "mainwindow.h"
NewMainNew::NewMainNew(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewMainNew)
{
    ui->setupUi(this);
}

NewMainNew::~NewMainNew()
{
    delete ui;
}

void NewMainNew::on_pushButton_clicked()
{
    MainWindow *mn = new MainWindow();
    this->hide();
    mn->setWindowTitle("Select Menu");
    mn->show();
}
