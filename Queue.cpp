// Queue:
// Dynamic linear data structure.
//
// Type:
// FIFO: First In First Out
//
// Time O(x):
// Enque O(1)
// Deque O(1)
// Peek O(1)
// Search O(n)
// Delete O(n)

#include <iostream>
#include <queue>

int main()
{
    std::queue<int> myQueue;

    myQueue.push(1);
    myQueue.push(30);
    myQueue.push(11);
    myQueue.push(15);

    // Display who is first -> 1
    std::cout << myQueue.front() << std::endl << std::endl;

    // Pop first element and add element at the end
    myQueue.pop();
    myQueue.push(100);

    // Display all elements in the queue
    while (!myQueue.empty())
    {
        std::cout << myQueue.front() << std::endl;
        myQueue.pop();
    }

    return 0;
}
