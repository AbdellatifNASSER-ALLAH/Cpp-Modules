#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    std::cout << "--- Test 1: Basic functionality ---" << std::endl;
    try {
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;
        bob.plusGrade();
        std::cout << "After plusGrade: " << bob << std::endl;
        bob.plusGrade();
        std::cout << "After plusGrade: " << bob << std::endl;
    } catch (std::exception &e) {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n--- Test 2: Grade too high in constructor ---" << std::endl;
    try {
        Bureaucrat high("Icarus", 0);
        std::cout << high << std::endl;
    } catch (std::exception &e) {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n--- Test 3: Grade too low in constructor ---" << std::endl;
    try {
        Bureaucrat low("Slacker", 151);
        std::cout << low << std::endl;
    } catch (std::exception &e) {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n--- Test 4: Exception on plusGrade ---" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        std::cout << boss << std::endl;
        boss.plusGrade();

    } catch (std::exception &e) {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n--- Test 5: Exception on minusGrade ---" << std::endl;
    try {
        Bureaucrat intern("Intern", 150);
        std::cout << intern << std::endl;
        intern.minusGrade();
    } catch (std::exception &e) {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n--- Test 6: Copy and Assignment ---" << std::endl;
    try {
        Bureaucrat original("Original", 42);
        Bureaucrat copy(original);
        Bureaucrat assigned("Assigned", 100);
        
        assigned = original;

        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy:     " << copy << std::endl;
        std::cout << "Assigned: " << assigned << std::endl;
    } catch (std::exception &e) {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    return 0;
}
