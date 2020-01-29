#ifndef DEPOSITPRODUCTNEXT1_H
#define DEPOSITPRODUCTNEXT1_H
#include <QDialog>

namespace Ui {
class DepositProductNext1;
}

class DepositProductNext1 : public QDialog
{
    Q_OBJECT

public:
    explicit DepositProductNext1(QWidget *parent = nullptr,QString username = "");
    ~DepositProductNext1();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();


private:
    Ui::DepositProductNext1 *ui;
    QString username;
};

#endif // DEPOSITPRODUCTNEXT1_H
