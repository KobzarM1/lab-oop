/********************************************************************************
** Form generated from reading UI file 'instrument.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSTRUMENT_H
#define UI_INSTRUMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Instrument
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Instrument)
    {
        if (Instrument->objectName().isEmpty())
            Instrument->setObjectName("Instrument");
        Instrument->resize(800, 600);
        centralwidget = new QWidget(Instrument);
        centralwidget->setObjectName("centralwidget");
        Instrument->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Instrument);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        Instrument->setMenuBar(menubar);
        statusbar = new QStatusBar(Instrument);
        statusbar->setObjectName("statusbar");
        Instrument->setStatusBar(statusbar);

        retranslateUi(Instrument);

        QMetaObject::connectSlotsByName(Instrument);
    } // setupUi

    void retranslateUi(QMainWindow *Instrument)
    {
        Instrument->setWindowTitle(QCoreApplication::translate("Instrument", "Instrument", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Instrument: public Ui_Instrument {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTRUMENT_H
