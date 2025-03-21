NAME = fractol
SRC = fractol_man.c util_man.c math_util_man.c valid_man.c
OBJ = $(SRC:.c=.o)

NAME_B = fractol_bonus
SRCB = bonus/fractol_bonus.c bonus/util_bonus.c bonus/math_util_bonus.c bonus/valid_bonus.c
OBJB = $(SRCB:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) fractol_man.h
	cc  $(OBJ) -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus: $(NAME_B)

$(NAME_B): $(OBJB) bonus/fractol_bonus.h
	cc  $(OBJB) -Wall -Wextra -Werror  -lmlx -framework OpenGL -framework AppKit -o $(NAME_B)

%_man.o: %_man.c fractol_man.h
	cc -c $< -Wall -Wextra -Werror -o $@

%_bonus.o: %_bonus.c bonus/fractol_bonus.h
	cc -c $< -Wall -Wextra -Werror -o $@

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJB)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_B)

re: fclean all

.PHONY: all bonus clean fclean  re 
