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
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *muha)
    {
        if (muha->objectName().isEmpty())
            muha->setObjectName("muha");
        muha->resize(1047, 795);
        centralwidget = new QWidget(muha);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(220, 520, 41, 41));
        muha->setCentralWidget(centralwidget);
        menubar = new QMenuBar(muha);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1047, 22));
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
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class muha: public Ui_muha {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUHA_H
