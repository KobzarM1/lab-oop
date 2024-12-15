#include "instrument.h"

// Реалізація методів класу Instrument
Instrument::Instrument(QString n, QString t, double p) : name(n), type(t), price(p) {}

QString Instrument::getName() const { return name; }
QString Instrument::getType() const { return type; }
double Instrument::getPrice() const { return price; }

void Instrument::setName(const QString& n) { name = n; }
void Instrument::setType(const QString& t) { type = t; }
void Instrument::setPrice(double p) { price = p; }
