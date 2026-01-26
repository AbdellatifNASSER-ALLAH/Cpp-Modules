NAME = bureaucrat

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Bureaucrat.cpp Form.cpp
HEADERS = Bureaucrat.hpp Form.hpp

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re
