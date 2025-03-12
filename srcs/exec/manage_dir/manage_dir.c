/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:19:06 by edubois-          #+#    #+#             */
/*   Updated: 2025/03/12 14:27:29 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

void	clean_cmd(t_data *data)
{
	int	i;
	int	j;
	int h;
	int	save_j;
	char	*save_str[2];

	i = 0;
	while (data->cmd_list[i].cmd)
	{
		j = 0;
		while (data->cmd_list[i].cmd[j])
		{
			if (data->cmd_list[i].cmd[j][0] == '<' || data->cmd_list[i].cmd[j][0] == '>')
			{
				h = j + 1;
				save_j = j;
				save_str[0] = data->cmd_list[i].cmd[j];
				save_str[1] = data->cmd_list[i].cmd[j + 1];
				while (data->cmd_list[i].cmd[j])
					data->cmd_list[i].cmd[j++] = data->cmd_list[i].cmd[h++];
				j = save_j;
				h = save_j + 1;
				while (data->cmd_list[i].cmd[j])
					data->cmd_list[i].cmd[j++] = data->cmd_list[i].cmd[h++];
				dh_free(save_str[0]);
				dh_free(save_str[1]);
				j = save_j;
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
		clean_cmd(data);
		// printcmd(data);
	}
	data->here_doc_name = NULL;
}
