SRCS			= fdf.c get_data.c rotations.c drawing.c key_hooks.c print.c mouse_hooks.c operations.c errors.c\
				utils/get_next_line.c utils/get_next_line_utils.c \
				utils/ft_atoi.c utils/ft_split.c
RM				= rm -f
GCC				= gcc -Wall -Wextra -Werror
NAME			= fdf

all:			$(SRCS) $(NAME)


$(NAME): $(SRCS)
	@make -C mlx
	@$(GCC) -I./mlx -framework OpenGL -framework AppKit $(SRCS) -L./mlx -lmlx -o $(NAME)
	@echo mlx is compiled successfully
	@echo fdf is created successfully
clean:
	@$(RM) $(NAME)
	@echo fdf is removed successfully

fclean:			clean
	@make clean -C mlx

re:				fclean
	make


.PHONY:			all clean fclean re
