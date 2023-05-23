/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:21:34 by kmehour           #+#    #+#             */
/*   Updated: 2023/05/19 14:27:06 by kmehour          ###   ########.fr       */
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
	int				data;
	struct s_stack	*next;
}					t_stack;

void	push_stack(t_stack **head, int val);
void	read_stack(t_stack *head);
void	free_stack(t_stack *head);
void	stack_arg(t_stack **head, char *arg);
void	init_stack(t_stack **stack, int argc, char* argv[]);

#endif