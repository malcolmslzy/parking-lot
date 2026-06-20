#include "parking.h"
#include <iostream>
#include <limits>
using namespace std;

int main() {
    initializeLot();
    int choice;

    do{
        cout << "\n===Parking System===\n";
        cout << "1. Add Car\n";
        cout << "2. Display Lot\n";
        cout << "3. Search car\n";
        cout << "4. Check slot\n";
        cout << "5. Display report\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1: addCar(); break;
            case 2: displayLot(); break;
            case 3: searchByCar(...); break;
            case 4: checkSlot(...); break;
            case 5: displayReport(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    }while (choice !=3);

    return 0;
}
