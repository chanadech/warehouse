#include "loginadmin.h"
#include "ui_loginadmin.h"
#include "mainwindow.h"
#include "QMessageBox"
#include "viewuser.h"
loginAdmin::loginAdmin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginAdmin)
{
    ui->setupUi(this);
}

loginAdmin::~loginAdmin()
{
    delete ui;
}

void loginAdmin::on_pushButton_2_clicked()
{
 MainWindow *mn = new MainWindow();
 this->hide();
 mn->show();
}

void loginAdmin::on_pushButton_Login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    if(username ==  "0" and password == "0"){
        QMessageBox :: information(this,"Login","Login Success");
        ViewUser *v = new ViewUser();
        v->setWindowTitle("Admin");
        this->hide();
        v->show();
    }
    else{
        QMessageBox::warning(this,"Login","Username or Password is not correct");

    }
}
