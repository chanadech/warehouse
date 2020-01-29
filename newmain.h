#ifndef NEWMAIN_H
#define NEWMAIN_H

#include <QDialog>

namespace Ui {
class NewMain;
}

class NewMain : public QDialog
{
    Q_OBJECT

public:
    explicit NewMain(QWidget *parent = nullptr);
    ~NewMain();

private:
    Ui::NewMain *ui;
};

#endif // NEWMAIN_H
