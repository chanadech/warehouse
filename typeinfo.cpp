#include "typeinfo.h"
#include "ui_typeinfo.h"
#include "depositproduct.h"
#include <qdebug.h>
#include <QString>

TypeInfo::TypeInfo(QWidget *parent,QString username) :
    QDialog(parent),
    ui(new Ui::TypeInfo)
{
    ui->setupUi(this);
    this->username = username;
    qDebug() << "Username Typeinfo = " << username<< endl;
}

TypeInfo::~TypeInfo()
{
    delete ui;
}

void TypeInfo::on_pushButton_clicked()
{

    DepositProduct *dp = new DepositProduct(this,username);
    dp->setWindowTitle("Choose type of Warehouse");
    this->close();

     dp->show();


}
