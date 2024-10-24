#ifndef PANTS_H
#define PANTS_H

#include "Clothing.h"
#include <iostream>

using namespace std;

class Pants : public Clothing {
private:
    string material;
    string fasteningType;

public:
    Pants(const string& name, const string& size, const string& color, const string& material, const string& fasteningType)
        : Clothing(name, size, color), material(material), fasteningType(fasteningType) {}

    void setMaterial(const string& material) {
        this->material = material;
    }

    void setFasteningType(const string& fasteningType) {
        this->fasteningType = fasteningType;
    }

    string getMaterial() const { return material; }
    string getFasteningType() const { return fasteningType; }

    void displayInfo() const override {
        cout << "pants: " << getName() << ", Size: " << getSize()
            << ", coor: " << getColor() << ", Material: " << material
            << ", Fastener type: " << fasteningType << std::endl;
    }
};

#endif // PANTS_H
