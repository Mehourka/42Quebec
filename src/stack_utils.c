/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:16:27 by kmehour           #+#    #+#             */
/*   Updated: 2023/05/26 10:22:46 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_stack(t_stack **head, int val)
{
	t_stack	*new;
	t_stack	*ptr;
	t_stack	*prev;

	new = malloc(sizeof(t_stack));
	new->val = val;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (0);
	}
	ptr = *head;
	while (ptr)
	{
		prev = ptr;
		if (ptr->val == val)
		{
			free(new);
			return (1);
		}
		ptr = ptr->next;
	}
	prev->next = new;
	return (0);
}

void	free_stack(t_stack *head)
{
	t_stack	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	ft_free_data(void)
{
	t_data	*data;

	data = init_data();
	free_stack(data->a_stack);
	free(data);
}
