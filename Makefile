NAME		=	writing.a

CFLAGS		=	-Wall -Werror -Wextra

SRC			=	ft_writing_cp.c \
				ft_writing_utils.c

OBJ			= $(SRC:.c=.o)

LIBFDIR		= ./writing_libft
LIBFT		= $(LIBFDIR)/writing_libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

$(LIBFT):
	make -C $(LIBFDIR) all

clean:
	make -C $(LIBFDIR) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBFDIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re