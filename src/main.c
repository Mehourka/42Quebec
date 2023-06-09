#include "fractol.h"
#include <stdio.h>


int32_t	main(int argc, char *argv[])
{
	t_data	*data;
	// mlx_t	*mlx;

	data = init_data();
	// mlx = data->mlx;

	(void) argc;
	(void) argv;

	parse_arguments(argc, argv, data);
	// printf("%f", ft_atod("123.123456"));



	mlx_loop_hook(data->mlx, &keyboard_hooks, data);
	mlx_loop_hook(data->mlx, &mouse_hooks, data);


	mlx_loop_hook(data->mlx, data->frac_function, data);
	// // mlx_loop_hook(data->mlx, &julia_pthread, data);
	mlx_cursor_hook(data->mlx, &julia_mouse_control, data);

	mlx_loop(data->mlx);
	free_data();

	return (EXIT_SUCCESS);
}