

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class	Brain {
	private:
		std::string	ideas[100];

	public:
		Brain();
		Brain(const Brain &ohter);
		Brain &operator=(const Brain &other);
		~Brain();

};

#endif
