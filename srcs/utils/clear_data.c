/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42angouleme>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 08:18:34 by edubois-          #+#    #+#             */
/*   Updated: 2025/03/11 17:13:41 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	free_cmd(t_data *data)
{
	int i;
	int	j;
	int	len;

	i = 0;
	if (data->cmd_list)
	{
		while (data->cmd_list[i].cmd)
		{
			j = 0;
			len = ft_arraylen(data->cmd_list[i].cmd);
			while (j <= len && data->cmd_list[i].cmd[j])
			{
				if ((data->cmd_list[i].cmd[j][0] == '<' || data->cmd_list[i].cmd[j][0] == '>') && data->cmd_list[i].cmd[j + 1])
					j += 2;
				else
					free(data->cmd_list[i].cmd[j++]);
			}
			free(data->cmd_list[i].path);
			free(data->cmd_list[i++].cmd);
		}
		free(data->cmd_list);
	}
}

void    reset_data(t_data *data, char *rl)
{
	free(rl);
	free(data->pids);
	free_cmd(data);
}

void	free_cmd_here(t_data *data)
{
	int	i;

	i = 0;
	while (data->cmd_list[i].cmd)
	{
		ft_free_tab(data->cmd_list[i].cmd);
		free(data->cmd_list[i++].path);
	}
	free(data->cmd_list);
}

void	reset_data_here(t_data *data, char *line)
{
	free(data->pids);
	free(line);
	ft_free_tab(data->paths);
	free_cmd_here(data);
	ft_free_tab(data->here_doc_name);
}