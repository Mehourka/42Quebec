# include "philosophers.h"

long int delta_usec(struct timeval start, struct timeval end)
{
	long int delta_s;
	long int delta_u;

	delta_s = end.tv_sec - start.tv_sec;
	delta_u = end.tv_usec - start.tv_usec;
	delta_u += delta_s * 1000000;
	return (delta_u);
}

long int get_runtime()
{
	struct timeval curr_time;
	static struct timeval start_time = {0, 0};

	if (start_time.tv_sec == 0)
	{
		gettimeofday(&start_time, NULL);
	}

	gettimeofday(&curr_time, NULL);
	return (delta_usec(start_time, curr_time));
}

int main(void)
{
	int string_len = 5;
	char dest_string[string_len + 1];
	// struct timeval start_time;
	get_runtime();

	usleep(100);


	// gettimeofday(&start_time, NULL);

	memset(&dest_string, 'D', string_len);
	printf("String : %s\n", dest_string);

	printf("runtime : %li\n", get_runtime());

}