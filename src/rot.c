/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:16:21 by kmehour           #+#    #+#             */
/*   Updated: 2023/05/26 12:39:54 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rot(t_stack **head)
{
	t_stack	*first_elem;
	t_stack	*ptr;

	if (!(*head) || !(*head)->next)
		return ;
	first_elem = (*head);
	(*head) = (*head)->next;
	first_elem->next = NULL;
	ptr = (*head);
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = first_elem;
}

void	ra(void)
{
	t_data	*data;

	data = init_data();
	rot(&data->a_stack);
	write(1, "ra\n", 3);
}

void	rb(void)
{
	t_data	*data;

	data = init_data();
	rot(&data->b_stack);
	write(1, "rb\n", 3);
}

void	rr(void)
{
	ra();
	rb();
}
