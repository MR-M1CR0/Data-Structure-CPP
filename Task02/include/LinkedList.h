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
            {
                head = tail = node;
            }
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
                cout << current->Data;
                current = current->Next;
            }
        }

        void Remove(int data)
        {
            Node *node = GetNodeByData(data);

            if(node == NULL)
            {
                return;
            }

            if(node == head)
            {
                if(node == tail)
                {
                    head = tail = NULL;
                }
                else
                {
                    head = head->Next;
                    head->Prev = NULL;
                }
            }
            else if(node == tail)
            {
                tail = tail->Prev;
                tail->Next = NULL;
            }
            else
            {
                Node *A = node->Prev;
                Node *B = node->Next;

                A->Next = B;
                B->Prev = A;
            }

            delete node;

        }

        int Search(int data)
        {
            Node *node = GetNodeByData(data);
            return node != NULL;
        }


        void InsertAfter(int data, int afterData)
        {
            Node *afterNode = GetNodeByData(data);

            if (afterNode == NULL)
            {
                cout << "Node with data " << data << " not found." << endl;
                return;
            }

            Node *newNode = new Node(afterData);

            newNode->Next = afterNode->Next;
            newNode->Prev = afterNode;
            afterNode->Next = newNode;

            if (newNode->Next != NULL)
            {
                newNode->Next->Prev = newNode;
            }
            else
            {
                // If inserting after the tail, update the tail
                tail = newNode;
            }
        }

        int GetCount()
        {
            int Count = 0;
            Node *Current = head;

            while(Current != NULL)
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

            while(Current != NULL)
            {
                if(CurrentIndex == index)
                    return Current->Data;
                CurrentIndex++;
                Current = Current->Next;
            }

            return -1;
        }

    protected:

    private:

        Node* GetNodeByData(int data)
        {
            Node *current = head;
            while (current != NULL)
            {
                if(data == current->Data)
                    return current;
                current = current->Next;
            }

            return NULL;
        }
};

#endif // LINKEDLIST_H
