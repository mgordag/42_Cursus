/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgordag <mgordag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:42:48 by mgordag           #+#    #+#             */
/*   Updated: 2022/09/03 13:45:30 by mgordag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	control_data(char **av)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = 0;
	while (av[++i])
	{
		j = 0;
		while (av[i][j])
		{
			j += ft_atoi(&av[i][j]);
			if (av[i][j] || ft_isnum(av[i][0]) || ft_isnum(av[i][j - 1]))
				size++;
		}
	}
	return (size);
}

void	is_equal(t_push *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->size)
	{
		j = i + 1;
		while (j < data->size)
		{
			if (data->temp_list[i] == data->temp_list[j])
			{
				free(data->temp_list);
				ft_errors(1);
			}
			j++;
		}
	}
}

int	is_sorted(int *stack, int start, int size)
{
	while (start < size - 1)
	{
		if (stack[start] > stack[start + 1])
			return (0);
		start++;
	}
	return (1);
}
