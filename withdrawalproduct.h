#ifndef WITHDRAWALPRODUCT_H
#define WITHDRAWALPRODUCT_H

#include <QDialog>

namespace Ui {
class WithdrawalProduct;
}

class WithdrawalProduct : public QDialog
{
    Q_OBJECT

public:
    explicit WithdrawalProduct(QWidget *parent = nullptr,QString username = "");
    ~WithdrawalProduct();

private slots:

    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::WithdrawalProduct *ui;
    QString username;

};

#endif // WITHDRAWALPRODUCT_H
