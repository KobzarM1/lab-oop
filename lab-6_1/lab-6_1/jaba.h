#ifndef JABA_H
#define JABA_H

#include <QLabel>
#include <QPoint>

class Jaba : public QLabel
{
    Q_OBJECT

public:
    explicit Jaba(QWidget *parent = nullptr);
    ~Jaba();

    void setupFrog();
    void moveTowards(const QPoint &flyPos);

private:
    int speed;
};

#endif // JABA_H
