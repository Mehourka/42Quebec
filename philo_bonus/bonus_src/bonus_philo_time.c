/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_philo_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:30:19 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/29 11:30:45 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

/*Get the current time (aka micro seconds since Jan 1970)*/
long int	get_curr_us(void)
{
	struct timeval	curr;

	gettimeofday(&curr, NULL);
	return (curr.tv_sec * 1000000 + curr.tv_usec);
}

long int	get_start_us(void)
{
	static long int	start_time = 0;

	if (start_time == 0)
	{
		start_time = get_curr_us();
	}
	return (start_time);
}

/*Gives the elapsed milliseconds since the first call to this function*/
long int	get_ms_runtime(void)
{
	return ((get_curr_us() - get_start_us()) / 1000);
}

/*Compute the time difference between two timevals in milliseconds*/
long int	delta_ms(long int start_us, long int end_us)
{
	return ((end_us - start_us) / 1000);
}

void	micro_sleep(long int milliseconds)
{
	long int	target;

	target = get_ms_runtime() + milliseconds;
	usleep((milliseconds - 5) * 1000);
	while (get_ms_runtime() < target)
		usleep(5);
}
