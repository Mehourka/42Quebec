#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

NAME = pipex
LDIR	=	libft/
LIBFT	=	$(LDIR)/libft.a
IDIR	=	lib/
HEADERS	=	$(IDIR)/pipex.h \
			$(LDIR)/libft.h
INCLUDES= $(patsubst %, -I%, $(dir $(HEADERS)))

# Color
GREEN	=	\033[0;32m
RED		=	\033[0;31m
BLUE	=	\033[0;34m
NC		=	\033[0m

# Compiler and flags
CC		=	gcc
CFLAGS	=	#-Wall -Werror -Wextra
CFLAGS +=	$(INCLUDES)
RM		=	rm

# Sources
SDIR	=	src/

SRCS	=	main.c\
			pipex_utils.c\
			\
			\
			\


# Objects
ODIR	=	obj/
OBJS	:=	$(SRCS:%.c=$(ODIR)%.o)

SRCS	:=	$(SRCS:%.c=$(SDIR)%.c)

#------------------------------------------------------------------------------#
#                                TARGETS                                       #
#------------------------------------------------------------------------------#

all : directories $(NAME)
	@echo
	./$(NAME)

# Compile exec
$(NAME) : $(OBJS) $(INC) $(LIBFT) 
	@echo "$(GREEN)	Compiling $(NAME)... $(NC)" 
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) -I. 

# Compile libft
$(LIBFT): 
	@echo "$(BLUE)	Compiling libft ...	$(NC)"
	@$(MAKE) -C $(@D) -s

# Create directories
directories :
	@mkdir -p $(ODIR);

# Compile objects
$(ODIR)%.o : $(SDIR)%.c directories
	@$(CC) -c $(CFLAGS) $< -o $@

# Remove objects
clean :
	@$(RM) -rf $(ODIR)
	@echo "$(RED)	Removed objects	$(NC)"

# Remove all
fclean : clean
	@$(RM) -r $(NAME) 
	@$(MAKE) fclean -C $(LDIR) -s
	@echo "$(RED)	Removed executablesand libft	$(NC)"

# Remake
re : fclean all

leak :
	echo "$(BLUE)	Checking leaks ...	$(NC)"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

test:
	@echo $(INCLUDES)

.PHONY:
	clean fclean re test all directories