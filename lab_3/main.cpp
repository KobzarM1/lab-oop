#include <iostream>
#include "Car.h"

int main() {
    // Створюємо об'єкт Engine
    Engine myEngine("Gasoline", 2.5);

    // Створюємо об'єкт Interior
    Interior myInterior(5, "Leather");

    // Створюємо об'єкт Car (Автомобіль)
    Car myCar("Toyota", "Camry", myEngine, myInterior);

    cout << "Car Info:" << endl;
    myCar.showCarInfo();

    // Створюємо об'єкт SportsCar (СпортивнийАвтомобіль)
    SportsCar mySportsCar("Ferrari", "488", Engine("Gasoline", 3.9), Interior(2, "Leather"), 340);

    cout << "\nSports Car Info:" << endl;
    mySportsCar.showSportsCarInfo();

    return 0;
}
