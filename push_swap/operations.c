/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgordag <mgordag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:28:49 by mgordag           #+#    #+#             */
/*   Updated: 2022/09/03 13:28:51 by mgordag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_op(int *stack, int index, int num)
{
	stack[index] = num;
}

void	reverse_op(int *stack, int start, int size)
{
	int	temp;

	while (start < size)
	{
		temp = stack[start];
		stack[start] = stack[size - 1];
		stack[size - 1] = temp;
		start++;
	}
}

void	swap_op(int *stack, int size)
{
	int	temp;

	temp = stack[size];
	stack[size] = stack[size + 1];
	stack[size + 1] = temp;
}

void	rotate_op(int *stack, int start, int size)
{
	int	temp;

	while (start < size)
	{
		temp = stack[size - 1];
		stack[size - 1] = stack[start];
		stack[start] = temp;
		size--;
	}
}
