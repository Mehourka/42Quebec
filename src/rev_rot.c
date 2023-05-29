/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:16:23 by kmehour           #+#    #+#             */
/*   Updated: 2023/05/29 12:20:07 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rot(t_stack **head)
{
	t_stack	*first_elem;
	t_stack	*ptr;

	if (!(*head) || !(*head)->next)
		return ;
	first_elem = (*head);
	while ((*head)->next)
	{
		ptr = (*head);
		*head = (*head)->next;
	}
	(*head)->next = first_elem;
	ptr->next = NULL;
}

void	rra(void)
{
	t_data	*data;

	data = init_data();
	rev_rot(&data->astack);
	write(1, "rra\n", 4);
}

void	rrb(void)
{
	t_data	*data;

	data = init_data();
	rev_rot(&data->bstack);
	write(1, "rrb\n", 4);
}

void	rrr(void)
{
	rra();
	rrb();
}
