/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgordag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:20:40 by mgordag           #+#    #+#             */
/*   Updated: 2022/08/17 15:20:42 by mgordag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "utils/libft.h"
# include "utils/get_next_line.h"
# include <math.h>
# include <stdio.h>
# include "mlx/mlx.h"

# define ON_KEYPRESS         2
# define ON_MOUSEPRESS       4
# define ON_MOUSERELEASE     5
# define ON_MOUSEMOVE        6
# define ON_DESTROY          17

typedef struct s_matrix
{
	float		x;
	float		y;
	float		z;
	int			is_last;

}	t_matrix;

typedef struct s_fdf
{
	double		angle_x;
	double		angle_y;
	double		angle_z;

	int			color;
	int			zoom;
	int			al_zoom;
	int			shift_x;
	int			shift_y;
	int			is_isometric;
	int			win_x;
	int			win_y;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*img;
	char		*addr;
	void		*mlx_ptr;
	void		*win_ptr;
	t_matrix	**map;
}				t_fdf;

t_matrix		**read_data(char *file_name);
void			create_image(t_fdf *data);
void			isometric(t_fdf *dot, double angle);
void			draw(t_fdf *data);
void			mlx_events(t_fdf *data);
void			rotation_op(t_matrix *coor_a, t_matrix *coor_b, t_fdf *data);
void			print_h(t_fdf data);
void			print_menu(t_fdf data);
float			ft_max(float num1, float num2);
float			ft_mod(float i);
int				key_hook(int key, t_fdf *data);
int				close_win(t_fdf *data);
int				ft_errors(int err_num);
unsigned long	color_op(int z1, int z2);
unsigned long	creatergb(int r, int g, int b);

#endif
