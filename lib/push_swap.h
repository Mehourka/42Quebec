/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:21:34 by kmehour           #+#    #+#             */
/*   Updated: 2023/05/26 10:00:03 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct		s_stack{
	int				val;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_data{
	t_stack			*a_stack;
	t_stack			*b_stack;
}					t_data;

void	init_stack(t_stack **stack, int argc, char* argv[]);
int		push_stack(t_stack **head, int val);
void	read_stack(t_stack *head);
void	free_stack(t_stack *head);

void	stack_arg(t_stack **head, char *arg);
void	raise_error();
void	ft_free_data();
t_data	*init_data();

void	sa();
void	sb();
void	ss();
void	pa();
void	pb();
void	ra();
void	rb();
void	rr();
void	rra();
void	rrb();
void	rrr();


// TESTING
void print_stacks();
//

#endif