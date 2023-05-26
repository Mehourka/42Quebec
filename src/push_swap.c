/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:16:31 by kmehour           #+#    #+#             */
/*   Updated: 2023/05/26 11:15:55 by kmehour          ###   ########.fr       */
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
		data->a_stack = NULL;
		data->b_stack = NULL;
	}
	return (data);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = init_data();
	printf("Pushing to stack\n");
	init_stack(&data->a_stack, argc, argv);
	printf("Indexing stack\n");
	index_stack(data->a_stack);
	printf("Reading stacks\n");
	print_stacks();
	ra();
	sa();
	rra();
	print_stacks();
	printf("Freeing data\n");
	ft_free_data();
}
