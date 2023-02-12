/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgordag <mgordag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:40:05 by mgordag           #+#    #+#             */
/*   Updated: 2022/09/03 13:40:44 by mgordag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_errors(int err_num)
{
	if (err_num == 0)
		write(1, "Wrong characters on argument", 28);
	else if (err_num == 1)
		write(1, "Equal values on stack!!!", 24);
	else if (err_num == 2)
		write(1, "Error occurred on malloc", 24);
	else if (err_num == 3)
		write(1, "Input is less than integer min value", 36);
	else if (err_num == 4)
		write(1, "Input is higher than integer max value", 38);
	exit(err_num);
}
