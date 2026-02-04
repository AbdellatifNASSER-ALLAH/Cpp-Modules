#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    std::cout << "========== BUREAUCRAT TESTS ==========" << std::endl;
    try {
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;
        bob.plusGrade();
        std::cout << "After plusGrade: " << bob << std::endl;
        bob.plusGrade(); // Should throw
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat low("Low", 151); // Should throw
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n========== FORM TESTS ==========" << std::endl;
    std::cout << "--- Test 1: Valid Form creation ---" << std::endl;
    try {
        Form f1("Tax Form", false, 50, 25);
        std::cout << f1 << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 2: Invalid Form creation (Grade too high) ---" << std::endl;
    try {
        Form f2("Top Secret", false, 0, 1);
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 3: Invalid Form creation (Grade too low) ---" << std::endl;
    try {
        Form f3("Trash", false, 151, 150);
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n========== SIGNING TESTS ==========" << std::endl;
    try {
        Bureaucrat boss("Boss", 10);
        Bureaucrat intern("Intern", 140);
        Form important("Important Document", false, 20, 10);
        Form trivial("Trivial Note", false, 150, 150);

        std::cout << boss << std::endl;
        std::cout << intern << std::endl;
        std::cout << important << std::endl;
        std::cout << trivial << std::endl;

        std::cout << "\nIntern tries to sign important document:" << std::endl;
        intern.signForm(important);
        std::cout << important << std::endl;

        std::cout << "\nBoss tries to sign important document:" << std::endl;
        boss.signForm(important);
        std::cout << important << std::endl;

        std::cout << "\nIntern tries to sign trivial note:" << std::endl;
        intern.signForm(trivial);
        std::cout << trivial << std::endl;

        std::cout << "\nAttempting to sign an already signed form (Boss signs trivial):" << std::endl;
        boss.signForm(trivial);
        std::cout << trivial << std::endl;

    } catch (std::exception &e) {
        std::cerr << "Unexpected Exception: " << e.what() << std::endl;
    }

    return 0;
}