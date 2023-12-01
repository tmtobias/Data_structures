// Stack:
// Dynamic linear data structure.
//
// Type:
// LIFO: Last In First Out
//
// Time O(x):
// Push O(1)
// Pop O(1)
// Peek O(1)
// Find O(n)
// Delete O(n)
// Modify O(n)

#include <iostream>
#include <stack>

int main()
{
    std::stack<int> myStack;
    myStack.push(1);
    myStack.push(100);
    myStack.push(3);
    myStack.push(7);

    // 7 is on top
    std::cout << myStack.top() << std::endl << std::endl;

    myStack.pop();
    // 3 is on top
    std::cout << myStack.top() << std::endl << std::endl;

    // Print all remaining and empty the stack
    while (!myStack.empty())
    {
        std::cout << myStack.top() << std::endl;
        myStack.pop();
    }

    return 0;
}
