CC = gcc
CFLAGS = -Wall -Werror -Wextra
CFLAGS =
NAME = libftprintf.a

IDIR = lib/


SDIR = src/
SRCS =	ft_printf.c \
		ft_printf_char.c \
		ft_printf_dec.c\
		ft_printf_hex.c\

ODIR = obj/
OBJS := $(SRCS:%.c=$(ODIR)%.o)
SRCS := $(SRCS:%=$(SDIR)%)

all : $(NAME)

$(ODIR)%.o:  $(SDIR)%.c
	@$(MAKE) -s makedir
	@$(CC) -c $(CFLAGS) $< -o $@ -I$(IDIR)

$(NAME) : $(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean :
	@$(RM) -rf $(ODIR)

fclean : clean
	@$(RM) $(NAME)

re : fclean $(NAME)

makedir :
	@mkdir -p $(ODIR)

test :
	$(CC) $(CFLAGS) main.c -o main -I$(IDIR) -lftprintf -L.

.PHONY :
	all clean fclean re test makedir
