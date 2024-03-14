#include <iostream>

#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList myList;

    myList.Add(3);
    myList.Add(5);
    myList.Add(7);
    myList.Add(9);

    myList.Remove(5);

    myList.InsertAfter(9, 2);

    myList.InsertAfter(3, 6);

    //myList.InsertAfter(30, 6);

    myList.Display();

    cout << endl << myList.GetCount() << endl;

    cout << myList.GetByIndex(2);
    //cout << myList.GetByIndex(8);

    return 0;
}
