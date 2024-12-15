#ifndef MUSICSTORE_H
#define MUSICSTORE_H

#include <vector>
#include <algorithm>
#include <QString>
#include "instrument.h"

template <typename T>
class MusicStore {
private:
    std::vector<T> instruments;

public:
    void addInstrument(const T& instrument);
    void removeInstrument(const QString& name);
    void listInstruments() const;
    std::vector<T> findInstrumentsByType(const QString& type) const;
};

template <typename T>
void MusicStore<T>::addInstrument(const T& instrument) {
    instruments.push_back(instrument);
}

template <typename T>
void MusicStore<T>::removeInstrument(const QString& name) {
    instruments.erase(std::remove_if(instruments.begin(), instruments.end(),
                                     [&name](const T& instrument) { return instrument.getName() == name; }),
                      instruments.end());
}

template <typename T>
void MusicStore<T>::listInstruments() const {
    for (const auto& instrument : instruments) {
        // Виведення може бути реалізоване через GUI
    }
}

template <typename T>
std::vector<T> MusicStore<T>::findInstrumentsByType(const QString& type) const {
    std::vector<T> result;
    for (const auto& instrument : instruments) {
        if (instrument.getType() == type) {
            result.push_back(instrument);
        }
    }
    return result;
}

#endif // MUSICSTORE_H
