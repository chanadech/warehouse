#include "register.h"
#include "ui_register.h"
#include <QMessageBox>
#include <qdebug.h>
#include <mainwindow.h>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);

    ui->lineEdit->setPlaceholderText("*Enter Your Username");
    ui->lineEdit_2->setPlaceholderText("*Enter Your Password");
    ui->lineEdit_3->setPlaceholderText("*Enter Your E-mail");

}

Register::~Register()
{
    delete ui;
}

bool Register::openDB() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName("/Users/dech/Downloads/projectc++whdb.sqlite3");
            qDebug() << "DB connection status : " << db.open()<< endl;
            if (db.open() == true) {
                qDebug() << ("Database Connected.");
                return true;
            }
            else {
                qDebug() << ("Database Failed.");
                return false;
            }

}

void Register::closeDB() {
    db.close();
    db.removeDatabase(QSqlDatabase::defaultConnection);
}



void Register::on_pushButton_clicked()
{
    QString user = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    QString email = ui->lineEdit_3->text();
    if (user != "" && password != "" && email != "") {
        openDB();
        QSqlQuery query;
        query.prepare("select * from User where username='"+user +"'");
        if(query.exec()) {
                int count = 0;
                QString fullname;
                while (query.next())
                {   count++;
                    fullname = query.value(2).toString();
                    qDebug() << "queried name = " << fullname << endl;
                }
                qDebug() << count << endl;
                if (count == 1)
                      QMessageBox :: warning(this,"Register","This User has use already Please try again");
                else {
                     QMessageBox::information(this,"Register","Register Success", QMessageBox::Ok);

                     query.prepare("INSERT INTO User(username, pw, mail, money)""VALUES(?,?,?,?)");
                     query.addBindValue(user);
                     qDebug()<< user;
                     query.addBindValue(password);
                     qDebug()<< password;
                     query.addBindValue(email);
                     qDebug()<<email;
                     query.addBindValue(0);

                     query.exec();
                     closeDB();
                     qDebug() << "navigate to home";

                     this -> hide();
                     MainWindow *nw = new MainWindow();
                       nw->show();

                    }
        }
    }
    else {
        QMessageBox :: warning(this,"Register","Please fill in the form");
    }
}



void Register::on_pushButton_2_clicked()
{

    MainWindow *nw = new MainWindow();
    this -> hide();

      nw->show();
}

