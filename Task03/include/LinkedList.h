#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.h"

using namespace std;


class LinkedList
{
    Node *head, *tail;

    public:
        LinkedList()
        {
            head = tail = NULL;
        }

        void Add(int data)
        {
            Node *node = new Node(data);

            if(head == NULL)
                head = tail = node;
            else
            {
                tail->Next = node;
                node->Prev = tail;
                tail = node;
            }
        }

        void Display()
        {
            Node *current = head;
            while (current != NULL)
            {
                cout << current->Data << " "; // Add space after each element
                current = current->Next;
            }
            cout << endl; // Add a newline at the end
        }


        int GetCount()
        {
            int Count = 0;
            Node *Current = head;

            while (Current != NULL)
            {
                Count++;
                Current = Current->Next;
            }
            return Count;
        }

        int GetByIndex(int index)
        {
            int CurrentIndex = 0;
            Node *Current = head;

            while (Current != NULL)
            {
                if (CurrentIndex == index)
                    return Current->Data;
                CurrentIndex++;
                Current = Current->Next;
            }
            return -1;
        }
        void bubbleSort(int& iterationCount)
        {
            int n = GetCount();
            iterationCount = 0;

            if (n <= 1)
            {
                // Already sorted or empty list
                return;
            }

            for (int i = 0; i < n - 1; i++)
            {
                Node* current = head;
                for (int j = 0; j < n - i - 1; j++)
                {
                    Node* nextNode = current->Next;

                    // Compare the data of the current node and the next node
                    if (current->Data > nextNode->Data)
                    {
                        // Swap nodes using the swap function
                        swapNodes(current, nextNode);
                    }
                    else
                    {
                        // Move to the next pair of nodes
                        current = current->Next;
                    }

                    iterationCount++;
                }
            }
        }

int GetIndex(int value)
    {
        int currentIndex = 0;
        Node* current = head;

        while (current != NULL)
        {
            if (current->Data == value)
                return currentIndex;

            currentIndex++;
            current = current->Next;
        }

        // Value not found
        return -1;
    }

bool binarySearch(int value)
{
    Node* start = head;
    Node* end = tail;

    while (start != end && start != NULL && end != NULL)
    {
        int midIndex = (GetIndex(start->Data) + GetIndex(end->Data)) / 2; // Calculate midIndex based on start and end
        int midValue = GetByIndex(midIndex);

        if (midValue == value)
        {
            return true;
        }
        else if (midValue > value)
        {
            end = GetNodeByData(midValue)->Prev;
        }
        else
        {
            start = GetNodeByData(midValue)->Next;
        }
    }

    if (start != NULL && start->Data == value)
    {
        return true;
    }

    return false;
}


    private:
        Node* GetNodeByData(int data)
        {
            Node *current = head;
            while (current != NULL)
            {
                if (data == current->Data)
                    return current;
                current = current->Next;
            }
            return NULL;
        }

        void swapNodes(Node* node1, Node* node2)
        {
            // Swap the nodes
            if (node1->Prev != NULL)
            {
                node1->Prev->Next = node2;
            }
            else
            {
                head = node2;
            }

            if (node2->Next != NULL)
            {
                node2->Next->Prev = node1;
            }
            else
            {
                tail = node1;
            }

            node1->Next = node2->Next;
            node2->Prev = node1->Prev;

            node2->Next = node1;
            node1->Prev = node2;
        }
};

#endif // LINKEDLIST_H
