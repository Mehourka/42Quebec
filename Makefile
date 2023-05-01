CC = gcc
CFLAGS = -Wall -Werror -Wextra
CFLAGS =
NAME = prog



SRC =	ft_printf.c \
		ft_printf_char.c
OBJ =

all : re test

$(NAME) :
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean :
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(NAME)

re : fclean $(NAME)
	@echo "recompile ...\n"

test : $(NAME)
	@./$(NAME)

.PHONY :
	all clean fclean re test
