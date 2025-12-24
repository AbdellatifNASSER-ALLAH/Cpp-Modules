CC=c++
CFLAGS= -Wall  -Wextra -Werror

SRC=megaphone.cpp

NAME=megaphone

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $@

clean:
	rm -rf $(NAME)

re: clean all

.PHONY: all clean re
