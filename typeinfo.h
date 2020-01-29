#ifndef TYPEINFO_H
#define TYPEINFO_H

#include <QDialog>

namespace Ui {
class TypeInfo;
}

class TypeInfo : public QDialog
{
    Q_OBJECT

public:
    explicit TypeInfo(QWidget *parent = nullptr,QString username = "");
    ~TypeInfo();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TypeInfo *ui;
    QString username;

};

#endif // TYPEINFO_H
