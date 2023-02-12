/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgordag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:21:34 by mgordag           #+#    #+#             */
/*   Updated: 2022/08/17 15:21:36 by mgordag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_h(t_fdf data)
{
	mlx_string_put(data.mlx_ptr, data.win_ptr, 0, 0, creatergb(0, 255, 255),
		"To See Menu: Please Press 'h' key");
}

void	print_menu(t_fdf data)
{
	int	y;

	y = 0;
	mlx_string_put(data.mlx_ptr, data.win_ptr, 0, y, creatergb(0, 255, 255),
		"Move Image: 'w', 'a', 's', 'd' keys");
	mlx_string_put(data.mlx_ptr, data.win_ptr, 0, y += 20,
		creatergb(0, 255, 255), "Close Window: 'esc' or 'x' button");
	mlx_string_put(data.mlx_ptr, data.win_ptr, 0, y += 20,
		creatergb(0, 255, 255), "Zoom In: 'z' key");
	mlx_string_put(data.mlx_ptr, data.win_ptr, 0, y += 20,
		creatergb(0, 255, 255), "Zoom Out: 'x' key");
	mlx_string_put(data.mlx_ptr, data.win_ptr, 0, y += 20,
		creatergb(0, 255, 255), "Increase The Altitude: 'o' key");
	mlx_string_put(data.mlx_ptr, data.win_ptr, 0, y += 20,
		creatergb(0, 255, 255), "Decrease The Altitude: 'p' key");
	mlx_string_put(data.mlx_ptr, data.win_ptr, 0, y += 20,
		creatergb(0, 255, 255), "Rotate x: 'up','down' arrow keys");
	mlx_string_put(data.mlx_ptr, data.win_ptr, 0, y += 20,
		creatergb(0, 255, 255), "Rotate y: 'left','right' arrow keys");
	mlx_string_put(data.mlx_ptr, data.win_ptr, 0, y += 20,
		creatergb(0, 255, 255), "Rotate z: '1' and '2' keys");
	mlx_string_put(data.mlx_ptr, data.win_ptr, 0, y += 20,
		creatergb(0, 255, 255), "isometric or plain: 'i' and 'u' keys");
}
