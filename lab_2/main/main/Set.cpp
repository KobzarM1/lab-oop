#include "Set.h"

Set::Set() {}

void Set::addElement(const std::string& element) {
    if (!contains(element)) {
        elements.push_back(element);
    }
}

bool Set::contains(const std::string& element) const {
    for (const auto& elem : elements) {
        if (elem == element) {
            return true;
        }
    }
    return false;
}

void Set::inputElements() {
    std::string input;
    while (true) {
        std::getline(std::cin, input);
        if (input == "done") break;
        addElement(input);
    }
}

void Set::display() const {
    for (const auto& elem : elements) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

Set Set::intersection(const Set& other) const {
    Set result;
    for (const auto& elem : elements) {
        if (other.contains(elem)) {
            result.addElement(elem);
        }
    }
    return result; // Повертаємо результат
}

Set Set::unionSet(const Set& other) const {
    Set result;
    for (const auto& elem : elements) {
        result.addElement(elem); // Додаємо елементи з поточної множини
    }
    for (const auto& elem : other.elements) {
        result.addElement(elem); // Додаємо елементи з іншої множини
    }
    return result; // Повертаємо результат
}

Set Set::difference(const Set& other) const {
    Set result;
    for (const auto& elem : elements) {
        if (!other.contains(elem)) {
            result.addElement(elem);
        }
    }
    return result; // Повертаємо результат
}

Set Set::symmetricDifference(const Set& other) const {
    Set result = this->unionSet(other).difference(this->intersection(other)); // Використовуємо вже реалізовані методи
    return result; // Повертаємо результат
}
