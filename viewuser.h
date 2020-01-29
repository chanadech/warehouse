#ifndef VIEWUSER_H
#define VIEWUSER_H

#include <QDialog>

namespace Ui {
class ViewUser;
}

class ViewUser : public QDialog
{
    Q_OBJECT

public:
    explicit ViewUser(QWidget *parent = nullptr);
    ~ViewUser();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::ViewUser *ui;
};

#endif // VIEWUSER_H
