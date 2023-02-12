/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgordag <mgordag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:29:21 by mgordag           #+#    #+#             */
/*   Updated: 2022/09/03 13:34:22 by mgordag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_indexed(t_push *data, int min, int index)
{
	int	i;

	i = -1;
	while (++i < data->size)
	{
		if (min == data->temp_list[i])
		{
			data->stack_a[i] = index;
			data->temp_list[i] = MAX_INT;
			break ;
		}
	}
	if (++index < data->size)
		make_indexed(data, ft_min(data->temp_list, 0, data->size), index);
}

void	assign_values(char **av, t_push *data)
{
	int	i;
	int	minus;
	int	j;
	int	k;

	data->temp_list = (int *)malloc(sizeof(int) * data->size);
	if (!data->temp_list)
		ft_errors(2);
	i = 0;
	k = 0;
	minus = 1;
	while (av[++i])
	{
		j = 0;
		while (av[i][j])
		{
			j += ft_atoi_real(&av[i][j], &data->temp_list[k], minus);
			if (av[i][j] || ft_isnum(av[i][0]) || ft_isnum(av[i][j - 1]))
				k++;
		}
	}
	data->stack_a = (int *)malloc(sizeof(int) * data->size);
	data->stack_b = (int *)malloc(sizeof(int) * (data->size - 3));
	if (!data->stack_a || !data->stack_a)
		ft_errors(2);
}

int	main(int ac, char **av)
{
	t_push	data;
	int		index;

	if (ac > 1)
	{
		index = 0;
		data.size = control_data(av);
		data.size_a = 0;
		data.size_b = data.size - 3;
		assign_values(av, &data);
		is_equal(&data);
		if (is_sorted(data.temp_list, 0, data.size))
		{
			free(data.temp_list);
			exit(5);
		}
		make_indexed(&data, ft_min(data.temp_list, 0, data.size), index);
		free(data.temp_list);
		ft_sort(&data);
	}
	return (0);
}
