#include "muha.h"
#include "ui_muha.h"
#include <QPixmap>
#include <QDebug>
#include <QRandomGenerator>
#include <QMessageBox>

muha::muha(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::muha), level(1)
{
    ui->setupUi(this);
    qDebug() << "Constructor called";
    setupLevel(level);
}

muha::~muha()
{
    qDebug() << "Destructor called";
    delete ui;
}

bool muha::event(QEvent *e)
{
    if (e->type() == QEvent::MouseMove) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(e);
        qDebug() << "Mouse move event at position:" << mouseEvent->pos();
        moveFlyAway(mouseEvent->pos());

        if (checkCollision()) {
            QMessageBox::information(this, "Win", "піймався");
            level++;
            if (level > 10) level = 1; // Повторне встановлення рівня на 1 після 10
            setupLevel(level);
        } else if (level >= 2 && checkWindowCollision()) {
            QMessageBox::information(this, "Loss", "муха втекла через вікно");
            qApp->quit(); // Закриття гри після програшу
        }
    }

    return QMainWindow::event(e);
}

void muha::moveFlyAway(const QPoint &mousePos)
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
        // Додаємо логіку для руху мухи до вікна
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
}

bool muha::checkCollision()
{
    if (!fly || !trap) {
        qDebug() << "Fly or trap label is null!";
        return false;
    }

    QRect flyRect = fly->geometry();
    QRect trapRect = trap->geometry();
    bool collided = flyRect.intersects(trapRect);
    qDebug() << "Checking collision:" << collided;
    return collided;
}

bool muha::checkWindowCollision()
{
    if (!fly || !window) {
        qDebug() << "Fly or window label is null!";
        return false;
    }

    QRect flyRect = fly->geometry();
    QRect windowRect = window->geometry();
    bool collided = flyRect.intersects(windowRect);
    qDebug() << "Checking window collision:" << collided;
    return collided;
}

void muha::setupLevel(int lvl)
{
    qDebug() << "Setting up level:" << lvl;
    level = lvl;

    if (fly) fly->deleteLater();
    if (trap) trap->deleteLater();
    if (window) window->deleteLater();

    fly = new QLabel(this);
    if (!fly) {
        qDebug() << "Failed to create fly label!";
        return;
    }

    QPixmap pix;
    if (!pix.load("C://Users/kobza/OneDrive/Рабочий стол/PROJECT_KNTU/OOP_lab/lab_5/Завдання 2/lab5_2/muha.png")) {
        qDebug() << "Failed to load muha.png";
        return;
    }
    fly->setPixmap(pix);
    fly->setScaledContents(true);
    fly->setGeometry(50, 50, 50, 50);
    fly->show();

    trap = new QLabel(this);
    if (!trap) {
        qDebug() << "Failed to create trap label!";
        return;
    }

    QPixmap trapPix;
    if (!trapPix.load("C://Users/kobza/OneDrive/Рабочий стол/PROJECT_KNTU/OOP_lab/lab_5/Завдання 2/lab5_2/trap.png")) {
        qDebug() << "Failed to load trap.png";
        return;
    }
    trap->setPixmap(trapPix);
    trap->setScaledContents(true);
    trap->setGeometry(300, 300, 100, 100);
    trap->show();

    if (level >= 2) {
        window = new QLabel(this);
        if (!window) {
            qDebug() << "Failed to create window label!";
            return;
        }

        QPixmap windowPix;
        if (!windowPix.load("C://Users/kobza/OneDrive/Рабочий стол/PROJECT_KNTU/OOP_lab/lab_5/Завдання 2/lab5_2/window.png")) {
            qDebug() << "Failed to load window.png";
            return;
        }
        window->setPixmap(windowPix);
        window->setScaledContents(true);
        window->setGeometry(500, 50, 100, 100);
        window->show();
    }

    randomizeTrapAndWindow(); // Випадкова зміна положення капкана і вікна

    if (!levelLabel) {
        levelLabel = new QLabel(this);
        levelLabel->setGeometry(10, 10, 100, 30);
    }

    updateLevelLabel();
    qDebug() << "Level setup complete.";
}

void muha::randomizeTrapAndWindow()
{
    int newX, newY;

    // Випадкове положення для капкана
    newX = QRandomGenerator::global()->bounded(this->width() - trap->width());
    newY = QRandomGenerator::global()->bounded(this->height() - trap->height());
    trap->move(newX, newY);
    qDebug() << "Trap moved to:" << newX << newY;

    // Випадкове положення для вікна
    if (window) {
        newX = QRandomGenerator::global()->bounded(this->width() - window->width());
        newY = QRandomGenerator::global()->bounded(this->height() - window->height());
        window->move(newX, newY);
        qDebug() << "Window moved to:" << newX << newY;
    }
}

void muha::updateLevelLabel()
{
    levelLabel->setText("Level: " + QString::number(level));
    qDebug() << "Level label updated to:" << level;
}
