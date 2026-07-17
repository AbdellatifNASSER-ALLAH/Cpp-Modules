#include <iostream>
#include <vector>
#include <exception>
#include "Span.hpp"

int main()
{
    std::cout << "--- 1. Subject Basic Test ---" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span (Expected 2): " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span (Expected 14): " << sp.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n--- 2. Exception Handling Tests ---" << std::endl;
    try {
        std::cout << "Trying to find span of empty object..." << std::endl;
        Span empty(5);
        empty.shortestSpan();
    } catch (std::exception &e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "Trying to overfill Span..." << std::endl;
        Span tiny(1);
        tiny.addNumber(42);
        tiny.addNumber(43); // Should throw here
    } catch (std::exception &e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- 3. Large Data Test (> 10,000 elements) ---" << std::endl;
    try {
        unsigned int size = 15000;
        Span bigSpan(size);
        std::vector<int> dataGen;

        // Generating a deterministic sequence: 0, 10, 20, 30... 149990
        for (unsigned int i = 0; i < size; ++i) {
            dataGen.push_back(i * 10);
        }

        std::cout << "Adding " << size << " numbers using addNumbers()..." << std::endl;
        bigSpan.addNumbers(dataGen.begin(), dataGen.end());

        // Expected shortest: 10 (difference between any adjacent elements)
        // Expected longest: 149990 (149990 - 0)
        std::cout << "Shortest Span (Expected 10): " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest Span (Expected 149990): " << bigSpan.longestSpan() << std::endl;

    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
