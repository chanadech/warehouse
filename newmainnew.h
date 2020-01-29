#ifndef NEWMAINNEW_H
#define NEWMAINNEW_H

#include <QDialog>

namespace Ui {
class NewMainNew;
}

class NewMainNew : public QDialog
{
    Q_OBJECT

public:
    explicit NewMainNew(QWidget *parent = nullptr);
    ~NewMainNew();

private slots:
    void on_pushButton_clicked();

private:
    Ui::NewMainNew *ui;
};

#endif // NEWMAINNEW_H
