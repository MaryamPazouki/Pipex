/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki <mpazouki@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:45:42 by mpazouki          #+#    #+#             */
/*   Updated: 2024/12/19 16:45:48 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_pipex *data, char **envp)
{
	int		file_in;
	char	*cmd1_path;

	file_in = open(data->infile, O_RDONLY);
	if (file_in == -1)
		ft_error();
	dup2(data->pipefd[1], STDOUT_FILENO);
	dup2(file_in, STDIN_FILENO);
	close(file_in);
	close(data->pipefd[0]);
	close(data->pipefd[1]);
	cmd1_path = ft_find_path(data->cmd1, envp);
	if (!cmd1_path || execve(cmd1_path, data->cmd1, envp) == -1)
	{
		perror("Error executing command 1");
		exit(EXIT_FAILURE);
	}
}

void	parent_process(t_pipex *data, char **envp)
{
	int		file_out;
	char	*cmd2_path;

	file_out = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_out == -1)
		ft_error();
	dup2(data->pipefd[0], STDIN_FILENO);
	dup2(file_out, STDOUT_FILENO);
	close(file_out);
	close(data->pipefd[0]);
	close(data->pipefd[1]);
	cmd2_path = ft_find_path(data->cmd2, envp);
	if (!cmd2_path || execve(cmd2_path, data->cmd2, envp) == -1)
	{
		perror("Error executing command 2");
		exit(EXIT_FAILURE);
	}
}

void	ft_execute(t_pipex *data, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		child_process(data, envp);
	else
	{
		waitpid(pid, NULL, 0);
		parent_process(data, envp);
	}
}
