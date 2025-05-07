NAME = Zombie
CC = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98
SRCS = main.cpp \
		Zombie.cpp \
		NewZombie.cpp \
		RandomChump.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

objs:

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

valgrind: 
	/usr/bin/valgrind --leak-check=full -s --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re download