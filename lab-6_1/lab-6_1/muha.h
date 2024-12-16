#ifndef MUHA_H
#define MUHA_H

#include <QMainWindow>
#include <QEvent>
#include <QMouseEvent>
#include <QLabel>
#include "jaba.h" // Додаємо включення для класу Jaba

QT_BEGIN_NAMESPACE
namespace Ui {
class muha;
}
QT_END_NAMESPACE

class muha : public QMainWindow
{
    Q_OBJECT

public:
    muha(QWidget *parent = nullptr);
    ~muha();

protected:
    bool event(QEvent *e) override;

private:
    Ui::muha *ui;
    QLabel *fly1 = nullptr;
    QLabel *fly2 = nullptr;
    QLabel *trap = nullptr;
    QLabel *window = nullptr;
    Jaba *frog = nullptr; // Використовуємо клас Jaba
    QLabel *background = nullptr; // Додаємо фон
    QLabel *levelLabel = nullptr;
    int level;
    int score; // Додаємо змінну score
    void moveFlyAway(const QPoint &mousePos, QLabel *fly);
    bool checkCollision(QLabel *fly, QLabel *other);
    void setupLevel(int lvl);
    void updateLevelLabel();
};

#endif // MUHA_H
