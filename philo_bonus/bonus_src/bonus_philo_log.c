/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_philo_log.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:50:59 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/23 12:18:11 by kmehour          ###   ########.fr       */
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
	printf("%li %d %s\n", get_ms_runtime(), philo_id, action);
	sem_post(data->write_sem);
}
