NAME = fractol
SRC = fractol.c util.c math_util.c
OBJ = $(SRC:.c=.o)


SRC_B = fractol_bonus.c util_bonus.c math_util_bonus.c
OBJ_B = $(SRC_B:.c=.o)

$(NAME): $(OBJ) fractol.h
	cc  $(OBJ) -Wall -Wextra -Werror -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus: $(OBJ_B) fractol_bonus.h
	cc  $(OBJ_B) -Wall -Wextra -Werror -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME) bonus

%.o: %.c fractol.h
	cc -c $< -Wall -Wextra -Werror -o $@

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_B)

fclean: clean
	rm -rf $(NAME)

re: fclean all