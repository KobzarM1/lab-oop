#include "jaba.h"
#include <QRandomGenerator>
#include <QPixmap>

Jaba::Jaba(QWidget *parent)
    : QLabel(parent), speed(1)
{
    setupFrog();
}

Jaba::~Jaba()
{
}

void Jaba::setupFrog()
{
    this->setPixmap(QPixmap("C:/Users/kobza/OneDrive/Рабочий стол/PROJECT_KNTU/OOP_lab/lab-6/lab-6_1/lab-6_1/frog.png"));
    this->setScaledContents(true);
    this->setGeometry(QRandomGenerator::global()->bounded(this->parentWidget()->width() - 100), QRandomGenerator::global()->bounded(this->parentWidget()->height() - 100), 100, 100);
    this->show();
}

void Jaba::moveTowards(const QPoint &flyPos)
{
    int frogX = this->x();
    int frogY = this->y();
    int deltaX = flyPos.x() - frogX;
    int deltaY = flyPos.y() - frogY;

    int newX = frogX;
    int newY = frogY;

    if (qAbs(deltaX) > speed) {
        newX += (deltaX > 0 ? speed : -speed);
    }

    if (qAbs(deltaY) > speed) {
        newY += (deltaY > 0 ? speed : -speed);
    }

    this->move(newX, newY);
}
