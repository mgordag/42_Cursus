/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgordag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:20:30 by mgordag           #+#    #+#             */
/*   Updated: 2022/08/17 15:20:32 by mgordag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_events(t_fdf *data)
{
	mlx_hook(data->win_ptr, ON_KEYPRESS, 0, &key_hook, data);
	mlx_hook(data->win_ptr, ON_DESTROY, 0, &close_win, data);
}

void	set_default(t_fdf *data)
{
	data->zoom = 20;
	data->al_zoom = -5;
	data->is_isometric = 1;
	data->angle_x = 0.3;
	data->angle_y = 0.3;
	data->angle_z = 0.3;
	data->win_x = 1200;
	data->win_y = 800;
	data->shift_x = 0;
	data->shift_y = 0;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_x,
			data->win_y, "FDF BY ADO");
}

int	main(int ac, char **av)
{
	t_fdf	data;

	if (ac != 2)
	{
		ft_errors(0);
	}
	data.map = read_data(av[1]);
	set_default(&data);
	draw(&data);
	mlx_events(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
