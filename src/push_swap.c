#include "push_swap.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	t_data *data;

	data = init_data();


	printf("Pushing to stack\n");
	init_stack(&data->a_stack, argc, argv);

	printf("Reading stacks\n");
	print_stacks();

	sa();
	pb();
	pb();
	pb();
	rr();
	rrr();
	sa();
	pa();
	pa();
	pa();
	
	print_stacks();


	printf("Freeing data\n");
	ft_free_data();
}