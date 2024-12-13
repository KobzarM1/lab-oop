#include <iostream>
#include "Set.h"

using namespace std;

int main() {
    Set set1, set2;
    set1.addElement("apple");
    set1.addElement("banana");
    set1.addElement("cherry");

    set2.addElement("banana");
    set2.addElement("dragonfruit");
    set2.addElement("elderberry");

    // Перевірка операцій
    Set unionSet = set1 + set2;
    Set intersectionSet = set1 * set2;
    Set differenceSet = set1 - set2;
    Set symDifferenceSet = set1 ^ set2;

    cout << "Set 1: ";
    set1.display();
    cout << "Set 2: ";
    set2.display();

    cout << "Union: ";
    unionSet.display();
    cout << "Intersection: ";
    intersectionSet.display();
    cout << "Difference (Set 1 - Set 2): ";
    differenceSet.display();
    cout << "Symmetric Difference: ";
    symDifferenceSet.display();

    bool areEqual = (set1 == set2);
    cout << "Are Set 1 and Set 2 equal? " << (areEqual ? "Yes" : "No") << endl;

    bool areNotEqual = (set1 != set2);
    cout << "Are Set 1 and Set 2 not equal? " << (areNotEqual ? "Yes" : "No") << endl;

    return 0;
}
