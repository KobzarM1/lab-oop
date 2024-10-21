#include <iostream>
#include "TravelDestination.h"

using namespace std;

int main() {
    TravelDestination destination("Kyiv", "Ukraine", 4);

    cout << "Destination: " << destination.getName() << endl;
    cout << "Country: " << destination.getCountry() << endl;
    cout << "Rating: " << destination.getRating() << endl;

    // Оновимо рейтинг
    destination.setRating(10);

    cout << "\nUpdated Rating: " << destination.getRating() << endl;

    return 0;
}
