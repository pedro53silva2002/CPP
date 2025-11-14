NAME = PmergeMe
CC = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98
SRCS = main.cpp PmergeMe.cpp
	
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -c 

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

valgrind: 
	/usr/bin/valgrind --leak-check=full -s --show-leak-kinds=all ./$(NAME) 3 5 9 7 4

.PHONY: all clean fclean re download