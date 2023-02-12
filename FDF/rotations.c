/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgordag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:21:45 by mgordag           #+#    #+#             */
/*   Updated: 2022/08/17 15:21:51 by mgordag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_x(float *y, float *z, double angle_x)
{
	float	previous_y;

	previous_y = *y;
	*y = previous_y * cos(angle_x) + *z * sin(angle_x);
	*z = -previous_y * sin(angle_x) + *z * cos(angle_x);
}

static void	rotate_y(float *x, float *z, double angle_y)
{
	float	previous_x;

	previous_x = *x;
	*x = previous_x * cos(angle_y) + *z * sin(angle_y);
	*z = -previous_x * sin(angle_y) + *z * cos(angle_y);
}

static void	rotate_z(float *x, float *y, double angle_z)
{
	float	previous_x;
	float	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(angle_z) - previous_y * sin(angle_z);
	*y = previous_x * sin(angle_z) + previous_y * cos(angle_z);
}

void	rotation_op(t_matrix *coor_a, t_matrix *coor_b, t_fdf *data)
{
	rotate_x(&coor_a->y, &coor_a->z, data->angle_x);
	rotate_y(&coor_a->x, &coor_a->z, data->angle_y);
	rotate_z(&coor_a->x, &coor_a->y, data->angle_z);
	rotate_x(&coor_b->y, &coor_b->z, data->angle_x);
	rotate_y(&coor_b->x, &coor_b->z, data->angle_y);
	rotate_z(&coor_b->x, &coor_b->y, data->angle_z);
}
