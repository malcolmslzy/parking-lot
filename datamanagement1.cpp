#include "parking.h"
#include <iostream>
#include <limits>
#include <ctime>
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

       time_t now = time(0);
           tm* localTime = localtime(&now);

        entryDate = to_string(localTime->tm_mday) + "/" +
            to_string(localTime->tm_mon + 1) + "/" +
            to_string(localTime->tm_year + 1900);

        entryTime = to_string(localTime->tm_hour) + ":" +
            to_string(localTime->tm_min);

    if (isFull()){
        cout << "Parking lot is full. Adding " << plate << " to waiting queue.\n";
        enqueue(waitingQueue, plate, entryDate, entryTime);
        return;
        }

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
