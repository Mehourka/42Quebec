/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:21:34 by kmehour           #+#    #+#             */
/*   Updated: 2023/05/29 12:20:07 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				val;
	struct s_stack	*next;
}					t_stack;

typedef struct s_data
{
	t_stack		*astack;
	t_stack		*bstack;
}				t_data;

void		init_stack(t_stack **stack, int argc, char *argv[]);
int			push_stack(t_stack **head, int val);
void		read_stack(t_stack *head);
void		free_stack(t_stack *head);
void		stack_arg(t_stack **head, char *arg);
void		raise_error(void);
void		ft_free_data(void);
t_data		*init_data(void);
void		index_stack(t_stack *head);
int			stack_len(t_stack *head);
void		rot_sort(void);
void		sa(void);
void		sb(void);
void		ss(void);
void		pa(void);
void		pb(void);
void		ra(void);
void		rb(void);
void		rr(void);
void		rra(void);
void		rrb(void);
void		rrr(void);
void		radix_sort(void);
int			is_sorted(t_stack *head);
void		small_sort(void);
long int	long_atoi(const char *str);
#endif