/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgordag <mgordag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:05:12 by mgordag           #+#    #+#             */
/*   Updated: 2022/09/03 13:06:50 by mgordag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_array_pivot(int *stack, int start, int size)
{
	unsigned long long	sum;
	int					i;

	sum = 0;
	i = 0;
	while (start < size)
	{
		sum += stack[start];
		start++;
		i++;
	}
	return (sum / i);
}

int	ft_min(int *stack, int start, int size)
{
	int	min;

	min = stack[start];
	while (start < size)
	{
		if (min > stack[start])
			min = stack[start];
		start++;
	}
	return (min);
}

int	ft_max(int *stack, int start, int size)
{
	int	max;

	max = stack[start];
	while (start < size)
	{
		if (max < stack[start])
			max = stack[start];
		start++;
	}
	return (max);
}

int	ft_isnum(char c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}
