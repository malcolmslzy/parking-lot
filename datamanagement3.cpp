#include "parking.h"
#include <iostream>

using namespace std;

bool checkCapacity() {
    if (carCount >= MAX_SLOTS) {
        return false; 
    }
    return true; 
}

bool isSlotValid(int slotNumber) {
    if (slotNumber < 1 || slotNumber > MAX_SLOTS) {
        cout << "[ERROR] Invalid slot number! Please choose a slot between 1 and " << MAX_SLOTS << ".\n";
        return false; 
    }
    return true;
}

void displayCapacityStatus() {
    int available = MAX_SLOTS - carCount;
    cout << "\n========================================";
    cout << "\n         PARKING CAPACITY REPORT        ";
    cout << "\n========================================";
    cout << "\n Maximum Slot Limit : " << MAX_SLOTS;
    cout << "\n Occupied Slots     : " << carCount;
    cout << "\n Available Slots    : " << available;
    cout << "\n System Status      : " << (checkCapacity() ? "AVAILABLE" : "FULL");
    cout << "\n========================================" << endl;
}
