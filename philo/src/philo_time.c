/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:30:19 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/16 16:30:20 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void micro_sleep(useconds_t milliseconds)
{
	usleep(milliseconds * 1000);
}

/*Compute the time difference between two timevals in milliseconds*/
long int delta_ms(struct timeval start, struct timeval end)
{
	long int delta_s;
	long int delta_us;
	long int delta_ms;

	delta_s = end.tv_sec  - start.tv_sec;
	delta_us =  end.tv_usec - start.tv_usec;
	delta_ms = delta_s * 1000 + delta_us / 1000;
	return (delta_ms);
}

/*Gives the elapsed milliseconds since the first call to this function*/
long int get_ms_runtime()
{
	struct timeval curr_time;
	static struct timeval start_time = {0, 0};

	if (start_time.tv_sec == 0)
	{
		gettimeofday(&start_time, NULL);
	}
	gettimeofday(&curr_time, NULL);
	return (delta_ms(start_time, curr_time));
}