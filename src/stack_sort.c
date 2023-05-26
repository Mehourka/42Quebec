/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:13:15 by kmehour           #+#    #+#             */
/*   Updated: 2023/05/26 13:39:54 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	rot_sort(void)
{
	t_data	*data;
	int		a_min ;

	data = init_data();
	a_min = 1;
	while (data->a_stack)
	{
		while (data->a_stack->val != a_min)
		{
			ra();
		}
		pb();
		a_min++;
	}
	while (data->b_stack)
		pa();
}
