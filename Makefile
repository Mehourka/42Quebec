#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

ARGS = "10 9 12 -12 14 32"

NAME = push_swap
LDIR	=	libft/
LIBFT	=	$(LDIR)/libft.a
IDIR	=	lib/
HEADERS	=	$(IDIR)/push_swap.h \
			$(LDIR)/libft.h
INCLUDES= $(patsubst %, -I%, $(dir $(HEADERS)))


# Colors
GREEN	=	\033[0;32m
RED		=	\033[0;31m
BLUE	=	\033[0;34m
NC		=	\033[0m

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
CFLAGS +=	$(INCLUDES)
RM		=	rm

# Sources
SDIR	=	src/
BDIR	=	bonus/

SRCS	=	push_swap.c		\
			stack_utils.c	\
			parsing.c		\
			push.c			\
			swap.c			\
			rot.c			\
			rev_rot.c		\
			testing.c		\
			index.c			\
			stack_sort.c			\

# Objects
ODIR	=	obj/
OBJS		:=	$(SRCS:%.c=$(ODIR)%.o)

SRCS		:=	$(SRCS:%.c=$(SDIR)%.c)


#------------------------------------------------------------------------------#
#                                TARGETS                                       #
#------------------------------------------------------------------------------#

all : $(NAME)

exec : $(NAME)
	./$(NAME) $(ARGS)

# Compile exec
$(NAME) :  $(LIBFT) $(OBJS)
	@echo "$(GREEN)	Compiling $(NAME)... $(NC)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) -I.

$(BONUS) :  $(LIBFT) $(OBJS_BONUS)
	@echo "$(GREEN)	Compiling $(NAME)... $(NC)"
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(BONUS) -I.

# Compile libft
$(LIBFT):
	@echo "$(BLUE)	Compiling libft ...	$(NC)"
	@$(MAKE) -C $(@D) -s

# Compile objects
$(ODIR)%.o : $(SDIR)%.c
	@mkdir -p $(ODIR);
	@$(CC) -c $(CFLAGS) $< -o $@

# Compile Bonus
$(ODIR)%.o : $(BDIR)%.c
	@mkdir -p $(ODIR);
	@$(CC) -c $(CFLAGS) $< -o $@

# Remove objects
clean :
	@$(RM) -rf $(ODIR)
	@echo "$(RED)	Removed objects	$(NC)"

# Remove all
fclean : clean
	@$(RM) -f $(NAME) $(BONUS)
	@$(RM) -rf $(NAME).dSYM

	@$(MAKE) fclean -C $(LDIR) -s
	@echo "$(RED)	Removed executablesand libft	$(NC)"

# Remake
re : fclean all

leak :
	echo "$(BLUE)	Checking leaks ...	$(NC)"
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=no --track-fds=no ./$(NAME) $(ARGS)

test:
	@echo $(INCLUDES)

visualizer:
	

.PHONY:
	clean fclean re test all directories