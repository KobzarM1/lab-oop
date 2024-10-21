#include <iostream>
#include "Car.h"

int main() {
    // ��������� ��'��� Engine
    Engine myEngine("Gasoline", 2.5);

    // ��������� ��'��� Interior
    Interior myInterior(5, "Leather");

    // ��������� ��'��� Car (���������)
    Car myCar("Toyota", "Camry", myEngine, myInterior);

    cout << "Car Info:" << endl;
    myCar.showCarInfo();

    // ��������� ��'��� SportsCar (�������������������)
    SportsCar mySportsCar("Ferrari", "488", Engine("Gasoline", 3.9), Interior(2, "Leather"), 340);

    cout << "\nSports Car Info:" << endl;
    mySportsCar.showSportsCarInfo();

    return 0;
}
