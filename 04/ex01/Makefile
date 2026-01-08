NAME = animals

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Animal.cpp  Cat.cpp  Dog.cpp Brain.cpp
HEADERS = Animal.hpp Cat.hpp Dog.hpp Brain.hpp

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: clean all

.PHONY: all clean fclean re
