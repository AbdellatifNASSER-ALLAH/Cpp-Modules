#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    // Seed for RobotomyRequestForm randomness
    std::srand(std::time(NULL));

    Intern someRandomIntern;
    Bureaucrat boss("The Boss", 1);
    Bureaucrat minion("Minion", 150);

    AForm* rrf = NULL;
    AForm* ppf = NULL;
    AForm* scf = NULL;
    AForm* unknown = NULL;

    std::cout << "\n--- Intern creates forms ---" << std::endl;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    ppf = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
    scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
    unknown = someRandomIntern.makeForm("vacation request", "Me"); // Should fail

    std::cout << "\n--- Testing Robotomy Request Form ---" << std::endl;
    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }

    std::cout << "\n--- Testing Presidential Pardon Form ---" << std::endl;
    if (ppf) {
        boss.signForm(*ppf);
        boss.executeForm(*ppf);
        delete ppf;
    }

    std::cout << "\n--- Testing Shrubbery Creation Form ---" << std::endl;
    if (scf) {
        minion.signForm(*scf); // Should fail (grade too low)
        boss.signForm(*scf);   // Should succeed
        boss.executeForm(*scf); // Should create Garden_shrubbery
        delete scf;
    }

    std::cout << "\n--- Testing Unknown Form ---" << std::endl;
    if (unknown) {
        delete unknown;
    } else {
        std::cout << "Successfully handled unknown form creation." << std::endl;
    }

    std::cout << "\n--- End of tests ---" << std::endl;

    return 0;
}
