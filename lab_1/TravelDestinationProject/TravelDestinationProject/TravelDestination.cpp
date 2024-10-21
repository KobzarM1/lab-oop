#include "TravelDestination.h"

using namespace std;

// Ініціалізація конструктора
TravelDestination::TravelDestination(const string& destinationName, const string& destinationCountry, int destinationRating)
    : name(destinationName), country(destinationCountry), rating(destinationRating) {}

void TravelDestination::setName(const string& destinationName) {
    name = destinationName;
}

string TravelDestination::getName() const {
    return name;
}

void TravelDestination::setCountry(const string& destinationCountry) {
    country = destinationCountry;
}

string TravelDestination::getCountry() const {
    return country;
}

void TravelDestination::setRating(int destinationRating) {
    rating = destinationRating;
}

int TravelDestination::getRating() const {
    return rating;
}
