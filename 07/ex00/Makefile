NAME = whatever

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp 
HEADERS = whatever.hpp 

all: $(NAME)

$(NAME): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)


clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
