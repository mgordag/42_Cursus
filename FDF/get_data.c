/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgordag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:20:48 by mgordag           #+#    #+#             */
/*   Updated: 2022/08/17 15:20:50 by mgordag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	control_data(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if ((line[i] <= '0' || line[i] >= '9') && (line[i] != ' '
				|| line[i] == '-'))
			return (0);
	}
	return (1);
}

int	wd_counter(char *line)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (line[++i])
	{
		if (line[i] != ' ' && line[i] != '-')
			count++;
	}
	return (count - 1);
}

t_matrix	**mem_allocation(int y_dim, char *filename)
{
	t_matrix	**new;
	char		*line;
	int			fd;
	int			x_dim;

	fd = open(filename, O_RDONLY, 0);
	if (fd == -1)
		ft_errors(1);
	line = get_next_line(fd);
	x_dim = wd_counter(line);
	while (line != NULL)
	{
		if (control_data(line))
			ft_errors(2);
		free(line);
		y_dim++;
		line = get_next_line(fd);
	}
	free(line);
	new = (t_matrix **)malloc(sizeof(t_matrix *) * (y_dim + 1));
	while (y_dim > 0)
		new[--y_dim] = (t_matrix *)malloc(sizeof(t_matrix) * (x_dim + 1));
	close(fd);
	return (new);
}

void	assign_values(t_matrix **new, char *line, int y)
{
	char	**nums;
	int		x;

	nums = ft_split(line, ' ');
	x = -1;
	while (nums[++x])
	{
		new[y][x].z = ft_atoi(nums[x]);
		new[y][x].x = x;
		new[y][x].y = y;
		new[y][x].is_last = 0;
		free(nums[x]);
	}
	free(nums);
	free(line);
	new[y][--x].is_last = 1;
}

t_matrix	**read_data(char *filename)
{
	t_matrix	**new;
	char		*line;
	int			fd;
	int			y;
	int			y_dim;

	y_dim = 0;
	new = mem_allocation(y_dim, filename);
	fd = open(filename, O_RDONLY, 0);
	if (fd < 0)
		ft_errors(1);
	line = get_next_line(fd);
	y = 0;
	while (1)
	{
		assign_values(new, line, y);
		y++;
		line = get_next_line(fd);
		if (line == NULL)
			break ;
	}
	free(line);
	new[y] = NULL;
	close(fd);
	return (new);
}
