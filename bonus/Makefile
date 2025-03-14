NAME = ../fractol
SRC = fractol_bonus.c util_bonus.c math_util_bonus.c
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ) fractol_bonus.h
	cc  $(OBJ) -Wall -Wextra -Werror  -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	
%.o: %.c fractol_bonus.h
	cc -c $< -Wall -Wextra -Werror -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
