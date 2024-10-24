#ifndef CLOTHING_H
#define CLOTHING_H

#include <string>
#include <stdexcept>

using namespace std;

class Clothing {
protected:
    string name;
    string size;
    string color;

public:
    Clothing(const string& name, const string& size, const string& color) {
        setName(name);
        setSize(size);
        this->color = color;
    }

    virtual ~Clothing() {}

    virtual void setName(const string& name) {
        if (name.empty()) {
            throw invalid_argument("no name");
        }
        this->name = name;
    }

    virtual void setSize(const string& size) {
        if (size != "S" && size != "M" && size != "L" && size != "XL") {
            throw invalid_argument("no");
        }
        this->size = size;
    }

    virtual void setColor(const string& color) {
        this->color = color;
    }

    virtual string getName() const { return name; }
    virtual string getSize() const { return size; }
    virtual string getColor() const { return color; }

    virtual void displayInfo() const = 0;
};

#endif // CLOTHING_H
