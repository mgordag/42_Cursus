/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgordag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:53:50 by mgordag           #+#    #+#             */
/*   Updated: 2022/05/16 20:20:42 by mgordag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_cmd(t_pipex pipex, char *cmd, char **envp)
{
	char	*command;

	pipex.i = -1;
	pipex.path = get_path(envp);
	pipex.path_list = ft_split(pipex.path, ':');
	while (pipex.path_list[++pipex.i])
	{
		command = ft_strjoin(pipex.path_list[pipex.i], cmd);
		if ((access(command, X_OK) == 0))
			return (command);
		free(command);
	}
	return (NULL);
}

char	*get_path(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		if (env[i][0] == 'P' && env[i][2] == 'T')
			return (env[i]);
	return (0);
}

void	child_process(t_pipex pipex, char **av, char **envp)
{
	int	a;

	a = dup2(pipex.infile, 0);
	if (a == -1)
		sys_call_errors(7);
	a = dup2(pipex.pipe_fd[1], 1);
	if (a == -1)
		sys_call_errors(7);
	a = close(pipex.pipe_fd[0]);
	if (a == -1)
		sys_call_errors(5);
	pipex.cmd_list = ft_split(av[2], ' ');
	pipex.cmd = get_cmd(pipex, pipex.cmd_list[0], envp);
	if (!pipex.cmd)
	{
		free_child(&pipex);
		input_errors(6);
	}
	a = execve(pipex.cmd, pipex.cmd_list, envp);
	if (a == -1)
		input_errors(8);
}

void	child_process2(t_pipex pipex, char **av, char **envp)
{
	int	a;

	a = dup2(pipex.pipe_fd[0], 0);
	if (a == -1)
		sys_call_errors(7);
	a = close(pipex.pipe_fd[1]);
	if (a == -1)
		sys_call_errors(5);
	a = dup2(pipex.outfile, 1);
	if (a == -1)
		sys_call_errors(7);
	pipex.cmd_list = ft_split(av[3], ' ');
	pipex.cmd = get_cmd(pipex, pipex.cmd_list[0], envp);
	if (!pipex.cmd)
	{
		free_child(&pipex);
		input_errors(6);
	}
	a = execve(pipex.cmd, pipex.cmd_list, envp);
	if (a == -1)
		input_errors(8);
}
