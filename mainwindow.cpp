#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <qdebug.h>
#include "register.h"
#include "login.h"
#include "loginadmin.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    MainWindow w;
    Register *nw = new Register();
    nw->setWindowTitle("Register");
    nw->show();
    this->hide();
}

void MainWindow::on_pushButton_2_clicked()
{
    MainWindow d;
    Login *lg = new Login();
    lg -> setWindowTitle("Login");
    lg -> show();
    this->hide();

}

void MainWindow::on_ExitBtn_clicked()
{

    QMessageBox::StandardButton reply= QMessageBox::critical(this,"My Title","Do you want to exit?",QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes){
        QApplication::quit();

    }else { qDebug () << "No is clicked"; }
}

void MainWindow::on_pushButton_7_clicked()
{
    loginAdmin *adm= new loginAdmin();
    this->hide();
    adm->setWindowTitle("Login-Admin");
    adm->show();
}
