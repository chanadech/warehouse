#include "withdrawalproduct.h"
#include "ui_withdrawalproduct.h"
#include "menu.h"
#include "QSqlQueryModel"
#include "qdebug.h"
#include "register.h"
#include <QMessageBox>
WithdrawalProduct::WithdrawalProduct(QWidget *parent,QString username) :
    QDialog(parent),
    ui(new Ui::WithdrawalProduct)
{
    ui->setupUi(this);
    this->username = username;
    qDebug() << "Username Viewpd wd = " << username<< endl;
}

WithdrawalProduct::~WithdrawalProduct()
{
    delete ui;
}



void WithdrawalProduct::on_pushButton_clicked()
{
    Menu *mn = new Menu(this,username);

    this->hide();
    mn->setWindowTitle("Select Menu");
    mn->show();
}


void WithdrawalProduct::on_pushButton_2_clicked()
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

void WithdrawalProduct::on_pushButton_3_clicked()
{
QString OrderID = ui->lineEdit->text();
Register db;
db.openDB();
QSqlQuery query ;
query.prepare("SELECT Username,Order_detail.Order_id,Product_information.Product_name,Order_detail.Quantity, Order_detail.Depositpd_day,Order_detail.Withdrawpd_day,Order_detail.Wherehouse_type FROM Order_detail, User_order LEFT JOIN Product_information  on Order_detail.Product_id WHERE Order_detail.Product_id =Product_information.Product_id and Order_detail.Order_id = User_order.Order_id and Username = '"+username+"' and User_order.Order_id = '"+OrderID+"'    ");

       if(query.exec()) {
               int count = 0;
               QString fullname;
               while (query.next())
               {   count++;
                    fullname = query.value(2).toString();
                   qDebug() << "queried name = " << fullname << endl;
               }
               if (count != 1)
                     QMessageBox :: warning(this,"Order_id","Dont have this order id");

               else {
                   query.prepare("Delete from User_order where Order_id = '"+OrderID+ "'");
                     QMessageBox :: information(this,"Order_id","Withdraw Success");

                   query.exec();
                    db.closeDB();

}
       }
}
