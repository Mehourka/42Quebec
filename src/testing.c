/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:16:29 by kmehour           #+#    #+#             */
/*   Updated: 2023/05/26 10:30:39 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void print_stacks(void)
{
	t_data *data;
	t_stack *aStack;
	t_stack *bStack;
	char *a;
	char *b;

	data = init_data();
	aStack = data->aStack;
	bStack = data->bStack;
	printf("\n A     B\n _______\n");
	while (aStack || bStack)
	{
		if (aStack)
		{
			a = ft_itoa(aStack->val);
			aStack = aStack->next;
		}
		else
			a = ft_strdup("_");
		if (bStack)
		{
			b = ft_itoa(bStack->val);
			bStack = bStack->next;
		}
		else
			b = ft_strdup("_");
		printf(" %s --- %s\n", a, b);
		free(a);
		free(b);
	}
	printf("\n\n");
}

void read_stack(t_stack *head)
{
	while (head)
	{
		printf("- %d\n", head->val);
		head = head->next;
	}
}
