/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_mlx_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:32:32 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/14 12:55:53 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_fractol.h"

void	free_data(void)
{
	t_data	*data;

	data = init_data();
	mlx_terminate(data->mlx);
	free(data);
}

void	ft_error(void)
{
	if (mlx_errno)
	{
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	free_data();
	exit(EXIT_FAILURE);
}
