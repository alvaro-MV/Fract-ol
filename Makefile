MLX_PATH=mlx_linux
MLX_LIB=mlx
NAME=fractol
LIB_DIR=./libft
LIBFT=libft/libft.a

SRCS=rgb_map.c \
	 hsv_map.c \
     mandatory.c \
     main.c \
	 ft_atof.c \
     hooks.c \
	 parse_params.c \
	 lyapunov.c \


FLAGS= -Wall -Wextra -Werror
OBJ=$(patsubst %.c, %.o, $(SRCS))

%.o: %.c
	gcc -Wall -Wextra -I/usr/include -I$(MLX_PATH) -O3 -c $< -o $@ -g


$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LIBFT) -L$(MLX_PATH) -l$(MLX_LIB) -L/usr/lib -I$(MLX_PATH) -lXext -lX11 -lm -lz -o $(NAME) -g


$(LIBFT):
	@make -sC $(LIB_DIR)

all: $(NAME)

clean:
	@make fclean -C $(LIB_DIR)
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: 
	make fclean
	make all

.PHONY: all re clean fclean
