/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:13:15 by kmehour           #+#    #+#             */
/*   Updated: 2023/05/29 12:20:07 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort_three(void)
{
	t_data	*data;
	t_stack	*ptr;
	int		diff;
	int		size;

	data = init_data();
	ptr = data->astack;
	size = stack_len(data->astack);
	if (size > 3)
		return ;
	while (ptr->next)
	{
		diff = ptr->next->val - ptr->val;
		if (diff == -1)
		{
			sa();
			break ;
		}
		ptr = ptr->next;
	}
	if (data->astack->val == 3)
		ra();
	if (data->astack->val == 2)
		rra();
}

void	small_sort(void)
{
	t_data	*data;

	data = init_data();
	while (stack_len(data->astack) > 3)
	{
		if (data->astack->val > 3)
			pb();
		else
			ra();
	}
	sort_three();
	if (data->bstack && data->bstack->val == 5)
		sb();
	while (data->bstack)
	{
		pa();
		ra();
	}
}

int	is_sorted(t_stack *head)
{
	int	prev;

	prev = 0;
	while (head)
	{
		if (prev >= head->val)
			return (1);
		prev = head->val;
		head = head->next;
	}
	return (0);
}

int	count_bits(int nb)
{
	int	count;

	count = 0;
	while (nb >> count)
		count++;
	return (count);
}

void	radix_sort(void)
{
	t_data	*data;
	int		size;
	int		i;
	int		shift;

	shift = 0;
	data = init_data();
	size = stack_len(data->astack);
	while (shift < count_bits(stack_len(data->astack)))
	{
		i = 0;
		while (i < size)
		{
			if ((data->astack->val >> shift) & 1)
			{
				ra();
			}
			else
				pb();
			i++;
		}
		while (data->bstack)
			pa();
		shift++;
	}
}
