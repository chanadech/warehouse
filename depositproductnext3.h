#ifndef DEPOSITPRODUCTNEXT3_H
#define DEPOSITPRODUCTNEXT3_H

#include <QDialog>

namespace Ui {
class Depositproductnext3;
}

class Depositproductnext3 : public QDialog
{
    Q_OBJECT

public:
    explicit Depositproductnext3(QWidget *parent = nullptr,QString username = "");
    ~Depositproductnext3();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Depositproductnext3 *ui;
     QString username;
};

#endif // DEPOSITPRODUCTNEXT3_H
