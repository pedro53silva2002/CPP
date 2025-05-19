NAME = DiamondTrap
CC = c++
CFLAGS = -Wall -Wextra -Werror -Wshadow -Wno-shadow -g -std=c++98
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
	
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

valgrind: 
	/usr/bin/valgrind --leak-check=full -s --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re download