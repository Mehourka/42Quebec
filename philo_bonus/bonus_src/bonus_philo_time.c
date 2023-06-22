/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_philo_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:30:19 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/22 15:06:37 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

int64_t			get_tv_ms(struct timeval tv);

struct timeval	get_start_tv(void)
{
	static struct timeval	start_time;

	if (start_time.tv_sec == 0)
	{
		gettimeofday(&start_time, NULL);
	}
	return (start_time);
}

/*Gives the elapsed milliseconds since the first call to this function*/
long int	get_ms_runtime(void)
{
	struct timeval	curr_time;
	struct timeval	start_time;

	start_time = get_start_tv();
	gettimeofday(&curr_time, NULL);
	return (delta_ms(start_time, curr_time));
}

/*Compute the time difference between two timevals in milliseconds*/
long int	delta_ms(struct timeval start, struct timeval end)
{
	long int	delta_s;
	long int	delta_us;

	delta_s = end.tv_sec - start.tv_sec;
	delta_us = end.tv_usec - start.tv_usec;
	return (delta_s * 1000 + delta_us / 1000);
}

void	micro_sleep(useconds_t milliseconds)
{
	int64_t	target;

	target = get_ms_runtime() + milliseconds;
	usleep((milliseconds - 10) * 1000);
	while (get_ms_runtime() < target)
		usleep(50);
}

int64_t	get_tv_ms(struct timeval tv)
{
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
