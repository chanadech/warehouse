#ifndef ADDMONEY_H
#define ADDMONEY_H

#include <QDialog>

namespace Ui {
class AddMoney;
}

class AddMoney : public QDialog
{
    Q_OBJECT

public:
    explicit AddMoney(QWidget *parent = nullptr,QString username = "");
    ~AddMoney();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::AddMoney *ui;
    QString username;

};

#endif // ADDMONEY_H
