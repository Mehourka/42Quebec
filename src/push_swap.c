#include "push_swap.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	t_data *data;

	data = init_data();


	printf("Pushing to stack\n");
	init_stack(&data->a_stack, argc, argv);

	printf("Reading stacks\n");
	read_stack(data->a_stack);
	// print_stacks();

	printf("Freeing data\n");
	ft_free_data();

}