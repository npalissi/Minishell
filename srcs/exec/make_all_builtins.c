/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_all_builtins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:32:12 by edubois-          #+#    #+#             */
/*   Updated: 2025/03/25 12:33:10 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	builtin_env(t_data *data, int i, int pipe_fd[2])
{
	int	saved_std[2];

	if (ft_strcmp(data->cmd_list[i].cmd[0], "env"))
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
		data->exit_status = 1;
		cmd_env(data);
		dup2(saved_std[0], STDIN_FILENO);
		dup2(saved_std[1], STDOUT_FILENO);
		close(saved_std[0]);
		close(saved_std[1]);
		return (1);
	}
	return (0);
}

int	builtin_echo(t_data *data, int i, int pipe_fd[2])
{
	int	saved_std[2];

	if (ft_strcmp(data->cmd_list[i].cmd[0], "echo"))
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
		echo(data->cmd_list[i].cmd);
		dup2(saved_std[0], STDIN_FILENO);
		dup2(saved_std[1], STDOUT_FILENO);
		close(saved_std[0]);
		close(saved_std[1]);
		data->exit_status = 0;
		return (1);
	}
	return (builtin_env(data, i, pipe_fd));
}

int	builtin_pwd(t_data *data, int i, int pipe_fd[2])
{
	int	saved_std[2];

	if (ft_strcmp(data->cmd_list[i].cmd[0], "pwd"))
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
		data->exit_status = pwd();
		dup2(saved_std[0], STDIN_FILENO);
		dup2(saved_std[1], STDOUT_FILENO);
		close(saved_std[0]);
		close(saved_std[1]);
		if (data->exit_status == -1)
			exit_error(data, "failed malloc");
		return (1);
	}
	return (builtin_echo(data, i, pipe_fd));
}

int	builtin_unset(t_data *data, int i, int pipe_fd[2])
{
	int	saved_std[2];

	if (ft_strcmp(data->cmd_list[i].cmd[0], "unset"))
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
		data->exit_status = cmd_unset(data, data->cmd_list[i].cmd);
		dup2(saved_std[0], STDIN_FILENO);
		dup2(saved_std[1], STDOUT_FILENO);
		close(saved_std[0]);
		close(saved_std[1]);
		if (data->exit_status == -1)
			exit_error(data, "failed malloc");
		return (1);
	}
	return (builtin_pwd(data, i, pipe_fd));
}

int	builtin_export(t_data *data, int i, int pipe_fd[2])
{
	int	saved_std[2];

	if (ft_strcmp(data->cmd_list[i].cmd[0], "export"))
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
		data->exit_status = export(data, data->cmd_list[i].cmd);
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
