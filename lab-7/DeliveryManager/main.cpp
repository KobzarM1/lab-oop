#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

struct Delivery {
    int id;
    string sender;
    string receiver;
    double weight;
    string type;
};

class DeliveryManager {
private:
    vector<Delivery> deliveries;
    int nextId = 1;

public:
    void addDelivery(const string& sender, const string& receiver, double weight, const string& type) {
        deliveries.push_back({nextId++, sender, receiver, weight, type});
    }

    void displayDeliveries() const {
        for (const auto& delivery : deliveries) {
            cout << "ID: " << delivery.id << ", Sender: " << delivery.sender << ", Receiver: " << delivery.receiver
                 << ", Weight: " << delivery.weight << ", Type: " << delivery.type << endl;
        }
    }

    void removeDelivery(int id) {
        deliveries.erase(remove_if(deliveries.begin(), deliveries.end(), [id](const Delivery& d) {
                             return d.id == id;
                         }), deliveries.end());
    }

    void updateDelivery(int id, double weight, const string& type) {
        for (auto& delivery : deliveries) {
            if (delivery.id == id) {
                delivery.weight = weight;
                delivery.type = type;
                break;
            }
        }
    }
};

void displayMenu() {
    cout << "1. Add Delivery" << endl;
    cout << "2. Display Deliveries" << endl;
    cout << "3. Remove Delivery" << endl;
    cout << "4. Update Delivery" << endl;
    cout << "5. Exit" << endl;
}

int main() {
    DeliveryManager manager;
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); // Очищаємо стан потоку вводу
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Видаляємо залишок буфера
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }

        switch (choice) {
        case 1: {
            string sender, receiver, type;
            double weight;

            cout << "Enter sender: ";
            cin.ignore();
            getline(cin, sender);

            cout << "Enter receiver: ";
            getline(cin, receiver);

            cout << "Enter weight: ";
            cin >> weight;

            cout << "Enter type: ";
            cin.ignore();
            getline(cin, type);

            manager.addDelivery(sender, receiver, weight, type);
            break;
        }
        case 2:
            manager.displayDeliveries();
            break;
        case 3: {
            int id;
            cout << "Enter ID to remove: ";
            cin >> id;
            manager.removeDelivery(id);
            break;
        }
        case 4: {
            int id;
            double weight;
            string type;

            cout << "Enter ID to update: ";
            cin >> id;

            cout << "Enter new weight: ";
            cin >> weight;

            cout << "Enter new type: ";
            cin.ignore();
            getline(cin, type);

            manager.updateDelivery(id, weight, type);
            break;
        }
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
