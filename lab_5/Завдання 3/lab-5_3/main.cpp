#include <iostream>
#include "rectangle.h"

int main() {
    try {
        Rectangle rect1(10, 20);
        Rectangle rect2(15, 25);

        Rectangle rect3 = rect1 + rect2;
        std::cout << "rect1 + rect2 = " << rect3 << std::endl;

        Rectangle rect4 = rect1 - rect2;
        std::cout << "rect1 - rect2 = " << rect4 << std::endl;

        Rectangle rect5 = rect1 * 2;
        std::cout << "rect1 * 2 = " << rect5 << std::endl;

        Rectangle rect6 = rect2 / 2;
        std::cout << "rect2 / 2 = " << rect6 << std::endl;

        bool isEqual = rect1 == rect2;
        std::cout << "rect1 == rect2: " << (isEqual ? "true" : "false") << std::endl;

        bool isNotEqual = rect1 != rect2;
        std::cout << "rect1 != rect2: " << (isNotEqual ? "true" : "false") << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
