/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_philosophers.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:30:31 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/23 10:27:57 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_PHILOSOPHERS_H
# define BONUS_PHILOSOPHERS_H

# include <limits.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <pthread.h>
# include <semaphore.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>
# include <unistd.h>
# include <signal.h>

# define PHILO_COUNT 2
# define TIMETO_DIE 420
# define TIMETO_EAT 69
# define TIMETO_SLEEP 69

# define LOG_FORK "has taken a fork"
# define LOG_EAT "is eating"
# define LOG_SLEEP "is sleeping"
# define LOG_THINK "is thinking"

# define MIN_ARG_NUM 5
# define MAX_ARG_NUM 6

# define FORKS_SEM "/semaforks"
# define WRITE_SEM "/writesem"

typedef struct s_philo
{
	int					id;
	struct s_data		*data;
	struct timeval		last_meal_tv;

}						t_philo;

typedef struct s_data
{
	int					philo_count;
	int					meal_count;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	t_philo				philosopher;
	sem_t				*sema_forks;
	sem_t				*write_sem;
	int					*pids;
}						t_data;

// Initialisation
t_data					*get_data(void);
int						philo_init(t_data *data, int argc, char *argv[]);

// Time functions
long int				delta_ms(struct timeval statrt, struct timeval end);
long int				get_ms_runtime(void);
void					micro_sleep(long int milliseconds);
struct timeval			get_start_tv(void);
int64_t					get_tv_ms(struct timeval tv);

// Thread routines
void					*philo_routine(void *data);

// Logs
void					ft_putnbr(long int number);
void					ft_putstr(char *string);
void					print_log(int philo_id, char *action);

// Memory managment
void					free_tdata(t_data *data);

// Parsing
int						parse_arguments(int argc, char *argv[], t_data *data);
int						is_dead(t_philo *philo);

#endif