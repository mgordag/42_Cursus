SRCS = main.c process_with_one.c routine.c utils.c utils2.c

OTHERS = philo.h Makefile

CC = gcc -Wall -Wextra -Werror -pthread -fsanitize=thread -g

RM = rm -rf

NAME = philo

all : $(NAME)

$(NAME): $(SRCS) $(OTHERS)
	$(CC) $(SRCS) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re