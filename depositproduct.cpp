#include "depositproduct.h"
#include "ui_depositproduct.h"
#include "menu.h"
#include "depositproductnext1.h"
#include "typeinfo.h"
#include "depositproductnext2.h"
#include "depositproductnext3.h"
#include "login.h"
#include <qdebug.h>
DepositProduct::DepositProduct(QWidget *parent,QString username) :
    QDialog(parent),
    ui(new Ui::DepositProduct)
{
    ui->setupUi(this);
    this->username = username;
    qDebug() << "Username depo = " << username<< endl;
}

DepositProduct::~DepositProduct()
{
    delete ui;
}

void DepositProduct::on_pushButton_4_clicked()
{
   Menu *mn = new Menu(this,username);
   this -> hide ();
   mn->setWindowTitle("Select Menu");
   mn -> show();
}

void DepositProduct::on_pushButton_2_clicked()
{
    DepositProductNext1 *dn = new DepositProductNext1(this, username);
    qDebug() << "After select type username = " << username << endl;
    this ->  hide();
    dn->setWindowTitle("Choose Type of Warehouse");
    dn-> show();
}


void DepositProduct::on_pushButton_5_clicked()
{
    TypeInfo *tp = new TypeInfo(this, username);
    qDebug() << "After select typeinfo = " << username << endl;

    tp->setWindowTitle("Detail for types of Warehouse");
    this -> hide();
    tp->show();


}

void DepositProduct::on_pushButton_clicked()
{
   Depositproductnext2 *dp2 = new Depositproductnext2(this, username);
    qDebug() << "After select type username = " << username << endl;
   dp2->setWindowTitle("Deposit Product Type B");
   this->hide();
   dp2->show();
}

void DepositProduct::on_pushButton_3_clicked()
{
    Depositproductnext3 *dp3 = new Depositproductnext3(this, username);
     qDebug() << "After select type username = " << username << endl;
    dp3->setWindowTitle("Deposit Product Type C");
    this->hide();
    dp3->show();

}
