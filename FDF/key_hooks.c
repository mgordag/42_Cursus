/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgordag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:20:57 by mgordag           #+#    #+#             */
/*   Updated: 2022/08/17 15:20:59 by mgordag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_hook3(int key, t_fdf *data)
{
	if (key == 1)
		data->shift_y += 10;
	else if (key == 13)
		data->shift_y -= 10;
	else if (key == 0)
		data->shift_x -= 10;
	else if (key == 2)
		data->shift_x += 10;
	else if (key == 32)
		data->is_isometric = 0;
	else if (key == 39)
		data->is_isometric = 1;
}

void	key_hook2(int key, t_fdf *data)
{
	if (key == 6)
		data->zoom += 5;
	else if (key == 7)
		data->zoom -= 5;
	else if (key == 31)
		data->al_zoom += 2;
	else if (key == 35)
		data->al_zoom -= 2;
	else if (key == 126)
		data->angle_y += 0.08;
	else if (key == 125)
		data->angle_y -= 0.08;
	else if (key == 124)
		data->angle_z += 0.08;
	else if (key == 123)
		data->angle_z -= 0.08;
	else if (key == 18)
		data->angle_x += 0.08;
	else if (key == 19)
		data->angle_x -= 0.08;
	else if (key == 53)
		close_win(data);
	else
		key_hook3(key, data);
}

int	key_hook(int key, t_fdf *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	if (key == 11)
	{
		data->angle_x = 0.3;
		data->angle_y = 0.3;
		data->angle_z = 0.3;
		data->shift_x = data->win_x / 2 - data->zoom * 15;
		data->shift_y = data->win_y / 2 - data->zoom * 15;
	}
	else if (key == 4)
	{
		print_menu(*data);
		return (0);
	}
	else
		key_hook2(key, data);
	draw(data);
	return (0);
}
