CC = cc

NAME = fractol
SRC = main.c init.c render.c main_utils.c map.c event.c
OBJ = $(SRC:.c=.o)

MLX_DIR = ../42tokyo/fract-ol/minilibx-linux
X11_DIR = /opt/homebrew/Cellar/libx11/1.8.11
XEXT_DIR = /opt/homebrew/Cellar/libxext/1.3.6

CFLAGS = -Wall -Wextra -Werror -O2
CFLAGS += -I$(MLX_DIR) -I$(X11_DIR)/include -I$(XEXT_DIR)/include

LDFLAGS = -L$(MLX_DIR) -L$(X11_DIR)/lib -L$(XEXT_DIR)/lib
LDFLAGS += -lmlx -lX11 -lXext -framework OpenGL -framework AppKit

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
