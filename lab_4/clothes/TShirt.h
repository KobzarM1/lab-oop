#ifndef TSHIRT_H
#define TSHIRT_H

#include "Clothing.h"
#include <iostream>

using namespace std;

class TShirt : public Clothing {
private:
    string material;
    string collarType;
public:
    TShirt(const string& name, const string& size, const string& color, const string& material, const string& collarType)
        : Clothing(name, size, color), material(material), collarType(collarType) {}

    void setMaterial(const string& material) {
        this->material = material;
    }

    void setCollarType(const string& collarType) {
        this->collarType = collarType;
    }

    string getMaterial() const { return material; }
    string getCollarType() const { return collarType; }

    void displayInfo() const override {
        cout << "TShirt: " << getName() << ", Size: " << getSize()
        << ", Color: " << getColor() << ", Material: " << material
        << ", Collar type: " << collarType << endl;
    }
};

#endif // TSHIRT_H
