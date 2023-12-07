// Min-Heap and Max-Heap example

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> heap = { 4, 7, 1, 3, 5, 9 };

    // Min-Heap implementation
    std::make_heap(heap.begin(), heap.end(), std::greater<int>());

    std::cout << "Min-Heap: ";
    for (const auto& element : heap) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    std::cout << "Heap front(): " << heap.front() << std::endl;
    std::cout << "Heap back(): " << heap.back() << std::endl;

    // Min-Heap after pop
    heap.pop_back();
    std::pop_heap(heap.begin(), heap.end(), std::greater<int>());
    std::cout << "Heap front() after pop_back(): " << heap.front() << std::endl;

    // Max-Heap implementation
    std::make_heap(heap.begin(), heap.end());

    std::cout << "Max-Heap: ";
    for (const auto& element : heap) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    std::cout << "Heap front(): " << heap.front() << std::endl;
    std::cout << "Heap back(): " << heap.back() << std::endl;

    // Max-Heap after push
    heap.push_back(99);
    std::push_heap(heap.begin(), heap.end());
    std::cout << "Heap front() after push_back(): " << heap.front() << std::endl;

    return 0;
}
