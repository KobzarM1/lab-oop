#ifndef SET_H
#define SET_H

#include <iostream>
#include <vector>
#include <string>

class Set {
private:
    std::vector<std::string> elements;

public:
    Set(); // Конструктор
    void addElement(const std::string& element);
    bool contains(const std::string& element) const;
    void inputElements();
    void display() const;

    Set intersection(const Set& other) const;
    Set unionSet(const Set& other) const;
    Set difference(const Set& other) const;
    Set symmetricDifference(const Set& other) const;
};

#endif // SET_H
