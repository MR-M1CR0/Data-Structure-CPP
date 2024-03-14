#include <iostream>

#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "ShiftingQueue.h"
#include "CircularQueue.h"

using namespace std;

int main()
{
    // Test LinkedList Stack
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Stack after pushing 1, 2, and 3:\n";
    stack.display();

    cout << "Top of the stack: " << stack.peek() << "\n";

    int num;
    int success = stack.pop(num);
    if(success)
    {
        cout << "Popped item: " << num << "\n";
    }

    cout << "Stack after popping an item:\n";
    stack.display();

    cout << "---------------------------------------------------------------\n";

    // Test LinkedList Queue
    Queue myQueue;

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    cout << "Queue after enqueueing 1, 2, and 3:\n";
    myQueue.display();

    cout << "Front of the queue: " << myQueue.peek() << "\n";

    int dequeued_item = myQueue.dequeue();
    cout << "Dequeued item: " << dequeued_item << "\n";

    cout << "Queue after dequeueing an item:\n";
    myQueue.display();

    cout << "---------------------------------------------------------------\n";

    // Test ShiftingQueue
    ShiftingQueue ShiftingQueue(5);

    ShiftingQueue.Enqueue(1);
    ShiftingQueue.Enqueue(2);
    ShiftingQueue.Enqueue(3);

    cout << "ShiftingQueue after enqueueing 1, 2, and 3:\n";
    ShiftingQueue.display();

    int dequeuedItemShifted = ShiftingQueue.Dequeue();
    cout << "Dequeued item from ShiftingQueue: " << dequeuedItemShifted << "\n";

    cout << "ShiftingQueue after dequeueing an item:\n";
    ShiftingQueue.display();
    ShiftingQueue.Dequeue();
    ShiftingQueue.Dequeue();
    ShiftingQueue.Dequeue();

    cout << "---------------------------------------------------------------\n";

    // Test CircularQueue
    CircularQueue circularQueue(5);

    circularQueue.Enqueue(1);
    circularQueue.Enqueue(2);
    circularQueue.Enqueue(3);

    cout << "CircularQueue after enqueueing 1, 2, and 3:\n";
    circularQueue.display();

    int dequeuedItemCircular = circularQueue.Dequeue();
    cout << "Dequeued item from CircularQueue: " << dequeuedItemCircular << "\n";

    cout << "CircularQueue after dequeueing an item:\n";
    circularQueue.display();
    circularQueue.Dequeue();
    circularQueue.Dequeue();
    circularQueue.Dequeue();


    return 0;
}
