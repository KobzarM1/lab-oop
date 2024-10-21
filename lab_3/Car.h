#pragma once
#include <iostream>
using namespace std;

// ���� Engine (������)
class Engine {
private:
    string engineType;
    double engineVolume;

public:
    // �����������
    Engine(const string& type = "Unknown", double volume = 0.0)
        : engineType(type), engineVolume(volume) {}

    void setEngineType(const string& type) {
        engineType = type;
    }

    string getEngineType() const {
        return engineType;
    }

    void setEngineVolume(double volume) {
        engineVolume = volume;
    }

    double getEngineVolume() const {
        return engineVolume;
    }

    void showEngineInfo() const {
        cout << "Engine Type: " << engineType << "\nEngine Volume: " << engineVolume << "L" << endl;
    }
};

// ���� Interior (�����)
class Interior {
private:
    int seatCount;
    string interiorType;

public:
    // �����������
    Interior(int seats = 0, const string& type = "Unknown")
        : seatCount(seats), interiorType(type) {}

    void setSeatCount(int seats) {
        seatCount = seats;
    }

    int getSeatCount() const {
        return seatCount;
    }

    void setInteriorType(const string& type) {
        interiorType = type;
    }

    string getInteriorType() const {
        return interiorType;
    }

    void showInteriorInfo() const {
        cout << "Seat Count: " << seatCount << "\nInterior Type: " << interiorType << endl;
    }
};

// ���� Car (���������)
class Car {
private:
    string brand;
    string model;
    Engine engine;      // ����������: ���� Engine
    Interior interior;  // ����������: ���� Interior

public:
    // �����������
    Car(const string& carBrand = "Unknown", const string& carModel = "Unknown",
        const Engine& carEngine = Engine(), const Interior& carInterior = Interior())
        : brand(carBrand), model(carModel), engine(carEngine), interior(carInterior) {}

    void setBrand(const string& carBrand) {
        brand = carBrand;
    }

    string getBrand() const {
        return brand;
    }

    void setModel(const string& carModel) {
        model = carModel;
    }

    string getModel() const {
        return model;
    }

    void showCarInfo() const {
        cout << "Brand: " << brand << "\nModel: " << model << endl;
        engine.showEngineInfo();
        interior.showInteriorInfo();
    }
};

// �������� ���� SportsCar (�������������������)
class SportsCar : public Car {
private:
    double maxSpeed; // ��������� ����

public:
    // �����������
    SportsCar(const string& carBrand, const string& carModel, const Engine& carEngine,
        const Interior& carInterior, double speed)
        : Car(carBrand, carModel, carEngine, carInterior), maxSpeed(speed) {}

    void setMaxSpeed(double speed) {
        maxSpeed = speed;
    }

    double getMaxSpeed() const {
        return maxSpeed;
    }

    void showSportsCarInfo() const {
        showCarInfo();
        cout << "Max Speed: " << maxSpeed << " km/h" << endl;
    }
};
