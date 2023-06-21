/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:30:21 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/20 17:51:49 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

void	destroy_sem(t_data *data);

void	free_tdata(t_data *data)
{
	destroy_sem(data);
	free(data->philosophers);
	free(data);
}

void	destroy_sem(t_data *data)
{
	(void) data;
	sem_unlink(FORKS_SEM);
	sem_unlink(WRITE_SEM);
	sem_unlink(STATE_SEM);
}
