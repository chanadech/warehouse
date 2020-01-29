#include "viewproducts.h"
#include "ui_viewproducts.h"
#include "menu.h"
#include "register.h"
#include "QSqlQueryModel"
#include "qdebug.h"

ViewProducts::ViewProducts(QWidget *parent,QString username) :
    QDialog(parent),
    ui(new Ui::ViewProducts)
{
    ui->setupUi(this);
    this->username = username;
    qDebug() << "Username Viewpd = " << username<< endl;
}

ViewProducts::~ViewProducts()
{
    delete ui;
}

void ViewProducts::on_pushButton_clicked()
{
    Menu *mn = new Menu(this,username);
    this-> hide();
    mn->setWindowTitle("Select Menu");
    mn->show();
}

void ViewProducts::on_pushButton_2_clicked()
{
 Register db;
  QSqlQueryModel *modal = new QSqlQueryModel();
  db.openDB();
  QSqlQuery query = QSqlQuery(db.db);
   query.prepare("SELECT Username,Order_detail.Order_id,Product_information.Product_name,Order_detail.Quantity, Order_detail.Depositpd_day,Order_detail.Withdrawpd_day,Order_detail.Wherehouse_type FROM Order_detail, User_order LEFT JOIN Product_information  on Order_detail.Product_id WHERE Order_detail.Product_id =Product_information.Product_id and Order_detail.Order_id = User_order.Order_id and Username = '"+username+"'"    );
   query.exec();
   modal->setQuery(query);
 ui->tableView-> setModel(modal);
 db.closeDB();
   qDebug()<< (modal->rowCount());
}
