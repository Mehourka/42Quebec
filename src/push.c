/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:16:19 by kmehour           #+#    #+#             */
/*   Updated: 2023/05/29 12:20:07 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*new_src;

	if (!*src)
		return ;
	new_src = (*src)->next;
	(*src)->next = (*dest);
	*dest = *src;
	*src = new_src;
}

void	pa(void)
{
	t_data	*data;

	data = init_data();
	push(&data->bstack, &data->astack);
	write(1, "pa\n", 3);
}

void	pb(void)
{
	t_data	*data;

	data = init_data();
	push(&data->astack, &data->bstack);
	write(1, "pb\n", 3);
}
