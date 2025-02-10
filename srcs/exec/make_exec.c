/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:50:29 by edubois-          #+#    #+#             */
/*   Updated: 2025/02/10 17:51:11 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	close_all(t_data *data, int pipe_fd[2])
{
	if (pipe_fd[0] > 2)
		close(pipe_fd[0]);
	if (pipe_fd[1] > 2)
		close(pipe_fd[1]);
	if (data->fd_in > 2)
		close(data->fd_in);
	if (data->fd_out > 2)
		close(data->fd_out);
}

void	manage_pipe(t_data *data, int pipe_fd[2])
{
	int	pid_in;
	int	pid_out;

	pid_in = data->fd_in;
	pid_out = pipe_fd[1];
	if (dup2(pid_in, STDIN_FILENO) == -1)
	{
		close_all(data, pipe_fd);
		return ;
	}
	if (dup2(pid_out, STDOUT_FILENO) == -1)
	{
		close_all(data, pipe_fd);
		return ;
	}
	close_all(data, pipe_fd);
}

void    make_exec(t_data data, char *line)
{
	int	*pids;
	int i;
	int	pipe_fd[2];
	int exit_status;
			
	pids = ft_calloc(4 ,(ft_charite(line, '|')) + 1);
	if (!pids)
		return ;
	data.pids = pids;
	i = 0;
	while(data.cmd_list[i].cmd)
	{
		if (data.cmd_list[i].cmd && data.cmd_list[i + 1].cmd && data.cmd_list[i + 1].cmd[0][0] == '|' && pipe(pipe_fd) == -1)
			return ;
		pids[i] = fork();
		if (pids[i] == 0)
		{
			if (data.cmd_list[i + 1].cmd && data.cmd_list[i + 1].cmd[0][0] == '|')
				manage_pipe(&data, pipe_fd);
			execve(data.cmd_list[i].path, data.cmd_list[i].cmd, data.env);
			exit(127);
		}
		if (data.fd_in > 2)
			close(data.fd_in);
		if (pipe_fd[1] > 2)
			close(pipe_fd[1]);
		data.fd_in = pipe_fd[0];
		i++;
		if (data.cmd_list[i].cmd && data.cmd_list[i].cmd[0][0] == '|')
			i++;
	}
	i = 0;
	exit_status = 0;
	while (data.cmd_list[i].cmd)
	{
		waitpid(data.pids[i], &exit_status, 0);
		i++;
	}
	exit_status =  WEXITSTATUS(exit_status);
}

