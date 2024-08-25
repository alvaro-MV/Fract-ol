MLX_PATH=mlx_linux
MLX_LIB=mlx
NAME=fract-ol
LIB_DIR=./lib
LIBFT=lib/libft.a

SRCS=escaping_algo.c \
     mandelbrot.c 


FLAGS= -Wall -Wextra -Werror
OBJ=$(patsubst %.c, %.o, $(SRCS))

%.o: %.c
	$(CC)  -I/usr/include -I$(MLX_PATH) -O3 -c $< -o $@ -g

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFT) -L$(MLX_PATH) -l$(MLX_LIB) -L/usr/lib -I$(MLX_PATH) -lXext -lX11 -lm -lz -o $(NAME) -g

all: $(NAME)

clean:
	@rm -rf $(OBJ)

fclean:
	@rm -rf $(OBJ)
	@rm -rf $(NAME)

re: 
	make fclean
	make all
