/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:30:19 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/19 15:53:17 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void print_usage();
int	parse_uint(char *nb, u_int32_t *dest);
int	ft_isdigit(int c);

int parse_arguments(int argc, char *argv[], t_data *data)
{
	if (argc < MIN_ARG_NUM || argc > MAX_ARG_NUM)
	{
		print_usage(argv);
		return (1);
	}

	if(	
		parse_uint(argv[1], &data->philo_count) ||\
		parse_uint(argv[2], &(data->time_to.die)) ||\
		parse_uint(argv[3], &(data->time_to.eat)) ||\
		parse_uint(argv[4], &(data->time_to.sleep))
	)
	{
		print_usage(argv);
		return (1);
	}
	return (0);
}

/*
Checks if a string is a valid int, assigne it to pointed int on success

Paramters :
	- str : char string
	- dest : pointer to destination int variable

Retruns :
	0 if str represents a valid int
	1 otherwise
*/
int	parse_uint(char *nb, u_int32_t *dest)
{
	int	i;
	int result;

	i = 0;
	result = 0;
	if (!nb)
		return (1);
	if (!nb[i])
		return (1);
	while (nb[i])
	{
		if (!ft_isdigit(nb[i]))
			return (1);
		result = 10 * result + (nb[i] - '0');
		i++;
	}
	*dest = result;
	return (0);
}

void print_usage(char *argv[])
{
	printf("Usage :\n%s number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n", argv[0]);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
