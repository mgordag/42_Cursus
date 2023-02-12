SOURCES			=	ft_strjoin.c ft_split.c
SOURCES			+=	errors.c pipex.c pipex_utils.c

OBJECTS			= $(SOURCES:.c=.o)
CC			= gcc
RM			= rm -rf
CFLAGS			= -Wall -Wextra -Werror
NAME			= pipex

$(NAME):$(OBJECTS)
	@$(CC) $(OBJECTS) -o $(NAME)
	@echo -e "$(RED) $(NAME) created!"

all:$(NAME)

clean:
	@$(RM) $(OBJECTS)
	@echo -e "$(RED)Objects removed from file"

fclean: clean
	@$(RM) $(NAME)
	@echo -e "$(RED) $(NAME) file removed from file"

re:	fclean all

.PHONY: all clean fclean re


RED = \033[0;31m