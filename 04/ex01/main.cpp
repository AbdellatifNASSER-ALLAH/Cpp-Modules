#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "----------------- 1. SUBJECT TEST ---------------------" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        std::cout << "Type: " << j->getType() << " " << std::endl;
        std::cout << "Type: " << i->getType() << " " << std::endl;
        
        std::cout << "Sound (Cat): "; i->makeSound(); 
        std::cout << "Sound (Dog): "; j->makeSound();
        std::cout << "Sound (Animal): "; meta->makeSound();

        delete meta;
        delete i;
        delete j;
    }

    std::cout << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "----------------- 2. WRONG ANIMAL TEST ----------------" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    {
        const WrongAnimal* wrongMeta = new WrongAnimal();
        const WrongAnimal* wrongCat = new WrongCat();

        std::cout << "Type: " << wrongCat->getType() << " " << std::endl;
        
        std::cout << "Sound (WrongCat as WrongAnimal*): "; 
        wrongCat->makeSound(); // Should output WrongAnimal sound due to lack of virtual
        
        std::cout << "Sound (WrongAnimal): ";
        wrongMeta->makeSound();

        delete wrongMeta;
        delete wrongCat;
    }

    std::cout << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "----------------- 3. CANONICAL FORM TEST --------------" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    {
        std::cout << "[1] Creating Dog 'original' on stack..." << std::endl;
        Dog original;
        
        std::cout << "[2] Creating Dog 'copy' via Copy Constructor..." << std::endl;
        Dog copy(original);
        
        std::cout << "[3] Creating Dog 'assigned'..." << std::endl;
        Dog assigned;
        std::cout << "[4] Assigning original to 'assigned' via operator=..." << std::endl;
        assigned = original;

        std::cout << "[5] Testing sounds..." << std::endl;
        std::cout << "Original: "; original.makeSound();
        std::cout << "Copy: "; copy.makeSound();
        std::cout << "Assigned: "; assigned.makeSound();
        
        std::cout << "[6] Destructors will run now (Reverse order)..." << std::endl;
    }

    return 0;
}
