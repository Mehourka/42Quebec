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

void rot_sort(void)
{
	t_data *data;
	int a_min;

	data = init_data();
	a_min = 1;
	if (is_sorted(data->aStack) == 0)
		return;

	while (data->aStack)
	{
		while (data->aStack->val != a_min)
		{
			ra();
		}
		pb();
		a_min++;
	}
	while (data->bStack)
		pa();
}

int is_sorted(t_stack *head)
{
	int prev;

	prev = 0;
	while(head)
	{
		if (prev >= head->val)
			return (1);
		prev = head->val;
		head = head->next;
	}
	return (0);
}

int count_bits(int nb)
{
	int count;

	count = 0;
	while (nb >> count)
		count++;
	return count;
}

void radix_sort(void)
{
	t_data *data;

	int size;
	int val;
	int i;
	int shift;
	shift = 0;

	data = init_data();
	size = stack_len(data->aStack);
	// while(data->bStack || is_sorted(data->aStack) != 0)
	while(shift < count_bits(stack_len(data->aStack)))
	{
		i = 0;
		while(i < size)
		{
			val = data->aStack->val;
			if ((val>>shift)&1)
			{
				ra();
			}
			else
				pb();
			i++;
		}
		while(data->bStack)
			pa();
		shift++;
	}
}
