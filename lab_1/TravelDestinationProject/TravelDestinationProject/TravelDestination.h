#pragma once
#include <iostream>

namespace std {
    class TravelDestination {
    private:
        string name;
        string country;
        int rating;

    public:
        // Конструктор
        TravelDestination(const string& destinationName = "", const string& destinationCountry = "", int destinationRating = 0);

        void setName(const string& destinationName);
        string getName() const;

        void setCountry(const string& destinationCountry);
        string getCountry() const;

        void setRating(int destinationRating);
        int getRating() const;
    };
}
