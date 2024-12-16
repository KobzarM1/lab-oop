/********************************************************************************
** Form generated from reading UI file 'muha.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUHA_H
#define UI_MUHA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_muha
{
public:
    QWidget *centralwidget;
    QLabel *trap;
    QLabel *window;
    QLabel *muha2;
    QLabel *muha1;
    QLabel *jaba;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *muha)
    {
        if (muha->objectName().isEmpty())
            muha->setObjectName("muha");
        muha->resize(873, 672);
        centralwidget = new QWidget(muha);
        centralwidget->setObjectName("centralwidget");
        trap = new QLabel(centralwidget);
        trap->setObjectName("trap");
        trap->setGeometry(QRect(80, 40, 101, 91));
        trap->setPixmap(QPixmap(QString::fromUtf8("trap.png")));
        trap->setScaledContents(true);
        window = new QLabel(centralwidget);
        window->setObjectName("window");
        window->setGeometry(QRect(570, 110, 111, 101));
        window->setPixmap(QPixmap(QString::fromUtf8("window.png")));
        window->setScaledContents(true);
        muha2 = new QLabel(centralwidget);
        muha2->setObjectName("muha2");
        muha2->setGeometry(QRect(410, 440, 81, 61));
        muha2->setPixmap(QPixmap(QString::fromUtf8("muha1.png")));
        muha2->setScaledContents(true);
        muha1 = new QLabel(centralwidget);
        muha1->setObjectName("muha1");
        muha1->setGeometry(QRect(130, 400, 91, 71));
        muha1->setPixmap(QPixmap(QString::fromUtf8("muha2.png")));
        muha1->setScaledContents(true);
        jaba = new QLabel(centralwidget);
        jaba->setObjectName("jaba");
        jaba->setGeometry(QRect(300, 290, 121, 91));
        jaba->setPixmap(QPixmap(QString::fromUtf8("frog.png")));
        jaba->setScaledContents(true);
        muha->setCentralWidget(centralwidget);
        window->raise();
        muha2->raise();
        trap->raise();
        muha1->raise();
        jaba->raise();
        menubar = new QMenuBar(muha);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 873, 21));
        muha->setMenuBar(menubar);
        statusbar = new QStatusBar(muha);
        statusbar->setObjectName("statusbar");
        muha->setStatusBar(statusbar);

        retranslateUi(muha);

        QMetaObject::connectSlotsByName(muha);
    } // setupUi

    void retranslateUi(QMainWindow *muha)
    {
        muha->setWindowTitle(QCoreApplication::translate("muha", "muha", nullptr));
        trap->setText(QString());
        window->setText(QString());
        muha2->setText(QString());
        muha1->setText(QString());
        jaba->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class muha: public Ui_muha {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUHA_H
