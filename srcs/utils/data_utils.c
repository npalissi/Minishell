/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:09:55 by edubois-          #+#    #+#             */
/*   Updated: 2025/02/20 18:38:37 by edubois-         ###   ########.fr       */
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
	free(cmd_tmp.path);
}

void	fill_data(t_data *data, char **full_line, char *line)
{
		fill_command(data, full_line);
		fill_paths(data);
		parse_cmd(data);
		data->redir_fd[0] = 0;
		data->redir_fd[1] = 0;
		// printcmd(data);
		add_history(line);
}