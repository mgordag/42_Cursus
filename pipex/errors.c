/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgordag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:07:16 by mgordag           #+#    #+#             */
/*   Updated: 2022/05/16 20:09:52 by mgordag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	sys_call_errors(int code)
{
	if (code == 2)
	{
		perror("An error occurred while opening the files");
		exit(code);
	}
	else if (code == 3)
	{
		perror("An error occurred during the pipe");
		exit(code);
	}
	else if (code == 4)
	{
		perror("An error occurred on fork");
		exit(code);
	}
	else if (code == 5)
	{
		perror("An error occurred while closing the files");
		exit(code);
	}
	else if (code == 7)
	{
		perror("An error occurred on dup2");
		exit(code);
	}
}

void	input_errors(int code)
{
	if (code == 1)
	{
		perror("Wrong input number");
		exit(code);
	}
	else if (code == 6)
	{
		perror("Wrong cmd input");
		exit(code);
	}
	else if (code == 8)
	{
		perror("An Error occurred on execve command");
		exit(code);
	}
}
