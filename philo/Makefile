# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/16 16:30:35 by kmehour           #+#    #+#              #
#    Updated: 2023/06/20 18:19:24 by kmehour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# life
# ARGS	=  2 410 200 200 # l
# ARGS	=  200 410 200 200 # l
ARGS	=  50 410 200 200 # d

# ARGS	=  2 200 100 100

NAME	=	philo

# Colors
GREEN	=	\033[0;32m
RED		=	\033[0;31m
BLUE	=	\033[0;34m
NC		=	\033[0m

# Directories
LIBDIR	=	lib/
INCDIR	=	include/
SRCDIR	=	src/
BONDIR	=	bonus_src/

# Libraries
INCLUDES=	-I $(INCDIR)
LIBS	=

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -g
CFLAGS +=	-fsanitize=thread
RM		=	rm

# Sources
SRCS	:=	main.c			\
			philo_time.c	\
			philo_init.c	\
			philo_memory.c	\
			philo_routines.c\
			philo_log.c\
			philo_parse.c\


B_SRCS	:=	$(SRCS:%=bonus_%)


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

all : $(NAME) bonus
	./bonus $(ARGS)

# Compile program
$(NAME) : $(LIBFT) $(OBJS)
	@echo "$(GREEN)	Compiling $@ ... $(NC)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME) -I. $(INCLUDES)

# Compile objects
$(OBJDIR)%.o : $(SRCDIR)%.c
	@mkdir -p $(OBJDIR);
	$(CC) -c $(CFLAGS) -MMD -MP $< -o $@ $(INCLUDES)

-include $(DEPS)

# Compile Bonus
bonus : $(B_OBJS)
	@echo "$(GREEN)	Compiling $@ ... $(NC)"
	$(CC) $(CFLAGS) $(B_OBJS) $(LIBS) -o $@ $(INCLUDES)

$(OBJDIR)%.o : $(BONDIR)%.c
	@mkdir -p $(OBJDIR);
	$(CC) -c $(CFLAGS) -MMD -MP $< -o $@ $(INCLUDES)

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
leak :
	echo "$(BLUE)	Checking leaks ...	$(NC)"
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=no --track-fds=no ./bonus $(ARGS)

.PHONY:
	all clean fclean re leak bonus