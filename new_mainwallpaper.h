#ifndef NEW_MAINWALLPAPER_H
#define NEW_MAINWALLPAPER_H
#include <QDialog>

namespace Ui {
class new_mainwallpaper;
}
class new_mainwallpaper:public QDialog
{
    Q_OBJECT

public:
    explicit new_mainwallpaper(QWidget *parent = nullptr);
    ~new_mainwallpaper();
 private slots:

private:
    Ui::new_mainwallpaper *ui;
};

#endif // NEW_MAINWALLPAPER_H









