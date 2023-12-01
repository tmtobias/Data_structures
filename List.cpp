// Linked list :
// Dynamic linear data structure.
// 
// Types :
// Singly, doublyand circular LL
// 
// Time O(x) :
// Access element O(n)
// Insert element O(1)
// Retrieve element O(n)
// Find element O(n)
// Delete element O(1), O(n)
// Modify element O(n)

#include <iostream>
#include <list>

int main()
{
    // Create list with some values
    std::list<int> myList = {5, 3, 7, 4};

    auto print_list = [](auto& l) {
        for (auto var : l)
            std::cout << var << std::endl;
        std::cout << std::endl;
    };

    print_list(myList);

    // Insert elements at the begining and at the end -> -5, 5, 3, 7, 4, 80
    myList.push_back(80);
    myList.push_front(-5);

    print_list(myList);

    // Insert element after the first value in the list -> -5, 100, 5, 3, 7, 4, 80
    std::list<int>::iterator it = myList.begin();
    myList.insert(++it, 100);

    print_list(myList);

    // Sort elements in the list -> -5, 3, 4, 5, 7, 80, 100
    myList.sort();

    print_list(myList);

    return 0;
}
