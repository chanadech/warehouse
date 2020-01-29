#ifndef USER_H
#define USER_H
#include <QString>
#include <iostream>
#include <vector>
#include <QTableView>
using namespace  std;

class User
{
public:
    User(QString username, QString password,  QString hotmail,double money){
        this->username = username;
        this->password = password;
        this->hotmail = hotmail;
        this->money = money;
    }
    User(){}

   void  DepositProduct(QString Order,QString ProductId ,QString Quantity,QString DepositDay ,QString WithdrawDay, QString Wherehouse_type ,QString username);





private:
class QString username;
class QString password;
class QString hotmail;
double money;


};

#endif // USER_H
