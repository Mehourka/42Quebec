#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

struct timeval {
	time_t		tv_sec;
	suseconds_t tv_usec;
};

# define STDOUT_FILENO 1
#endif