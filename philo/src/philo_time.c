#include "philosophers.h"

void micro_sleep(useconds_t milliseconds)
{
	usleep(milliseconds * 1000);
}

/*Compute the time difference between two timevals in milliseconds*/
long int delta_ms(struct timeval start, struct timeval end)
{
	long int start_ms;
	long int end_ms;
	long int delta_ms;

	start_ms = start.tv_sec % 1000 * 1000 + start.tv_usec / 1000;
	end_ms =  end.tv_sec % 1000 * 1000 + end.tv_usec / 1000;
	delta_ms = end_ms - start_ms;
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