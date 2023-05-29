/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:16:31 by kmehour           #+#    #+#             */
/*   Updated: 2023/05/29 12:20:07 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include <stdio.h>

t_data	*init_data(void)
{
	static t_data	*data;

	if (!data)
	{
		data = malloc(sizeof(t_data));
		data->astack = NULL;
		data->bstack = NULL;
	}
	return (data);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = init_data();
	init_stack(&data->astack, argc, argv);
	index_stack(data->astack);
	if (is_sorted(data->astack) != 0)
	{
		if (stack_len(data->astack) <= 5)
			small_sort();
		else
			radix_sort();
	}
	ft_free_data();
}
