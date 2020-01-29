#include "new_mainwallpaper.h"
#include "ui_new_mainwallpaper.h"


new_mainwallpaper::new_mainwallpaper(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::new_mainwallpaper)
{
    ui->setupUi(this);
}

new_mainwallpaper::~new_mainwallpaper()
{
    delete ui;
}
