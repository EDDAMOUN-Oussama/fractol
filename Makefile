NAME = fractol
SRC = fractol.c util.c math_util.c
OBJ = $(SRC:.c=.o)


$(NAME): $(OBJ) fractol.h
	cc  $(OBJ) -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus:
	Make -C ./bonus

all: $(NAME)

%.o: %.c fractol.h
	cc -c $< -Wall -Wextra -Werror -o $@

clean:
	rm -rf $(OBJ)
	Make -C bonus clean

fclean: clean
	rm -rf $(NAME)
	Make -C bonus fclean

re: fclean all

.PHONY: all bonus clean fclean  re 
