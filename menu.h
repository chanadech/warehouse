#ifndef MENU_H
#define MENU_H
#include "depositproduct.h"
#include <QDialog>

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr,QString username = "");
    ~Menu();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Menu *ui;
    QString username;
    DepositProduct *dp;
};

#endif // MENU_H
