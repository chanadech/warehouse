#include "menu.h"
#include "ui_menu.h"
#include "login.h"
#include <mainwindow.h>
#include "depositproduct.h"
#include "withdrawalproduct.h"
#include "viewproducts.h"
#include "addmoney.h"
#include   <qdebug.h>
Menu::Menu(QWidget *parent,QString username) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    this->username = username;
    qDebug() << "Username = " << username<< endl;
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButton_5_clicked()
{
    MainWindow *nw = new MainWindow();
    this -> hide();
      nw->show();
}

void Menu::on_pushButton_clicked()
{
    DepositProduct *dp = new DepositProduct(this, username);

    this ->  hide();
    dp->setWindowTitle("Choose Type");
    dp -> show();
}

void Menu::on_pushButton_2_clicked()
{
    WithdrawalProduct *wp = new WithdrawalProduct(this,username);
    this -> hide();

    wp->setWindowTitle("Products Withdrawal ");
    wp->show();
}

void Menu::on_pushButton_3_clicked()
{
    ViewProducts *vp = new ViewProducts(this,username);
    this->hide();
    vp->setWindowTitle("View Products");
    vp->show();
}

void Menu::on_pushButton_4_clicked()
{
    AddMoney *am = new AddMoney(this,username);
    this->hide();
    am->setWindowTitle("Add - Money");
    am->show();
}
