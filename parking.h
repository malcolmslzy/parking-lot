#ifndef PARKING_H
#define PARKING_H

#include <string>
using namespace std;

const int MAX_SLOTS = 20;

struct Car {
    string plate;
    int slot;
    bool occupied;
};

extern Car lot[MAX_SLOTS];
extern int carCount;


void initializeLot();
bool isFull();
void addCar();
void displayLot();

/* Member 1 function
xxxxxxx */

/* member 3 fucntion
xxxxxxxxxx */
 

#endif
