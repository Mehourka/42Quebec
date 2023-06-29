/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:50:59 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/29 10:29:36 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	ft_putnbr(long int number);
void	ft_putstr(char *string);

void	print_log(int philo_id, char *action)
{
	t_data		*data;

	data = get_data();
	pthread_mutex_lock(&data->write_mutex);
	if (!data->death)
	{
		printf("%li %d %s\n", get_ms_runtime(), philo_id, action);
	}
	pthread_mutex_unlock(&data->write_mutex);
}
