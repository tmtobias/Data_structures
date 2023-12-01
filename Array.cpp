// Array:
// Fixed in size and linear data structure.
// 
// Time O(x):
// Access element O(1)
// Insert element O(1)
// Retrieve element O(1)
// Find element O(n), when not sorted O(nlogn) when sorted O(logn)
// Delete element O(1)

#include <iostream>
#include <algorithm>

int main()
{
    // Create and initialize array except last 2 values.
    constexpr int arraySize = 5;
    int array[arraySize] = { 1, 2, 3 };

    auto print_array = [](auto& ar) {
        for (auto var : ar)
            std::cout << var << std::endl;
    };

    // Console output: 1, 2, 3, 0, 0
    print_array(array);

    // Initialize last 2 values
    array[3] = 4;
    array[4] = 5;

    // Console output: 1, 2, 3, 4, 5
    print_array(array);

    // Before binary search is executed array needs to be sorted. In our case, already is.
    if (std::binary_search(std::begin(array), std::end(array), 4))
        std::cout << "Array contains number 4" << std::endl;

    if (!std::binary_search(std::begin(array), std::end(array), 6))
        std::cout << "Array does not contain number 6" << std::endl;

    // Delete element 4
    array[3] = 0;
    print_array(array);

    return 0;
}
