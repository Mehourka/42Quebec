#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

NAME= libft.a
LDIR=lib/

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm
DEPS = $(LDIR)/libft.h

# Color
GREEN	=	\033[0;32m
RED		=	\033[0;31m
BLUE	=	\033[0;34m
NC		=	\033[0m

# Sources
SDIR	=	src/
SRCS	=	$(wildcard $(SDIR)/ft_*.c)

# Objects
ODIR	=	obj/
OBJS	=	$(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRCS))


#------------------------------------------------------------------------------#
#                                TARGETS                                       #
#------------------------------------------------------------------------------#

all : $(NAME)

$(ODIR)/%.o : $(SDIR)/%.c $(DEPS)
	mkdir -p $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(LDIR)

$(NAME) : $(OBJS)
	ar -rcs $@ $^

main: $(OBJS) $(NAME)
	$(CC) $(CFLAGS) -o $@ -L$(LDIR) -lft

clean :
	rm -rf $(ODIR)

fclean : clean
	rm -f $(NAME) main

re : fclean all

.PHONY : all re clean fclean