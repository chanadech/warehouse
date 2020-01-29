#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <user.h>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    QSqlDatabase db;
    bool openDB();
    void closeDB();

    ~Register();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();



private:
    Ui::Register *ui;
};

#endif // REGISTER_H
