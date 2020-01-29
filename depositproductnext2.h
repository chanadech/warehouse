#ifndef DEPOSITPRODUCTNEXT2_H
#define DEPOSITPRODUCTNEXT2_H

#include <QDialog>

namespace Ui {
class Depositproductnext2;
}

class Depositproductnext2 : public QDialog
{
    Q_OBJECT

public:
    explicit Depositproductnext2(QWidget *parent = nullptr,QString username = "");
    ~Depositproductnext2();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::Depositproductnext2 *ui;
    QString username;

};

#endif // DEPOSITPRODUCTNEXT2_H
