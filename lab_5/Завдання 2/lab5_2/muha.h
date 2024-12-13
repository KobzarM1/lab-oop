#ifndef MUHA_H
#define MUHA_H

#include <QMainWindow>
#include <QEvent>
#include <QMouseEvent>
#include <QLabel>

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
    QLabel *fly = nullptr;
    QLabel *trap = nullptr;
    QLabel *window = nullptr;
    QLabel *levelLabel = nullptr;
    int level;
    void moveFlyAway(const QPoint &mousePos);
    void moveFlyToWindow();
    bool checkCollision();
    bool checkWindowCollision();
    void setupLevel(int lvl);
    void updateLevelLabel();
    void randomizeTrapAndWindow(); // Нова функція для випадкової зміни положення
};
#endif // MUHA_H
