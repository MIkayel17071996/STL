#include <iostream>
#include "array.hpp"
#include "RandomAccessIterator.hpp"
#include "ReverseIterator.hpp"

int main() {
    // Create an array with an initializer list
    Array<int, 5> arr = {1, 2, 3, 4, 5};

    // Test element access methods
    std::cout << "Element at index 2: " << arr.at(2) << std::endl;
    std::cout << "Element at index 2 using operator[]: " << arr[2] << std::endl;
    std::cout << "First element (front): " << arr.front() << std::endl;
    std::cout << "Last element (back): " << arr.back() << std::endl;

    // Test data() method
    std::cout << "Array data pointer: " << arr.data() << std::endl;
    std::cout << "First element via data pointer: " << *arr.data() << std::endl;

    // Test iterators
    std::cout << "Array elements using iterator: ";
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Test reverse iterators
    std::cout << "Array elements in reverse using reverse iterator: ";
    for (auto rit = arr.rbegin(); rit != arr.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    // Test capacity methods
    std::cout << "Array is empty: " << (arr.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Array size: " << arr.size() << std::endl;
    std::cout << "Array max size: " << arr.max_size() << std::endl;

    // Test fill() method
    arr.fill(10);
    std::cout << "Array after fill with 10: ";
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Test swap() method
    Array<int, 5> arr2 = {6, 7, 8, 9, 10};
    std::cout << "Array 1 before swap: ";
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Array 2 before swap: ";
    for (auto it = arr2.begin(); it != arr2.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    arr.swap(arr2);

    std::cout << "Array 1 after swap: ";
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Array 2 after swap: ";
    for (auto it = arr2.begin(); it != arr2.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

}
