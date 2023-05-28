/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:16:31 by kmehour           #+#    #+#             */
/*   Updated: 2023/05/26 13:26:02 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_data	*init_data(void)
{
	static t_data	*data;

	if (!data)
	{
		data = malloc(sizeof(t_data));
		data->aStack = NULL;
		data->bStack = NULL;
	}
	return (data);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = init_data();
	printf("Pushing to stack\n");
	init_stack(&data->aStack, argc, argv);
	printf("Stack length : %d\n", stack_len(data->aStack));
	printf("Indexing stack\n");
	index_stack(data->aStack);
	// printf("Reading stacks\n");
	// print_stacks();

	printf("Sorting ...\n");
	radix_sort();
	// print_stacks();
	// printf("Freeing data\n");
	ft_free_data();

}
