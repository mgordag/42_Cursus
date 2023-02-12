/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgordag <mgordag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:12:30 by mgordag           #+#    #+#             */
/*   Updated: 2022/09/03 13:12:33 by mgordag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	last_sort(t_push *data)
{
	if (data->stack_b[0] < data->stack_b[1])
		ft_swap(data, 'b');
	if (!is_sorted(data->stack_a, data->size_a, data->size))
		sort_three(data, data->size_a);
	while (data->size_b < 2)
		ft_push(data, 'a');
}

void	quicksort_five(t_push *data)
{
	int	pivot;

	pivot = ft_array_pivot(data->stack_a, data->size_a, data->size);
	while (data->size_b > 0)
	{
		if (data->stack_a[data->size_a] < pivot)
			ft_push(data, 'b');
		else
		{
			if (data->stack_a[data->size - 1] < pivot)
				ft_revrotate(data, 'a');
			else
				ft_rotate(data, 'a');
		}
	}
	last_sort(data);
}
