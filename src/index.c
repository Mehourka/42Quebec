/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:51:31 by kmehour           #+#    #+#             */
/*   Updated: 2023/05/26 11:13:38 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_array(t_stack *head, int *arr)
{
	t_stack	*ptr;
	int		i;

	i = 0;
	ptr = head;
	while (ptr)
	{
		arr[i] = ptr->val;
		ptr = ptr->next;
		i++;
	}
}

static int	stack_len(t_stack *head)
{
	t_stack	*ptr;
	int		arr_size;

	arr_size = 0;
	ptr = head;
	while (ptr)
	{
		ptr = ptr->next;
		arr_size++;
	}
	return (arr_size);
}

void	sort_array(int *arr, int arr_size)
{
	int	swap;
	int	i;
	int	tmp;

	swap = 1;
	if (arr_size < 2)
		return ;
	while (swap)
	{
		i = 0;
		swap = 0;
		while (i < (arr_size - 1))
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				swap = 1;
			}
			i++;
		}
	}
}

int	*get_sorted_array(t_stack *head)
{
	int	arr_size;
	int	*arr;

	arr_size = stack_len(head);
	if (arr_size == 0)
		return (NULL);
	arr = malloc(sizeof(int) * arr_size);
	if (arr == NULL)
		return (NULL);
	init_array(head, arr);
	sort_array(arr, arr_size);
	return (arr);
}

void	index_stack(t_stack *head)
{
	int	i;
	int	*arr;

	arr = get_sorted_array(head);
	while (head)
	{
		i = 0;
		while (head->val != arr[i])
			i++;
		head->val = i + 1;
		head = head->next;
	}
}
