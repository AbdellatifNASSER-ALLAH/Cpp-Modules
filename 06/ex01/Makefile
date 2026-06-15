NAME = serialize

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Serializer.cpp
HEADERS = Serializer.hpp Data.hpp

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re
