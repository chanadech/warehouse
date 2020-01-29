#-------------------------------------------------
#
# Project created by QtCreator 2019-04-16T22:40:47
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = warehouse
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        addmoney.cpp \
        depositproduct.cpp \
        depositproductnext1.cpp \
        depositproductnext2.cpp \
        depositproductnext3.cpp \
        login.cpp \
        loginadmin.cpp \
        main.cpp \
        mainwindow.cpp \
        menu.cpp \
        newmainnew.cpp \
        register.cpp \
        typeinfo.cpp \
        user.cpp \
        viewproducts.cpp \
        viewuser.cpp \
        withdrawalproduct.cpp

HEADERS += \
        addmoney.h \
        depositproduct.h \
        depositproductnext1.h \
        depositproductnext2.h \
        depositproductnext3.h \
        login.h \
        loginadmin.h \
        mainwindow.h \
        menu.h \
        newmainnew.h \
        register.h \
        typeinfo.h \
        user.h \
        viewproducts.h \
        viewuser.h \
        withdrawalproduct.h

FORMS += \
        addmoney.ui \
        depositproduct.ui \
        depositproductnext1.ui \
        depositproductnext2.ui \
        depositproductnext3.ui \
        login.ui \
        loginadmin.ui \
        mainwindow.ui \
        menu.ui \
        newmainnew.ui \
        register.ui \
        typeinfo.ui \
        viewproducts.ui \
        viewuser.ui \
        withdrawalproduct.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src.qrc
