// Stack.h
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "StackNode.h"

using namespace std;

class Stack
{
    private:
    Node* top;

    public:
    Stack()
    {
        top = NULL;
    }

    void push(int data)
    {
        Node* new_node = new Node(data);
        new_node->Next = top;
        top = new_node;
    }

    int pop(int &data)
    {
        if (top == NULL)
        {
            cout << "Stack is empty\n";
            return 0;
        }

        data = top->Data;
        Node* temp = top;
        top = top->Next;
        delete temp;
        return 1;
    }

    int peek()
    {
        if (top == NULL)
        {
            cout << "Stack is empty\n";
            return -1; // Assuming -1 as an indicator of an empty stack
        }

        return top->Data;
    }

    void display()
    {
        Node* current = top;
        while (current != NULL)
        {
            cout << current->Data << " ";
            current = current->Next;
        }
        cout << "\n";
    }
};

#endif // STACK_H
