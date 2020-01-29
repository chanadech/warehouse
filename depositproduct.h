#ifndef DEPOSITPRODUCT_H
#define DEPOSITPRODUCT_H

#include <QDialog>

namespace Ui {
class DepositProduct;
}

class DepositProduct : public QDialog
{
    Q_OBJECT

public:
    explicit DepositProduct(QWidget *parent = nullptr,QString username = "");
    ~DepositProduct();

private slots:
    void on_pushButton_4_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::DepositProduct *ui;
     QString username;
};

#endif // DEPOSITPRODUCT_H
