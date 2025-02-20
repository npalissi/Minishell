/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:19:06 by edubois-          #+#    #+#             */
/*   Updated: 2025/02/20 22:16:59 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	clean_cmd(t_data *data)
{
	int	i;
	int	j;
	int	save_j[2];
	char	*save_str[2];

	i = 0;
	while (data->cmd_list[i].cmd)
	{
		j = 0;
		while (data->cmd_list[i].cmd[j])
		{
			if (data->cmd_list[i].cmd[j][0] == '<' || data->cmd_list[i].cmd[j][0] == '>')
			{
				save_j[0] = j;
				save_str[0] = data->cmd_list[i].cmd[j];
				save_str[1] = data->cmd_list[i].cmd[j + 1];
				save_j[1] = --j;
				while (data->cmd_list[i].cmd[++j])
					data->cmd_list[i].cmd[j] = data->cmd_list[i].cmd[j + 1];
				while (data->cmd_list[i].cmd[++save_j[1]])
					data->cmd_list[i].cmd[save_j[1]] = data->cmd_list[i].cmd[save_j[1] + 1];
				free(save_str[0]);
				free(save_str[1]);
				j = save_j[0];
			}
			else 
				j++;
		}
		i++;
	}
}

void manage_exec_dir(t_data *data, int i)
{
	int	j;

	j = 0;
	if (data->cmd_list[i].cmd)
	{
		while (data->cmd_list[i].cmd[j])
		{
			if (ft_strcmp(data->cmd_list[i].cmd[j], "<") && !check_error(data, i, j, "<"))
				data->redir_fd[0] = open(data->cmd_list[i].cmd[j + 1], O_RDONLY);
			else if (ft_strcmp(data->cmd_list[i].cmd[j], "<<") && !check_error(data, i, j, "<<"))
				data->redir_fd[0] = open(data->cmd_list[i].cmd[j + 1], O_RDONLY, 0644);
			else if (ft_strcmp(data->cmd_list[i].cmd[j], ">") && !check_error(data, i, j, ">"))
				data->redir_fd[1] = open(data->cmd_list[i].cmd[j + 1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
			else if (ft_strcmp(data->cmd_list[i].cmd[j], ">>") && !check_error(data, i, j, ">>"))
				data->redir_fd[1] = open(data->cmd_list[i].cmd[j + 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
			j++;
		}
		j = 0;
		// printcmd(data);
		clean_cmd(data);
	}
	data->here_doc_name = NULL;
}
