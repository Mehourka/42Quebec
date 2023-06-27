/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:30:12 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/23 12:16:17 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

void	*death_loop(void *arg);
void	*wait_children(void *arg);
void	create_children(t_data *data);
void	kill_children(t_data *data);

int	main(int argc, char *argv[])
{
	t_data		*data;
	pthread_t	watcher;

	data = get_data();
	if (!data)
		return (1);
	if (philo_init(data, argc, argv))
		return (1);
	create_children(data);
	pthread_create(&watcher, NULL, wait_children, data);
	pthread_join(watcher, NULL);
	free_tdata(data);
	return (0);
}

void	create_children(t_data *data)
{
	int			*pids;
	int			i;
	t_philo		*philo;

	pids = data->pids;
	i = 0;
	while (i < data->philo_count)
	{
		philo = &data->philosopher;
		get_start_tv();
		// gettimeofday(&philo->last_meal_tv, NULL);
		philo->last_meal_tv = get_start_tv();
		pids[i] = fork();

		philo->id = i + 1;

		if (pids[i] == 0)
		{
			philo_routine(philo);
			return ;
		}
		i++;
	}
}

void	*wait_children(void *arg)
{
	t_data		*data;
	int	i;
	int status;

	data = arg;
	i = 0;
	while (i < data->philo_count)
	{
		waitpid(0, &status, 0);
		i++;
		if(WIFEXITED(status))
		{
			if(WEXITSTATUS(status) != 0)
			{
				kill_children(data);
				break ;
			}
		}
	}
	return (NULL);
}

void	kill_children(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		kill(data->pids[i], SIGKILL);
		i++;
	}
}
