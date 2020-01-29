#include "newmain.h"
#include "ui_newmain.h"

NewMain::NewMain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewMain)
{
    ui->setupUi(this);
}

NewMain::~NewMain()
{
    delete ui;
}
