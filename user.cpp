#include "user.h"
#include "register.h"
#include "QSqlQuery"
#include <qdebug.h>



void User:: DepositProduct(QString Productname, QString ProductId, QString Quantity, QString DepositDay, QString WithdrawDay, QString Wherehouse_typeA,QString username){
    qDebug() << Productname;
qDebug() <<"UserNameIndepo" <<username;

             Register db;
             db.openDB();
             QSqlQuery query;
             QString PdID;
             query.prepare("select * from  Product_information where Product_name='"+Productname +"'");
             if(query.exec() == 1){
                       qDebug() << "Query Successful";
                   int count = 0 ;
                   QString pd;
                   while(query.next()){
                       count++;
                      pd = query.value(1).toString();
                       qDebug() << "queried name = " <<pd << endl;
                   }

                   if (count == 0 ){
                       qDebug() << "Unfound";
                       query.prepare("SELECT  Product_id FROM Product_information");
                       query.exec();
                       int counter = 0;
                       while(query.next()) {
                            counter++;
                       }
                       counter++;
                       qDebug() << "DB contains " << counter << "data";
                       qDebug() << counter << endl;
                       PdID = QString::number(counter);
                       query.prepare("INSERT INTO Product_information(Product_id,Product_name)""VALUES(?,?)");
                       query.addBindValue(counter);
                       query.addBindValue(Productname);
                       query.exec();
                   }


                   else {
                       qDebug() << "Found" ;
                       query.prepare("SELECT product_id FROM Product_information WHERE Product_name = '" + Productname + "'");
                       query.exec();
                       while (query.next()) {
                           qDebug() << query.value(0).toInt() << endl;
                           PdID = query.value(0).toString();
                       }
                   }

                   }
               QString order_no;
              query.prepare("select * from  Product_information where Product_id='"+ProductId +"'");
              if(query.exec() == 1) {
                        qDebug() << "Select Successful";
                    int count = 0 ;
                    QString pid;
                    while(query.next()){
                        count++;
                       pid = query.value(1).toString();
                        qDebug() << "queried1 name = " <<pid << endl;}

                    if (count == 0 ){
                        qDebug() << "Unfound";
                        query.prepare("SELECT Order_id FROM Order_detail");
                        query.exec();
                        int order_count = 0;
                        while(query.next()) {
                             order_count++;
                        } order_count++;
                        order_no = QString::number(order_count);
                        qDebug() << "Order No. : " << order_count << endl;
                        qDebug() << "DB contains1 " << order_count << "data";
                        query.prepare("INSERT INTO Order_detail(Order_id,Product_id,Quantity,Depositpd_day,Withdrawpd_day,Wherehouse_type)""VALUES(?,?,?,?,?,?)");
                        query.addBindValue(order_count);
                        query.addBindValue(PdID);
                        query.addBindValue(Quantity);
                        query.addBindValue(DepositDay);
                        query.addBindValue(WithdrawDay);
                        query.addBindValue(Wherehouse_typeA);
                        qDebug() << order_count;
                        qDebug() << PdID;
                        qDebug() << Quantity;
                        qDebug() << DepositDay;
                        qDebug() << WithdrawDay;
                        qDebug()<< Wherehouse_typeA;


                        query.exec();
                    }
                    else {
                        qDebug() << "Found" ;
                        query.prepare("SELECT Product_id FROM Order_id WHERE Product_id = '" + ProductId + "'");
                        query.exec();
                        while (query.next()) {
                            qDebug() << query.value(0).toInt() << endl;}
                    }

               }

                qDebug() << "order id" << order_no << " username" << username;
              query.prepare("INSERT INTO User_order(Username, Order_id) VALUES(?,?)");
              query.addBindValue(username);
              query.addBindValue(order_no);
              query.exec();
                db.closeDB();
                qDebug() << "end" << endl;

}

