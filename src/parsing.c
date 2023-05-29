/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:16:25 by kmehour           #+#    #+#             */
/*   Updated: 2023/05/29 11:35:49 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	raise_error(void)
{
	write(2, "Error\n", 6);
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
	if (long_atoi(nb) > INT_MAX || long_atoi(nb) < INT_MIN)
		return (1);
	if (nb[0] == '-' || nb[0] == '+')
		i++;
	if (!nb[i])
		return (1);
	while (nb[i])
	{
		if (!ft_isdigit(nb[i]))
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
