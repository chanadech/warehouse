#ifndef LOGIN_H
#define LOGIN_H
#include <menu.h>
#include <QMessageBox>
namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_Login_clicked();


private:
    Ui::Login *ui;
    Menu *menu;
};

#endif // LOGIN_H
