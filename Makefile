#Variables
NAME	=	get_next_line
CC		=	gcc -g
CFLAGS	=	-Wall -Werror -Wextra
CFLAGS =

# Headers
LIB		=	get_next_line.h

# Sources
SRC		=	get_next_line.c \
			get_next_line_utils.c \
			main.c

# Objects
ODIR	=	obj/
OBJS	=	$(SRC:%.c=$(ODIR)%.o)

# File
FILE = text.txt

# Targets

all: $(NAME)

$(NAME): $(FILE) $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) -o $@ -I.
	./$(NAME)

$(ODIR)%.o: %.c
	$(MAKE) dirs
	$(CC) -c $(CFLAGS) $< -o $@ -I.

dirs:
	@mkdir -p $(ODIR)

clean:
	$(RM) -rf $(ODIR)

fclean: clean
	$(RM) $(NAME)

re : fclean all

leak :
	valgrind --leak-check=full --show-leak-kinds=all -s ./$(NAME)

.PHONY : all clean fclean re dirs leak
