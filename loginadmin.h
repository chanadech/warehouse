#ifndef LOGINADMIN_H
#define LOGINADMIN_H

#include <QDialog>

namespace Ui {
class loginAdmin;
}

class loginAdmin : public QDialog
{
    Q_OBJECT

public:
    explicit loginAdmin(QWidget *parent = nullptr);
    ~loginAdmin();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_Login_clicked();

private:
    Ui::loginAdmin *ui;
};

#endif // LOGINADMIN_H
