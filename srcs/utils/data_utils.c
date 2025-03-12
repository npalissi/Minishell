/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:09:55 by edubois-          #+#    #+#             */
/*   Updated: 2025/03/12 14:27:29 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	delete_cmd(t_data *data, int i)
{
	t_cmd	cmd_tmp;

	cmd_tmp = data->cmd_list[i];
	while (data->cmd_list[i].cmd)
	{
		data->cmd_list[i] = data->cmd_list[i + 1];
		i++;
	}
	ft_free_tab(cmd_tmp.cmd);
	dh_free(cmd_tmp.path);
}

void	fill_exec_path(t_data *data)
{
	int	i;

	i = 0;
	while (data->cmd_list[i].cmd)
	{
		if (!ft_strncmp(data->cmd_list[i].cmd[0], "./", 2))
		{
			data->cmd_list[0].path = ft_strjoin(getenv("PWD"), "/");
			data->cmd_list[0].path = ft_strjoinfree(data->cmd_list[0].path,
					data->cmd_list[0].cmd[0] + 2, 1);
		}
		i++;
	}
}

void	fill_data(t_data *data, char **full_line, char *line)
{
	fill_command(data, full_line);
	sort_cmd(data);
	dh_free(full_line);
	fill_paths(data);
	fill_exec_path(data);
	// printcmd(data);
	data->redir_fd[0] = 0;
	data->redir_fd[1] = 0;
	add_history(line);
}
