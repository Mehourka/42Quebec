/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:30:19 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/29 08:54:34 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long int		get_tv_ms(struct timeval tv);
long int		get_curr_us(void);

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

/*Get the current time (aka micro seconds since Jan 1970)*/
long int get_curr_us(void)
{
	struct timeval curr;

	gettimeofday(&curr, NULL);
	return (curr.tv_sec * 1000000 + curr.tv_usec);
}

void	micro_sleep(long int milliseconds)
{
	long int	target;

	target = get_curr_us() + milliseconds * 1000;
	usleep((milliseconds - 1) * 1000);
	while (get_curr_us() < target)
		usleep(50);
}

long int	get_tv_ms(struct timeval tv)
{
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
