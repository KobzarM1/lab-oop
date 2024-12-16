#include "muha.h"
#include "ui_muha.h"
#include <QPixmap>
#include <QDebug>
#include <QRandomGenerator>
#include <QMessageBox>
#include <QMouseEvent>
#include <QPoint>

muha::muha(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::muha), level(1), score(0)
{
    ui->setupUi(this);

    // Встановлення QLabel з фоном
    background = new QLabel(this);
    background->setPixmap(QPixmap("C:/Users/kobza/OneDrive/Рабочий стол/PROJECT_KNTU/OOP_lab/lab-6/lab-6_1/lab-6_1/room.jpg"));
    background->setScaledContents(true);
    background->setGeometry(0, 0, this->width(), this->height());
    background->show();

    // Лічильник рівнів
    levelLabel = new QLabel(this);
    levelLabel->setGeometry(10, 10, 150, 30);
    updateLevelLabel();

    // Установка рівня
    setupLevel(level);
}

muha::~muha()
{
    delete ui;
}

void muha::setupLevel(int lvl)
{
    // Оновлення рівня
    level = lvl;
    updateLevelLabel();

    // Перевірка чи гра досягла рівня 3
    if (level > 3) {
        QMessageBox::information(this, "Ви перемогли!", "Ви досягли 3 рівня і виграли гру!");
        qApp->quit();
        return;
    }

    // Видаляємо старі елементи (якщо вони існують)
    if (fly1) fly1->deleteLater();
    if (fly2) fly2->deleteLater();
    if (trap) trap->deleteLater();
    if (window) window->deleteLater();
    if (frog) frog->deleteLater();

    // Додаємо муху на рівні 1
    fly1 = new QLabel(this);
    fly1->setPixmap(QPixmap("C:/Users/kobza/OneDrive/Рабочий стол/PROJECT_KNTU/OOP_lab/lab-6/lab-6_1/lab-6_1/muha1.png"));
    fly1->setScaledContents(true);
    fly1->setGeometry(QRandomGenerator::global()->bounded(this->width() - 50), QRandomGenerator::global()->bounded(this->height() - 50), 50, 50);
    fly1->show();

    // Додаємо другу муху на рівні 2
    if (level >= 2) {
        fly2 = new QLabel(this);
        fly2->setPixmap(QPixmap("C:/Users/kobza/OneDrive/Рабочий стол/PROJECT_KNTU/OOP_lab/lab-6/lab-6_1/lab-6_1/muha2.png"));
        fly2->setScaledContents(true);
        fly2->setGeometry(QRandomGenerator::global()->bounded(this->width() - 50), QRandomGenerator::global()->bounded(this->height() - 50), 50, 50);
        fly2->show();
    }

    // Додаємо пастку
    trap = new QLabel(this);
    trap->setPixmap(QPixmap("C:/Users/kobza/OneDrive/Рабочий стол/PROJECT_KNTU/OOP_lab/lab-6/lab-6_1/lab-6_1/trap.png"));
    trap->setScaledContents(true);
    trap->setGeometry(QRandomGenerator::global()->bounded(this->width() - 100), QRandomGenerator::global()->bounded(this->height() - 100), 100, 100);
    trap->show();

    // Додаємо вікно на рівні 2 і вище
    if (level >= 2) {
        window = new QLabel(this);
        window->setPixmap(QPixmap("C:/Users/kobza/OneDrive/Рабочий стол/PROJECT_KNTU/OOP_lab/lab-6/lab-6_1/lab-6_1/window.png"));
        window->setScaledContents(true);
        window->setGeometry(QRandomGenerator::global()->bounded(this->width() - 100), QRandomGenerator::global()->bounded(this->height() - 100), 100, 100);
        window->show();
    }

    // Додаємо жабу на рівні 3
    if (level == 3) {
        QMessageBox::information(this, "Подія", "Через відкриті двері запригнула жаба. Вікно зачиняється, пастка знищується.");

        frog = new Jaba(this);
        frog->setupFrog();

        if (window) {
            window->deleteLater(); // Видаляємо вікно
            window = nullptr;
        }

        if (trap) {
            trap->deleteLater(); // Видаляємо пастку
            trap = nullptr;
        }

        // Прискорюємо муху
        fly1->setGeometry(QRandomGenerator::global()->bounded(this->width() - 50), QRandomGenerator::global()->bounded(this->height() - 50), 30, 30);
    }
}

void muha::updateLevelLabel()
{
    levelLabel->setText("Level: " + QString::number(level) + " Score: " + QString::number(score));
}

bool muha::event(QEvent *e)
{
    if (e->type() == QEvent::MouseMove) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(e);
        moveFlyAway(mouseEvent->pos(), fly1);

        if (fly2) {
            moveFlyAway(mouseEvent->pos(), fly2);
        }

        if (checkCollision(fly1, trap) || (fly2 && checkCollision(fly2, trap))) {
            QMessageBox::information(this, "Win", "Піймався");
            if (fly1 && checkCollision(fly1, trap)) {
                fly1->deleteLater();
                fly1 = nullptr;
            }
            if (fly2 && checkCollision(fly2, trap)) {
                fly2->deleteLater();
                fly2 = nullptr;
            }
            score++;
            level++;
            setupLevel(level);
        } else if (checkCollision(fly1, window) || (fly2 && checkCollision(fly2, window))) {
            QMessageBox::information(this, "Loss", "Муха втекла через вікно");
            if (fly1 && checkCollision(fly1, window)) {
                fly1->deleteLater();
                fly1 = nullptr;
            }
            if (fly2 && checkCollision(fly2, window)) {
                fly2->deleteLater();
                fly2 = nullptr;
            }
            level++;
            setupLevel(level);
        } else if (level == 3 && (checkCollision(fly1, frog) || (fly2 && checkCollision(fly2, frog)))) {
            QMessageBox::information(this, "Win", "Ви виграли! Муха спіймана жабою!");
            qApp->quit();
        }
    }

    return QMainWindow::event(e);
}

void muha::moveFlyAway(const QPoint &mousePos, QLabel *fly)
{
    if (!fly) {
        qDebug() << "Fly label is null!";
        return;
    }

    int flyX = fly->x();
    int flyY = fly->y();
    int deltaX = flyX - mousePos.x();
    int deltaY = flyY - mousePos.y();

    int newX = flyX;
    int newY = flyY;

    if (qAbs(deltaX) < 50 && qAbs(deltaY) < 50) {
        newX = flyX + (deltaX > 0 ? 1 : -1);
        newY = flyY + (deltaY > 0 ? 1 : -1);
    } else if (level >= 2) {
        int windowX = window->x();
        int windowY = window->y();
        if (flyX < windowX)
            newX = flyX + 1;
        else if (flyX > windowX)
            newX = flyX - 1;
        if (flyY < windowY)
            newY = flyY + 1;
        else if (flyY > windowY)
            newY = flyY - 1;
    }

    newX = qBound(0, newX, this->width() - fly->width());
    newY = qBound(0, newY, this->height() - fly->height());

    qDebug() << "New fly position:" << newX << newY;
    fly->move(newX, newY);

    // Рух жаби за мухою на 3 рівні
    if (level == 3 && frog) {
        frog->moveTowards(fly->pos());
    }
}

bool muha::checkCollision(QLabel *fly, QLabel *other)
{
    if (!fly || !other) {
        qDebug() << "Fly or other label is null!";
        return false;
    }

    QRect flyRect = fly->geometry();
    QRect otherRect = other->geometry();
    bool collided = flyRect.intersects(otherRect);
    qDebug() << "Checking collision:" << collided;
    return collided;
}
