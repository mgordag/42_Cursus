/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgordag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:21:20 by mgordag           #+#    #+#             */
/*   Updated: 2022/08/17 15:21:27 by mgordag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_mod(float i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}

float	ft_max(float num1, float num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}

unsigned long	color_op(int z1, int z2)
{
	if (z1 > 0 || z2 > 0)
		return (creatergb(0, 255, 0));
	else if (z1 < 0 || z2 < 0)
		return (creatergb(255, 0, 0));
	return (creatergb(255, 255, 255));
}

unsigned long	creatergb(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}
