#include <iostream>
#include "Set.h"

int main() {
    Set set1, set2;

    // Введення елементів для Set 1
    std::cout << "Input elements for Set 1:" << std::endl;
    set1.inputElements();

    // Введення елементів для Set 2
    std::cout << "Input elements for Set 2:" << std::endl;
    set2.inputElements();

    std::cout << "Set 1: ";
    set1.display();

    std::cout << "Set 2: ";
    set2.display();

    std::cout << "Intersection: ";
    set1.intersection(set2).display();

    std::cout << "Union: ";
    set1.unionSet(set2).display();

    std::cout << "Difference (Set 1 - Set 2): ";
    set1.difference(set2).display();

    std::cout << "Symmetric Difference: ";
    set1.symmetricDifference(set2).display();

    return 0;
}
