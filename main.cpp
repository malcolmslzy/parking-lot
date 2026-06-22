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
        cout << "5. Remove Car\n";
        cout << "6. Display Capacity Status\n"; 
        cout << "7. Exit\n";
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
           
            case 3: {
             string searchPlate;
             cout << "Enter plate to search: ";
             cin >> searchPlate;
             searchByCar(searchPlate);
             break;
         }
            case 4: {
             int slotNumber;
             cout << "Enter slot number: ";
             cin >> slotNumber;
             checkSlot(slotNumber);
             break;
         }
            case 5: removeCar(); break;
            case 6: displayCapacityStatus(); break; 
            case 7: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    }while (choice !=7);

    return 0;
}
