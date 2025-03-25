/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:39:58 by edubois-          #+#    #+#             */
/*   Updated: 2025/03/25 12:33:13 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	builtin_cd(t_data *data, int i, int pipe_fd[2])
{
	int	saved_std[2];

	if (ft_strcmp(data->cmd_list[i].cmd[0], "cd"))
	{
		data->cmd_list[i].builtin = 1;
		saved_std[0] = dup(STDIN_FILENO);
		saved_std[1] = dup(STDOUT_FILENO);
		manage_exec_dir(data, i);
		if (!data->cmd_list[i + 1].cmd)
		{
			if (pipe_fd[0] > 2)
				close(pipe_fd[0]);
			pipe_fd[1] = STDOUT_FILENO;
		}
		manage_pipe(data, pipe_fd);
		data->exit_status = cd(data, data->cmd_list[i].cmd);
		dup2(saved_std[0], STDIN_FILENO);
		dup2(saved_std[1], STDOUT_FILENO);
		close(saved_std[0]);
		close(saved_std[1]);
		if (data->exit_status == -1)
			exit_error(data, "failed malloc");
		return (1);
	}
	return (builtin_export(data, i, pipe_fd));
}

int	make_builtin(t_data *data, int i, int pipe_fd[2])
{
	int	saved_std[2];

	if (ft_strcmp(data->cmd_list[i].cmd[0], "exit"))
	{
		data->cmd_list[i].builtin = 1;
		saved_std[0] = dup(STDIN_FILENO);
		saved_std[1] = dup(STDOUT_FILENO);
		manage_exec_dir(data, i);
		if (!data->cmd_list[i + 1].cmd)
		{
			if (pipe_fd[0] > 2)
				close(pipe_fd[0]);
			pipe_fd[1] = STDOUT_FILENO;
		}
		manage_pipe(data, pipe_fd);
		ft_exit(data, i);
		dup2(saved_std[0], STDIN_FILENO);
		dup2(saved_std[1], STDOUT_FILENO);
		close(saved_std[0]);
		close(saved_std[1]);
		return (1);
	}
	return (builtin_cd(data, i, pipe_fd));
}
