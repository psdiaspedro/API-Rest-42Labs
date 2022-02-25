NAME		=	api
CC			=	gcc
FLAGS		=	-lcurl
DB_FLAG1	=	-I/usr/local/opt/mysql/include
DB_FLAG2	=	-L/usr/local/opt/mysql/lib -lmysqlclient
RM			=	rm -f

INCLUDE		=	api.h \
				mongoose.h \
				mjson.h


SRC_FILES =	main.c \
			mongoose.c \
			mjson.c \
			request.c \
			database.c \
			libft.c \
			get.c \
			api_utils.c \
			post.c \
			delete.c

SRC =	$(SRC_FILES)

OBJECTS = $(SRC:.c=.o)

.c.o:
		$(CC) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(INCLUDE)
		$(CC) $(FLAGS) $(DB_FLAG1) $(OBJECTS) -o $(NAME) $(DB_FLAG2)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
