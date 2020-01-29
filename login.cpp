#include "login.h"
#include "ui_login.h"
#include <QPixmap>
#include <QMessageBox>
#include "mainwindow.h"
#include <qdebug.h>
#include "register.h"
#include <QSqlQueryModel>
#include <qlabel.h>
Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
//    QPixmap pix("/Users/dech/Downloads/login-icon-png-19.png"); //add location file
//    int w =    ui->label_4-> width();
//    int h =    ui->label_4 -> height();
//    ui->label_4 -> setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->lineEdit_username->setPlaceholderText("*Enter Your Username");
    ui->lineEdit_password->setPlaceholderText("*Enter Your Password");
}

Login::~Login()
{
    delete ui;
}


void Login::on_pushButton_2_clicked()
{
    MainWindow *nw = new MainWindow();
    this -> hide();

      nw->show();
}


void Login::on_pushButton_Login_clicked()
{
      QString username = ui->lineEdit_username->text();
      QString password = ui->lineEdit_password->text();
        Register db;
//           not use QSqlQueryModel *modal = new QSqlQueryModel;
            db.openDB();
            // not use QSqlQuery query = QSqlQuery(User.db);
            QSqlQuery query ;
            query.prepare("select * from User where username='"+username +"' and pw ='" + password +"'");

                   if(query.exec()) {
                           int count = 0;
                           QString fullname;
                           while (query.next())
                           {   count++;
                                fullname = query.value(2).toString();
                               qDebug() << "queried name = " << fullname << endl;
                           }
                           if (count != 1)
                                 QMessageBox :: warning(this,"Login","Username and password is not correct");
                           else {
                                 QMessageBox :: information(this,"Login","Username and password is correct");
                               db.closeDB();
                               this->hide();
                                Menu *menu = new Menu(this, username); //pass constructor
                                menu->setModal(true);
                                menu -> setWindowTitle("Select Menu");
                                menu -> show();

                                menu->exec();


                           }
                   }

}


