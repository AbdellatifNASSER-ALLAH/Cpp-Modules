#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Assuming your class is defined in this header
#include "PmergeMe.hpp" 

// C++98 compliant helper to check if a vector is sorted
bool isSorted(const std::vector<int>& vec) {
    if (vec.size() < 2)
        return true;
    for (std::size_t i = 0; i < vec.size() - 1; ++i) {
        if (vec[i] > vec[i + 1])
            return false;
    }
    return true;
}

// Helper to print small vectors
void printVector(const std::vector<int>& vec) {
    std::cout << "[ ";
    for (std::size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << (i < vec.size() - 1 ? ", " : "");
    }
    std::cout << " ]\n";
}

// Test runner function
void runTest(const std::string& testName, std::vector<int> vec) {
    std::cout << "--- " << testName << " ---\n";
    
    if (vec.size() <= 20) {
        std::cout << "Before: ";
        printVector(vec);
    } else {
        std::cout << "Before: [ " << vec.size() << " elements ]\n";
    }

    // Reset your static comparison counter before each test
    PmergeMe::_nb_cmp = 0; 

    // Run the sort
    PmergeMe::sort(vec);

    if (vec.size() <= 20) {
        std::cout << "After : ";
        printVector(vec);
    } else {
        std::cout << "After : [ " << vec.size() << " elements ]\n";
    }

    if (isSorted(vec)) {
        std::cout << "\033[32m[SUCCESS]\033[0m Array is sorted! ";
    } else {
        std::cout << "\033[31m[FAILED]\033[0m Array is NOT sorted! ";
    }
    
    std::cout << "(Comparisons made: " << PmergeMe::_nb_cmp << ")\n\n";
}

int main() {
    // Seed the random number generator
    std::srand(std::time(NULL));

    // Test 1: Basic Even Length
    int arr1[] = { 42, 15, 8, 23 };
    runTest("Basic Even", std::vector<int>(arr1, arr1 + 4));

    // Test 2: Basic Odd Length (Tests your leftover logic)
    int arr2[] = { 5, 2, 9, 1, 7 };
    runTest("Basic Odd", std::vector<int>(arr2, arr2 + 5));

    // Test 3: Duplicates
    int arr3[] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
    runTest("Duplicates", std::vector<int>(arr3, arr3 + 11));

    // Test 4: Already Sorted
    int arr4[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    runTest("Already Sorted", std::vector<int>(arr4, arr4 + 10));

    // Test 5: Reverse Sorted
    int arr5[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    runTest("Reverse Sorted", std::vector<int>(arr5, arr5 + 10));

    // Test 6: Empty and Single Element
    runTest("Empty Array", std::vector<int>());
    int arr6[] = { 42 };
    runTest("Single Element", std::vector<int>(arr6, arr6 + 1));

    // Test 7: Stress Test (3000 elements - typical benchmarking size)
    std::vector<int> largeVec;
    for (int i = 0; i < 3000; ++i) {
        largeVec.push_back(std::rand() % 10000); // Random numbers 0-9999
    }
    runTest("Stress Test (3000 elements)", largeVec);

    return 0;
}