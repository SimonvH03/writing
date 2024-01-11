NAME		=	writing_libft.a

CFLAGS		=	-Wall -Werror -Wextra

SRC			=	ft_bzero_wr.c \
				ft_isprint_wr.c \
				ft_charcat_wr.c \
				ft_strcat_wr.c \
				ft_strdup_wr.c \
				ft_strlen_wr.c 

OBJ			=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re