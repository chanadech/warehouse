#include "depositproductnext2.h"
#include "ui_depositproductnext2.h"
#include "depositproduct.h"
#include <QMessageBox>
#include <qdebug.h>
#include <QIntegerForSize>
#include "register.h"
#include "user.h"
#include "qdebug.h"
#include <QString>

Depositproductnext2::Depositproductnext2(QWidget *parent,QString username) :
    QDialog(parent),
    ui(new Ui::Depositproductnext2)
{
    ui->setupUi(this);
    this->username = username;
    qDebug() << "Username depoB = " << username<< endl;
    ui->lineEdit_5->setPlaceholderText("*Input Product name");
    ui->lineEdit_6->setPlaceholderText("*Input Quality");
    ui->lineEdit_7->setPlaceholderText("*Enter Your Deposit Day : DD/MM/YY ");
    ui->lineEdit_8->setPlaceholderText("*Enter Your Withdraw Day : DD/MM/YY ");

}

Depositproductnext2::~Depositproductnext2()
{
    delete ui;
}

void Depositproductnext2::on_pushButton_5_clicked()
{

   DepositProduct *dn = new DepositProduct(this,username);
   this->hide();
   dn->setWindowTitle("Choose Type of Warehouse");
   dn->show();
}

void Depositproductnext2::on_pushButton_6_clicked()
{
    Register db;
    User  x;
     QString Productname = ui->lineEdit_5->text();
     QString ProductId ;
     QString Quantity = ui->lineEdit_6->text();
 //    int Quantity = ui->lineEdit_2->text().toInt();
     QString DepositDay = ui->lineEdit_7->text();
     QString WithdrawDay = ui->lineEdit_8->text();
     QString Wherehouse_typeB = ui-> pushButton_4 ->text();

     if(Productname != ""&& Quantity != "" && DepositDay!="" && WithdrawDay !=""){

         qDebug() << Productname << Quantity << DepositDay << WithdrawDay << Wherehouse_typeB;
         QMessageBox::StandardButton reply ;
        int QuantityInt = ui->lineEdit_6->text().toInt();
        reply= QMessageBox::information(this,"Deposit","Deposit Success Please pay at the counter", QMessageBox::Ok);
        if (QMessageBox::Ok == reply) {
            x.DepositProduct(Productname,ProductId,Quantity,DepositDay,WithdrawDay,Wherehouse_typeB,username);
             qDebug() << "pressed ok" << endl;


             db.closeDB();
}
     }
}
