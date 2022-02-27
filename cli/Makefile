NAME		=	cli
CC			=	gcc
RM			=	rm -f

INCLUDE		=	cli.h


SRC_FILES =	main.c \
			cli_print.c \
			cli_utils.c \
			get_next_line.c \
			init.c \
			libft.c \
			report.c

SRC =	$(SRC_FILES)

OBJECTS = $(SRC:.c=.o)

.c.o:
		$(CC) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(INCLUDE)
		$(CC) $(OBJECTS) -o $(NAME)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
