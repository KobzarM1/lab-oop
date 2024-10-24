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
    QLabel *fly;
    QLabel *trap;
    void moveFlyAway(const QPoint &mousePos);
    bool checkCollision();

};
#endif // MUHA_H
