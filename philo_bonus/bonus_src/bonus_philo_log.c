/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:50:59 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/20 17:51:04 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

void	ft_putnbr(long int number);
void	ft_putstr(char *string);

void	print_log(int philo_id, char *action)
{
	t_data		*data;

	data = get_data();
	sem_wait(data->write_sem);
	if (!data->death)
	{
		printf("%li ms %d %s", get_ms_runtime(), philo_id, action);
	}
	sem_post(data->write_sem);
}

void	ft_putnbr(long int number)
{
	char	c;

	if (number > 9)
		ft_putnbr(number / 10);
	c = number % 10 + '0';
	write(1, &c, 1);
}

void	ft_putstr(char *string)
{
	if (!string)
		return ;
	while (*string)
	{
		write(1, string, 1);
		string++;
	}
}