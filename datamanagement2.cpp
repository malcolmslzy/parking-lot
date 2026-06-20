#include "parking.h"
#include <iostream>
using namespace std;

// your Queue instance
Queue waitingQueue;


// 1. enqueue()
   void enqueue(Queue& q, string regNumber, string entryDate, string entryTime) {
   QueueNode* newNode = new QueueNode;
   newNode->regNumber = regNumber;   
   newNode->entryDate = entryDate;   
   newNode->entryTime = entryTime;   
   newNode->next = NULL;


   if (q.front == NULL) {
     q.front = newNode;
     q.back = newNode;
    } else {
     q.back->next = newNode;
     q.back = newNode;
}

// 2. dequeue()
   void dequeue(Queue& q) {
    if (q.front == NULL) {
        cout << "No cars waiting!" << endl;
        return;
    }

    QueueNode* temp = q.front;
    q.front =q.front->next;

    if (q.front == NULL)
        q.back = NULL;

   cout << "Car " << temp->regNumber << " entering parking lot!" << endl;
   delete temp;
} 

// 3. searchByCar()
   void searchByCar(string searchPlate) {
    for (int i = 0; i < MAX_SLOTS; i++) {
        if (lot[i].occupied && lot[i].plate == searchPlate) {
            cout << "Car found!" << endl;
            cout << "Slot: " << lot[i].slot << endl;
            cout << "Plate: " << lot[i].plate << endl;
            return;
        }
    }
    cout << "Car not found!" << endl;
}

// 4. checkSlot()
   void checkSlot(int slotNumber) {
    if (slotNumber < 1 || slotNumber > 20) {
        cout << "Invalid slot number!" << endl;
        return;
    }
    
    int index = slotNumber - 1;
    
    if (lot[index].occupied) {
        cout << "Slot " << slotNumber << " is occupied by: " << lot[index].plate << endl;
    } else {
        cout << "Slot " << slotNumber << " is Empty" << endl;
    }
}

// 5. displayReport()
   void displayReport() {
    cout << "=== Parking Lot Report ===" << endl;
    cout << "Total slots: " << MAX_SLOTS << endl;
    cout << "Occupied: " << carCount << endl;
    cout << "Available: " << MAX_SLOTS - carCount << endl;
    cout << "-------------------------" << endl;
    
    for (int i = 0; i < MAX_SLOTS; i++) {
        cout << "Slot " << lot[i].slot << ": ";
        if (lot[i].occupied) {
            cout << lot[i].plate << " | " << lot[i].entryDate << " | " << lot[i].entryTime;
        } else {
            cout << "Empty";
        }
        cout << endl;
    }
}
