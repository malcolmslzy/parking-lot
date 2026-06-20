#include "parking.h"
#include <iostream>
#include <limits>
using namespace std;

Car lot[MAX_SLOTS];
int carCount = 0;

void initializeLot(){
    for (int i=0; i < MAX_SLOTS; i++){
        lot[i].slot = i + 1;
        lot[i].occupied = false;
        lot[i].plate = "";
    }
}

bool isFull (){
    return carCount >= MAX_SLOTS;
}

void addCar(){
    if (isFull()){
        cout << "Parking lot is full.\n";
        return;
    }

    string plate;
    string entryDate;
    string entryTime;
    cout << "Enter car plate number: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline (cin, plate); 

    if (plate.empty()) {
        cout << "Plate number cannot be empty.\n";
        return;
    }

    for (int i = 0; i < MAX_SLOTS; i++){
        if (lot[i].occupied && lot[i].plate == plate) {
            cout << "This car is already parked.\n";
            return;
        }
    }

      cout << "Enter entry date (DD/MM/YYYY): ";
      cin >> entryDate;
      cout << "Enter entry time (HH:MM): ";
      cin >> entryTime;

    for (int i = 0; i < MAX_SLOTS; i++){
        if (!lot[i].occupied){
            lot[i].plate = plate;
            lot[i].occupied = true;
            lot[i].entryDate = entryDate;
            lot[i].entryTime = entryTime;
            carCount++;
            cout << "Car " << plate << " parked at slot " << lot[i].slot << ".\n";
            return;
        }
    }
}

void displayLot(){
    cout << "Parking Lot Status\n";
    for (int i = 0; i < MAX_SLOTS; i++){
        cout << "Slot " << lot[i].slot << ": ";
        if (lot[i].occupied)
            cout << lot[i].plate;
        else
            cout << "Empty";
        cout << endl;
    }
}
