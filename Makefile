#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

OUT = /dev/stdout
# CMD = infile cat "grep Dog" $(OUT)
CMD = infile "ping -c 3 google.com" "wc -l" $(OUT)
INFILE = "Hello cats!\nHello Dog!\nHello World!"


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
CFLAGS	=	-g #-Wall -Werror -Wextra
CFLAGS +=	$(INCLUDES)
RM		=	rm

# Sources
SDIR	=	src/

SRCS	=	main.c\
			pipex_utils.c\
			pipex_checks.c\
			\
			\


# Objects
ODIR	=	obj/
OBJS	:=	$(SRCS:%.c=$(ODIR)%.o)

SRCS	:=	$(SRCS:%.c=$(SDIR)%.c)

#------------------------------------------------------------------------------#
#                                TARGETS                                       #
#------------------------------------------------------------------------------#

all : $(NAME)

exec : all
	@ echo $(INFILE)  > infile
	./$(NAME) $(CMD)

# Compile exec
$(NAME) :  $(HEADERS) $(LIBFT) $(OBJS)
	@echo "$(GREEN)	Compiling $(NAME)... $(NC)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) -I.

# Compile libft
$(LIBFT):
	@echo "$(BLUE)	Compiling libft ...	$(NC)"
	@$(MAKE) -C $(@D) -s

# Compile objects
$(ODIR)%.o : $(SDIR)%.c
	@mkdir -p $(ODIR);
	@$(CC) -c $(CFLAGS) $< -o $@

# Remove objects
clean :
	@$(RM) -rf $(ODIR)
	@$(RM) outfile infile
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
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=no --track-fds=no ./$(NAME) $(CMD)

test:
	@echo $(INCLUDES)

.PHONY:
	clean fclean re test all directories