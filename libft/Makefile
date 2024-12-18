# Nombre de la librería
NAME = libft.a

NAME_BONUS = libft_bonus.a

# Compilador
CC = gcc

# Opciones de compilación
CFLAGS = -Wall -Wextra -Werror

# Directorio de archivos fuente
SRCDIR = .

# Obtener automáticamente todos los archivos .c en el directorio
SRCS =	ft_atoi.c \
		  ft_bzero.c \
		  ft_calloc.c \
		  ft_isalnum.c \
		  ft_isalpha.c \
		  ft_isascii.c \
		  ft_isdigit.c \
		  ft_isprint.c \
		  ft_itoa.c \
		  ft_itoa_w.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_memcpy.c \
		  ft_memmove.c \
		  ft_memset.c \
		  ft_putchar_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_putstr_fd.c \
		  ft_split.c \
		  ft_strchr.c \
		  ft_strdup.c \
		  ft_striteri.c \
		  ft_strjoin.c \
		  ft_strlcat.c \
		  ft_strlcpy.c \
		  ft_strlen.c \
		  ft_strmapi.c \
		  ft_strcmp.c \
		  ft_strncmp.c \
		  ft_strnstr.c \
		  ft_strrchr.c \
		  ft_strtrim.c \
		  ft_substr.c \
		  ft_tolower.c \
		  ft_toupper.c \
		  ft_printf.c \
		  ft_chtoa.c \
		  ft_ptoa.c \
		  ft_utoa.c \
		  ft_itoa.c \
		  ft_strtoa.c \
		  ft_xtoa.c \
		  get_next_line.c \
		  ft_free_array.c

SRCS_BONUS = ft_lstadd_back_bonus.c \
		  ft_lstadd_front_bonus.c \
		  ft_lstdelone_bonus.c \
		  ft_lstclear_bonus.c \
		  ft_lstiter_bonus.c \
		  ft_lstmap_bonus.c \
		  ft_lstlast_bonus.c \
		  ft_lstnew_bonus.c \
		  ft_lstsize_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

$(NAME_BONUS): $(OBJS_BONUS)
	ar rcs $@ $^

bonus: $(NAME_BONUS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re 
