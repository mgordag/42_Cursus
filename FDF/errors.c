/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgordag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:20:19 by mgordag           #+#    #+#             */
/*   Updated: 2022/08/17 15:20:21 by mgordag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_errors(int err_num)
{
	if (err_num == 0)
		perror("Invalid arguments. Please type the name of the file");
	else if (err_num == 1)
		perror("file couldn't be opened");
	else if (err_num == 2)
		perror("Invalid data type. Program needs integer values");
	exit(err_num);
	return (0);
}
