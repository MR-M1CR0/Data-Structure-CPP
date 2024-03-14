#include <iostream>

#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList list;

    // Adding elements to the list
    list.Add(5);
    list.Add(9);
    list.Add(7);
    list.Add(3);
    list.Add(0);
    list.Add(10);

    // Displaying the original list
    cout << "Original linked list: ";
    list.Display();

    // Testing bubble sort
    int bubbleSortIterations;
    list.bubbleSort(bubbleSortIterations);
    cout << "Linked list after Bubble Sort: ";
    list.Display();
    cout << "Bubble Sort Iterations: " << bubbleSortIterations << endl;

    // Testing binary search
    int searchValue = 3;
    bool found = list.binarySearch(searchValue);
    if (found) {
        cout << searchValue << " found in the linked list." << endl;
    } else {
        cout << searchValue << " not found in the linked list." << endl;
    }

    searchValue = 7;
    found = list.binarySearch(searchValue);
    if (found) {
        cout << searchValue << " found in the linked list." << endl;
    } else {
        cout << searchValue << " not found in the linked list." << endl;
    }

    searchValue = 20;
    found = list.binarySearch(searchValue);
    if (found) {
        cout << searchValue << " found in the linked list." << endl;
    } else {
        cout << searchValue << " not found in the linked list." << endl;
    }

    searchValue = 0;
    found = list.binarySearch(searchValue);
    if (found) {
        cout << searchValue << " found in the linked list." << endl;
    } else {
        cout << searchValue << " not found in the linked list." << endl;
    }
    return 0;
}
