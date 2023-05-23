#include "push_swap.h"
#include <stdio.h>

t_data *init_data()
{
	static t_data	*data;

	if (!data)
	{
		data = malloc(sizeof(t_data));
		data->a_stack = NULL;
	}
	return data;
}

void ft_free_data()
{
	t_data *data;

	data = init_data();

	free_stack(data->a_stack);
	free(data);
}

int main(int argc, char *argv[])
{
	// t_stack **pile;
	t_data *data;

	data = init_data();
	// pile = &data->a_stack;


	(void) argv;
	(void) argc;

	printf("Pushing to stack\n");
	init_stack(&data->a_stack, argc, argv);
	printf("Reading stack\n");
	read_stack(data->a_stack);
	printf("Freeing data\n");
	// free_stack(data->a_stack);

	ft_free_data();

}