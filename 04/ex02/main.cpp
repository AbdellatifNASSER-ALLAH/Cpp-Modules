#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define N_ANIMALS 10

int main() {
	std::cout << "========================================" << std::endl;
	std::cout << "       TEST 1: ARRAY OF ANIMALS         " << std::endl;
	std::cout << "========================================" << std::endl;

	Animal* animals[N_ANIMALS];

	for (int i = 0; i < N_ANIMALS; i++) {
		std::cout << "\n[Creating Animal " << i << "]" << std::endl;
		if (i < N_ANIMALS / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "\n[Testing Sounds]" << std::endl;
	for (int i = 0; i < N_ANIMALS; i++) {
		animals[i]->makeSound();
	}

	std::cout << "\n[Deleting Animals]" << std::endl;
	for (int i = 0; i < N_ANIMALS; i++) {
		std::cout << "Deleting Animal " << i << " (" << animals[i]->getType() << ")" << std::endl;
		delete animals[i];
	}

	std::cout << "\n========================================" << std::endl;
	std::cout << "       TEST 2: DEEP COPY PROOF          " << std::endl;
	std::cout << "========================================" << std::endl;

	std::cout << "\n[1] Creating Dog A" << std::endl;
	Dog dogA;
	dogA.setIdea(0, "I want a bone");
	dogA.setIdea(1, "I want to sleep");

	std::cout << "\n[2] Creating Dog B as a copy of Dog A" << std::endl;
	Dog dogB(dogA);

	std::cout << "\n[3] Modifying Dog A's brain..." << std::endl;
	dogA.setIdea(0, "I want a steak"); // Change index 0

	std::cout << "\n[4] Checking Dog B's brain (Should be unchanged)" << std::endl;
	std::cout << "Dog A Idea 0: " << dogA.getIdea(0) << std::endl;
	std::cout << "Dog B Idea 0: " << dogB.getIdea(0) << std::endl;

	if (dogA.getIdea(0) != dogB.getIdea(0)) {
		std::cout << "SUCCESS: Dog B has its own Brain!" << std::endl;
	} else {
		std::cout << "FAILURE: Dog B shares Brain with Dog A (Shallow Copy)!" << std::endl;
	}

	std::cout << "\n========================================" << std::endl;
	std::cout << "       TEST 3: ASSIGNMENT OPERATOR      " << std::endl;
	std::cout << "========================================" << std::endl;

	std::cout << "\n[1] Creating Cat A" << std::endl;
	Cat catA;
	catA.setIdea(0, "Chase laser");

	std::cout << "\n[2] Creating Cat B" << std::endl;
	Cat catB;
	catB.setIdea(0, "Sleep all day");

	std::cout << "\n[3] Assigning A = B" << std::endl;
	catA = catB;

	std::cout << "\n[4] Modifying Cat B" << std::endl;
	catB.setIdea(0, "Eat tuna");

	std::cout << "Cat A Idea 0: " << catA.getIdea(0) << std::endl;
	std::cout << "Cat B Idea 0: " << catB.getIdea(0) << std::endl;

	if (catA.getIdea(0) != catB.getIdea(0)) {
		std::cout << "SUCCESS: Cat A has its own Brain!" << std::endl;
	} else {
		std::cout << "FAILURE: Cat A shares Brain with Cat B!" << std::endl;
	}

	std::cout << "\n[End of Tests]" << std::endl;
	return 0;
}
