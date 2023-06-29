/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_philo_memory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:30:21 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/29 11:31:21 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

void	destroy_sem(t_data *data);

void	free_tdata(t_data *data)
{
	destroy_sem(data);
	free(data->pids);
	free(data);
}

void	destroy_sem(t_data *data)
{
	(void) data;
	sem_close(data->sema_forks);
	sem_close(data->write_sem);
	sem_unlink(FORKS_SEM);
	sem_unlink(WRITE_SEM);
}
