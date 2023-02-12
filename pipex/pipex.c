/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgordag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:27:15 by mgordag           #+#    #+#             */
/*   Updated: 2022/05/16 20:11:59 by mgordag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_child(t_pipex *pipex)
{
	pipex->i = -1;
	while (pipex->cmd_list[++pipex->i])
		free(pipex->cmd_list[pipex->i]);
	free(pipex->cmd_list);
	free(pipex->cmd);
}

void	free_parent(t_pipex *pipex)
{
	int	a;

	a = close(pipex->infile);
	if (a == -1)
		sys_call_errors(5);
	a = close(pipex->outfile);
	if (a == -1)
		sys_call_errors(5);
	a = close(pipex->pipe_fd[0]);
	if (a == -1)
		sys_call_errors(5);
	a = close(pipex->pipe_fd[1]);
	if (a == -1)
		sys_call_errors(5);
}

void	pipex_func(t_pipex pipex, char **av, char **envp)
{
	pid_t		pid1;
	pid_t		pid2;

	if (pipe(pipex.pipe_fd) == -1)
		sys_call_errors(3);
	pid1 = fork();
	if (pid1 == 0)
		child_process(pipex, av, envp);
	pid2 = fork();
	if (pid2 == 0)
		child_process2(pipex, av, envp);
	if (pid1 == -1 || pid2 == -1)
		sys_call_errors(4);
	free_parent(&pipex);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	if (ac != 5)
		input_errors(1);
	pipex.infile = open(av[1], O_RDONLY);
	pipex.outfile = open(av[4], O_CREAT | O_TRUNC | O_RDWR, 0000644);
	if (pipex.infile == -1 || pipex.outfile == -1)
		sys_call_errors(2);
	pipex_func(pipex, av, envp);
	return (0);
}
