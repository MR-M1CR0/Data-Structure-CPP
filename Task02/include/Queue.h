// Queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "StackNode.h"

using namespace std;

class Queue
{
    private:
    Node* front;
    Node* rear;

    public:
    Queue()
    {
        front = rear = NULL;
    }

    void enqueue(int data)
    {
        Node* new_node = new Node(data);
        if (front == NULL)
        {
            front = rear = new_node;
        } else
        {
            rear->Next = new_node;
            rear = new_node;
        }
    }

    int dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue is empty\n";
            return -1; // Assuming -1 as an indicator of an empty queue
        }

        int dequeued_data = front->Data;
        Node* temp = front;
        front = front->Next;

        if (front == NULL)
        {
            rear = NULL;
        }

        delete temp;
        return dequeued_data;
    }

    int peek()
    {
        if (front == NULL)
        {
            cout << "Queue is empty\n";
            return -1; // Assuming -1 as an indicator of an empty queue
        }

        return front->Data;
    }

    void display()
    {
        Node* current = front;
        while (current != NULL)
        {
            cout << current->Data << " ";
            current = current->Next;
        }
        cout << "\n";
    }
};

#endif // QUEUE_H
