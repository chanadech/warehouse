#ifndef VIEWPRODUCTS_H
#define VIEWPRODUCTS_H

#include <QDialog>

namespace Ui {
class ViewProducts;
}

class ViewProducts : public QDialog
{
    Q_OBJECT

public:
    explicit ViewProducts(QWidget *parent = nullptr,QString username = "");
    ~ViewProducts();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ViewProducts *ui;
    QString username;

};

#endif // VIEWPRODUCTS_H
