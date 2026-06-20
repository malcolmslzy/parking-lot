#ifndef PARKING_H
#define PARKING_H

#include <string>
using namespace std;

const int MAX_SLOTS = 50;

struct Car {
    string plate;
    int slot;
    bool occupied;
    string entryDate;
    string entryTime;
};

struct QueueNode {
    string regNumber;
    string entryDate;
    string entryTime;
    QueueNode* next;
};

struct Queue {
    QueueNode* front;
    QueueNode* back;
};

extern Car lot[MAX_SLOTS];
extern int carCount;
extern Queue waitingQueue;


void initializeLot();
bool isFull();
void addCar();
void displayLot();

void enqueue(Queue& q, string regNumber, string entryDate, string entryTime);
void dequeue(Queue& q);
void searchByCar(string searchPlate);
void checkSlot(int slotNumber);
void displayReport();

/* member 3 fucntion
xxxxxxxxxx */
 

#endif
