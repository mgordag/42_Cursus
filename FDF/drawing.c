/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgordag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:20:07 by mgordag           #+#    #+#             */
/*   Updated: 2022/08/17 15:20:12 by mgordag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	shift_op(t_matrix *coor_a, t_matrix *coor_b, t_fdf *data)
{
	coor_a->x += data->shift_x;
	coor_a->y += data->shift_y;
	coor_b->x += data->shift_x;
	coor_b->y += data->shift_y;
}

void	zoom_op(t_matrix *coor_a, t_matrix *coor_b, t_fdf *data)
{
	coor_a->x *= data->zoom;
	coor_a->y *= data->zoom;
	coor_b->x *= data->zoom;
	coor_b->y *= data->zoom;
	coor_a->z *= data->al_zoom;
	coor_b->z *= data->al_zoom;
}

void	operations(t_matrix *coor_a, t_matrix *coor_b, t_fdf *data)
{
	zoom_op(coor_a, coor_b, data);
	if (data->is_isometric)
		rotation_op(coor_a, coor_b, data);
	shift_op(coor_a, coor_b, data);
}

void	line(t_matrix coor_a, t_matrix coor_b, t_fdf *data)
{
	float	max;
	float	step_x;
	float	step_y;
	int		z1;
	int		z2;

	z1 = coor_a.z;
	z2 = coor_b.z;
	operations(&coor_a, &coor_b, data);
	step_x = coor_b.x - coor_a.x;
	step_y = coor_b.y - coor_a.y;
	max = ft_max(ft_mod(step_x), ft_mod(step_y));
	step_x /= max;
	step_y /= max;
	data->color = color_op(z1, z2);
	while ((int)(coor_a.x - coor_b.x) || (int)(coor_a.y - coor_b.y))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr,
			coor_a.x, coor_a.y, data->color);
		coor_a.x += step_x;
		coor_a.y += step_y;
	}
}

void	draw(t_fdf *data)
{
	int	y;
	int	x;

	print_h(*data);
	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (1)
		{
			if (data->map[x + 1])
				line(data->map[x][y], data->map[x + 1][y], data);
			if (!data->map[x][y].is_last)
				line(data->map[x][y], data->map[x][y + 1], data);
			else
				break ;
			y++;
		}
		x++;
	}
}
