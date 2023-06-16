#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo_times{
	long int	die;
	long int	eat;
	long int	sleep;
	long int	think;
}	t_philo_times;

typedef struct s_data{
	u_int32_t		philo_count;
	pthread_t		*philo_threads;
	t_philo_times	time_to;
}	t_data;


// Initialisation
t_data			*philo_init(void);

// Time functions
long int		delta_ms(struct timeval statrt, struct timeval end);
long int		get_ms_runtime(void);
void			micro_sleep(useconds_t milliseconds);

// Thread functions

// Memory managment
void		free_tdata(void);

# define STDOUT_FILENO 1
#endif