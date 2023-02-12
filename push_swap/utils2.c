/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgordag <mgordag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:01:19 by mgordag           #+#    #+#             */
/*   Updated: 2022/09/03 13:02:09 by mgordag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_movecount(int start, int size, int index)
{
	if (index == start)
		return (0);
	if (index - start <= (size - start) / 2)
		return (index - start);
	return (index - size);
}

int	ft_get_totalmove(t_push *data, int index, int *index_a)
{
	int	count;

	*index_a = ft_array_minidx(data->stack_a, data->size_a,
			data->size, data->stack_b[index]);
	count = ft_abs(ft_get_movecount(data->size_b, data->size - 3, index));
	count += ft_abs(ft_get_movecount(data->size_a, data->size, *index_a));
	return (count);
}

int	ft_array_minidx(int *stack, size_t begin, size_t size, int start)
{
	int		min;
	size_t	i;

	i = begin - 1;
	while (++i < size)
	{
		if (stack[i] > start)
		{
			min = i;
			break ;
		}
	}
	while (++i < size)
		if (stack[i] > start && stack[i] < stack[min])
			min = i;
	return (min);
}
