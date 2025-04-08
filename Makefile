CC = cc -Wall -Wextra -Werror -g

NAME = fractol
SRC = main.c init.c render.c main_utils.c map.c event.c
OBJ = $(SRC:.c=.o)

MLX_PATH = minilibx-linux
CFLAGS = -I$(MLX_PATH)
LDFLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
