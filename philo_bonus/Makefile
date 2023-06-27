# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/16 16:30:35 by kmehour           #+#    #+#              #
#    Updated: 2023/06/23 12:12:48 by kmehour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# life
# ARGS	=  2 410 200 200 # l
# ARGS	=  200 410 200 200 # l
ARGS	=  2 410 200 100 2 # d

# ARGS	=  2 200 100 100

NAME	=	philo_bonus

# Colors
GREEN	=	\033[0;32m
RED		=	\033[0;31m
BLUE	=	\033[0;34m
NC		=	\033[0m

# Directories
LIBDIR	=	lib/
INCDIR	=	include/
SRCDIR	=	bonus_src/

# Libraries
INCLUDES=	-I $(INCDIR)
LIBS	=

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -O2
# CFLAGS +=	-fsanitize=thread -g
RM		=	rm

# Sources
SRCS	:=	main.c			\
			philo_time.c	\
			philo_init.c	\
			philo_memory.c	\
			philo_routines.c\
			philo_log.c\
			philo_parse.c\
			philo_checks.c


SRCS	:=	$(SRCS:%=bonus_%)


# Objects
OBJDIR	=	obj/
OBJS		:=	$(SRCS:%.c=$(OBJDIR)%.o)
SRCS		:=	$(SRCS:%.c=$(SRCDIR)%.c)
B_OBJS	:=	$(B_SRCS:%.c=$(OBJDIR)%.o)
B_SRCS		:=	$(B_SRCS:%=$(BONDIR)%)
DEPS		:=	$(OBJS:%.o=%.d)


#------------------------------------------------------------------------------#
#                                TARGETS                                       #
#------------------------------------------------------------------------------#

all : $(NAME)
#	./$(NAME) $(ARGS)

bonus : all

# Compile program
$(NAME) : $(LIBFT) $(OBJS)
	@echo "$(GREEN)	Compiling $@ ... $(NC)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME) -I. $(INCLUDES)

# Compile objects
$(OBJDIR)%.o : $(SRCDIR)%.c
	@mkdir -p $(OBJDIR);
	$(CC) -c $(CFLAGS) -MMD -MP $< -o $@ $(INCLUDES)

-include $(DEPS)

# Remove objects
clean :
	@$(RM) -rf $(OBJDIR)
	@$(RM) -rf $(NAME).dSYM
	@echo "$(RED)	Removed objects	$(NC)"

# Remove all
fclean : clean
	@$(RM) -f $(NAME) bonus
	@echo "$(RED)	Removed executables and libft	$(NC)"

# Remake
re : fclean all

# Valgrind leak check
leak : re
	echo "$(BLUE)	Checking leaks ...	$(NC)"
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --track-fds=no ./$(NAME) $(ARGS)

.PHONY:
	all clean fclean re leak bonus