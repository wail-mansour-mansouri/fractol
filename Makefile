NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
MLX_DIR ?= mlx

CPPFLAGS = -I$(INC_DIR) -I$(MLX_DIR)
LDLIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

SRCS = \
	$(SRC_DIR)/app/exit.c \
	$(SRC_DIR)/app/init_graphics.c \
	$(SRC_DIR)/app/main.c \
	$(SRC_DIR)/events/hooks.c \
	$(SRC_DIR)/events/keyboard.c \
	$(SRC_DIR)/events/mouse.c \
	$(SRC_DIR)/events/move.c \
	$(SRC_DIR)/events/window.c \
	$(SRC_DIR)/fractals/julia.c \
	$(SRC_DIR)/fractals/mandelbrot.c \
	$(SRC_DIR)/math/complex_abs2.c \
	$(SRC_DIR)/math/complex_add.c \
	$(SRC_DIR)/math/complex_mul.c \
	$(SRC_DIR)/math/complex_square.c \
	$(SRC_DIR)/render/image.c \
	$(SRC_DIR)/render/init_view.c \
	$(SRC_DIR)/render/map.c \
	$(SRC_DIR)/render/map_inverse.c \
	$(SRC_DIR)/render/render.c \
	$(SRC_DIR)/render/viewport.c \
	$(SRC_DIR)/utils/int_array_contains.c \
	$(SRC_DIR)/utils/parse_double.c \
	$(SRC_DIR)/utils/string_equal.c \
	$(SRC_DIR)/utils/string_len.c \
	$(SRC_DIR)/utils/write_str.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

bonus: all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/fractol.h
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
