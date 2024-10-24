#include <iostream>
#include "TShirt.h"
#include "Pants.h"
//#include <windows.h>

using namespace std;

int main() {
    try {

        TShirt tshirt("Nike", "M", "black", "bavovna", "circle");
        Pants pants("Levi's", "L", "bluetooth", "jeans", "lightning");


        tshirt.displayInfo();
        pants.displayInfo();

    }
    catch (const exception& e) {
        cerr << "error: " << e.what() << endl;
    }

    return 0;
}
