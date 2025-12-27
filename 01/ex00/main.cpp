#include "Zombie.hpp"

int main() {
	std::cout << "=== Creating heap zombie ===" << std::endl;
	Zombie* heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	
	std::cout << "\n=== Creating stack zombie ===" << std::endl;
	randomChump("StackZombie");
	
	std::cout << "\n=== Cleaning up heap zombie ===" << std::endl;
	delete heapZombie;
	
	std::cout << "\n=== Program ending ===" << std::endl;
	return 0;
}
