/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgordag <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:12:27 by mgordag           #+#    #+#             */
/*   Updated: 2022/05/16 20:18:42 by mgordag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include<stdlib.h>
# include<stdio.h>
# include<unistd.h>
# include<fcntl.h>

typedef struct s_pipex
{
	char	**cmd_list;
	char	**path_list;
	char	*path;
	char	*cmd;
	int		infile;
	int		outfile;
	int		i;
	int		pipe_fd[2];
}	t_pipex;

char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*get_path(char **env);

void	input_errors(int code);
void	sys_call_errors(int code);

void	child_process2(t_pipex pipex, char **av, char **envp);
void	child_process(t_pipex pipex, char **av, char **envp);

void	free_child(t_pipex *pipex);
void	free_parent(t_pipex *pipex);

#endif
