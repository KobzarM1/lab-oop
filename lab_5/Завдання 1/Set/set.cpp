#include "Set.h"

Set::Set() {}

Set Set::operator+(const Set& other) const {
    return this->unionSet(other);
}

Set Set::operator-(const Set& other) const {
    return this->difference(other);
}

Set Set::operator*(const Set& other) const {
    return this->intersection(other);
}

Set Set::operator^(const Set& other) const {
    return this->symmetricDifference(other);
}

bool Set::operator==(const Set& other) const {
    if (elements.size() != other.elements.size()) {
        return false;
    }
    for (const auto& elem : elements) {
        if (!other.contains(elem)) {
            return false;
        }
    }
    return true;
}

bool Set::operator!=(const Set& other) const {
    return !(*this == other);
}


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
    return result;
}

Set Set::unionSet(const Set& other) const {
    Set result;
    for (const auto& elem : elements) {
        result.addElement(elem);
    }
    for (const auto& elem : other.elements) {
        result.addElement(elem);
    }
    return result;
}

Set Set::difference(const Set& other) const {
    Set result;
    for (const auto& elem : elements) {
        if (!other.contains(elem)) {
            result.addElement(elem);
        }
    }
    return result;
}

Set Set::symmetricDifference(const Set& other) const {
    Set result = this->unionSet(other).difference(this->intersection(other));
    return result;
}
