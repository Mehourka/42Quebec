/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:16:25 by kmehour           #+#    #+#             */
/*   Updated: 2023/05/26 11:10:39 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	raise_error(void)
{
	printf("Error\n");
	ft_free_data();
	exit(1);
}

void	init_stack(t_stack **stack, int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		stack_arg(stack, argv[i]);
		i++;
	}
}

/*
Returns
	0 : if str represents valid int
	1 : otherwise
*/
int	int_check(char *nb)
{
	int	i;

	i = 0;
	while (nb[i])
	{
		if (!ft_isdigit(nb[i]) && !ft_strchr("+-", nb[i]))
			return (1);
		i++;
	}
	return (0);
}

void	stack_arg(t_stack **head, char *arg)
{
	char	**tab;
	int		i;
	int		val;

	i = 0;
	tab = ft_split(arg, ' ');
	while (tab[i])
	{
		val = ft_atoi(tab[i]);
		if (int_check(tab[i]) || push_stack(head, val))
		{
			ft_free_tab(tab);
			raise_error();
		}
		i++;
	}
	ft_free_tab(tab);
}
