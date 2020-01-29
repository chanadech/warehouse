#include "depositproductnext3.h"
#include "ui_depositproductnext3.h"
#include "depositproduct.h"
#include <QMessageBox>
#include <qdebug.h>
#include <QIntegerForSize>
#include "register.h"
#include "user.h"
#include "qdebug.h"
#include <QString>

Depositproductnext3::Depositproductnext3(QWidget *parent,QString username) :
    QDialog(parent),
    ui(new Ui::Depositproductnext3)
{
    ui->setupUi(this);
    this->username = username;
    qDebug() << "Username depoC = " << username<< endl;
    ui->lineEdit->setPlaceholderText("*Input Product name");
    ui->lineEdit_2->setPlaceholderText("*Input Quality");
    ui->lineEdit_3->setPlaceholderText("*Enter Your Deposit Day : DD/MM/YY ");
    ui->lineEdit_4->setPlaceholderText("*Enter Your Withdraw Day : DD/MM/YY ");

}

Depositproductnext3::~Depositproductnext3()
{
    delete ui;
}

void Depositproductnext3::on_pushButton_2_clicked()
{
    DepositProduct *dn = new DepositProduct(this,username);
    qDebug() << "Username back buttonc" << username << endl;
    this->hide();
    dn->setWindowTitle("Choose Type of Warehouse");
    dn->show();
}

void Depositproductnext3::on_pushButton_clicked()
{
    Register db;
    User  x;
     QString Productname = ui->lineEdit->text();
     QString ProductId ;
     QString Quantity = ui->lineEdit_2->text();
 //    int Quantity = ui->lineEdit_2->text().toInt();
     QString DepositDay = ui->lineEdit_3->text();
     QString WithdrawDay = ui->lineEdit_4->text();
     QString Wherehouse_typeC = ui-> pushButton_3 ->text();

     if(Productname != ""&& Quantity != "" && DepositDay!="" && WithdrawDay !=""){

         qDebug() << Productname << Quantity << DepositDay << WithdrawDay << Wherehouse_typeC;
         QMessageBox::StandardButton reply ;
        int QuantityInt = ui->lineEdit_2->text().toInt();
        reply= QMessageBox::information(this,"Deposit","Deposit Success Please pay at the counter", QMessageBox::Ok);
        if (QMessageBox::Ok == reply) {
            x.DepositProduct(Productname,ProductId,Quantity,DepositDay,WithdrawDay,Wherehouse_typeC,username);
             qDebug() << "pressed ok" << endl;


             db.closeDB();
}
     }
}
