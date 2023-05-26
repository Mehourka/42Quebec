/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:16:17 by kmehour           #+#    #+#             */
/*   Updated: 2023/05/26 12:39:39 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **head)
{
	t_stack	*top;
	t_stack	*bot;

	if (!*head || !(*head)->next)
		return ;
	top = *head;
	bot = top->next;
	top->next = bot->next;
	bot->next = top;
	*head = bot;
}

void	sa(void)
{
	t_data	*data;

	data = init_data();
	swap(&data->a_stack);
	write(1, "sa\n", 3);
}

void	sb(void)
{
	t_data	*data;

	data = init_data();
	swap(&data->b_stack);
	write(1, "sb\n", 3);
}

void	ss(void)
{
	sa();
	sb();
}
