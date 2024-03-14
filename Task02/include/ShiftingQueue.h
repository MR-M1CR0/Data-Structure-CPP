#ifndef SHIFTINGQUEUE_H
#define SHIFTINGQUEUE_H

#include <iostream>

using namespace std;

class ShiftingQueue
{
    private:
    int* arr;
    int size;
    int front;
    int rear;

    public:
    ShiftingQueue(int _size) {
        front = -1;
        rear = -1;
        size = _size;
        arr = new int[size];
    }

    ~ShiftingQueue() {
        for (int i = 0; i < size; i++) {
            arr[i] = -1;
        }
        delete[] arr;
    }

    void Enqueue(int value) {
        if (IsFull()) {
            cout << "Queue is full. Cannot enqueue.\n";
            return;
        }

        if (IsEmpty()) {
            front = 0;
        }

        rear++;
        arr[rear] = value;
    }

    int Dequeue() {
        if (IsEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }

        int dequeuedValue = arr[front];

        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            // Shift remaining elements to the left
            for (int i = front; i < rear; i++) {
                arr[i] = arr[i + 1];
            }
            rear--;
        }

        return dequeuedValue;
    }

    bool IsFull() {
        return rear == size - 1;
    }

    bool IsEmpty() {
        return front == -1;
    }

    void display() {
        if (IsEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
#endif // SHIFTINGQUEUE_H
