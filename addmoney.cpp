#include "addmoney.h"
#include "ui_addmoney.h"
#include "menu.h"
#include <QPixmap>
#include "register.h"
#include <QSqlQuery>
#include <QMessageBox>
#include "iostream"
#include "string"
#include <qdebug.h>
#include <sstream>
#include <QSqlQueryModel>
#include <qlabel.h>

AddMoney::AddMoney(QWidget *parent,QString username) :
    QDialog(parent),
    ui(new Ui::AddMoney)
{
    ui->setupUi(this);
    this->username = username;
    qDebug() << "Username add = " << username<< endl;
}

AddMoney::~AddMoney()
{
    delete ui;
}

void AddMoney::on_pushButton_clicked()
{
    Menu *mn = new Menu(this,username);
    this->hide();
    mn ->setWindowTitle("Select Menu");
    mn->show();
}

void AddMoney::on_pushButton_4_clicked()
{
 QString moneynew = ui->lineEdit->text();

 double x = moneynew.toDouble();
 if(moneynew != ""){
     Register db;
     db.openDB();
     QSqlQuery query;
      query.prepare("select money from User where username = '" + username + "'");
      qDebug() << "Flag Z" << endl;
      if(query.exec()) {
         int count = 0;
         double val ;
         qDebug() << "Enter if statment" << endl;
          while (query.next()){
              count++;
              val = query.value(0).toDouble();
              qDebug() << "Query Value Money" << val<< endl;
          }
            QString calculated_amount_str;
          qDebug() <<"countwhile" << count << endl;
          if (count == 1) {
              double calculated_amount = val + x;
              calculated_amount_str = QString::number(calculated_amount);
              qDebug() << "New Value = " << calculated_amount_str << endl;
              query.prepare("UPDATE User SET money = '" + calculated_amount_str +"' WHERE username = '" + username +"'");
              query.exec();
          }
          ui->label_2->setText(calculated_amount_str);

      }
      else {

          QMessageBox :: warning(this,"Add-money","Please fill in the form");

      }}}



