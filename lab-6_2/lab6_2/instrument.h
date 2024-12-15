#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <QString>

class Instrument {
private:
    QString name;
    QString type;
    double price;

public:
    Instrument(QString n, QString t, double p);

    QString getName() const;
    QString getType() const;
    double getPrice() const;

    void setName(const QString& n);
    void setType(const QString& t);
    void setPrice(double p);
};

#endif // INSTRUMENT_H
