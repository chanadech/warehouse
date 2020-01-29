#include "viewuser.h"
#include "ui_viewuser.h"
#include "register.h"
#include <QSqlQueryModel>
#include <qdebug.h>
#include "loginadmin.h"
ViewUser::ViewUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewUser)
{
    ui->setupUi(this);
}

ViewUser::~ViewUser()
{
    delete ui;
}

void ViewUser::on_pushButton_2_clicked()
{
    Register db;
    QSqlQueryModel *modal = new QSqlQueryModel;
    db.openDB();
    QSqlQuery query = QSqlQuery(db.db);
    query.prepare("select * from User");
    query.exec();
    modal->setQuery(query);
    ui->tableView-> setModel(modal);
    db.closeDB();
    qDebug()<< (modal->rowCount());
}

void ViewUser::on_pushButton_clicked()
{
    loginAdmin *l = new loginAdmin () ;
    this->hide();
    l->show();
}
