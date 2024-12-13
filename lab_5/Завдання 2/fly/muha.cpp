#include "muha.h"
#include "ui_muha.h"
#include <QPixmap>
#include <QDebug>
#include <QRandomGenerator>
#include <QMessageBox>

muha::muha(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::muha)
{
    ui->setupUi(this);


    fly = new QLabel(this);
    QPixmap pix;
    pix.load("C://Users/kobza/OneDrive/Рабочий стол/PROJECT_KNTU/OOP_lab/lab_4/fly/muha.png");
    fly->setPixmap(pix);
    fly->setScaledContents(true);
    fly->setGeometry(50, 50, 50, 50);


    trap = new QLabel(this);
    QPixmap trapPix;
    trapPix.load("C://Users/kobza/OneDrive/Рабочий стол/PROJECT_KNTU/OOP_lab/lab_4/fly/trap.png"); // Шлях до зображення пастки
    trap->setPixmap(trapPix);
    trap->setScaledContents(true);
    trap->setGeometry(300, 300, 100, 100);
}

muha::~muha()
{
    delete ui;
}

bool muha::event(QEvent *e)
{
    if (e->type() == QEvent::MouseMove) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(e);
        moveFlyAway(mouseEvent->pos());

        if (checkCollision()) {
            QMessageBox::information(this, "Win", "піймався");
            close();
        }
    }

    return QMainWindow::event(e);
}

void muha::moveFlyAway(const QPoint &mousePos)
{
    int flyX = fly->x();
    int flyY = fly->y();

    if (qAbs(mousePos.x() - flyX) < 100 && qAbs(mousePos.y() - flyY) < 100) {
        int newX = QRandomGenerator::global()->bounded(this->width() - fly->width());
        int newY = QRandomGenerator::global()->bounded(this->height() - fly->height());
        fly->move(newX, newY);
    }
}

bool muha::checkCollision()
{
    QRect flyRect = fly->geometry();
    QRect trapRect = trap->geometry();
    return flyRect.intersects(trapRect);
}
