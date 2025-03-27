NAME = megaphone
CC = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98
SRC = megaphone.cpp
OBJ = megaphone.o
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

valgrind: 
	/usr/bin/valgrind --leak-check=full -s --show-leak-kinds=all ./megaphone

.PHONY: all clean fclean re download