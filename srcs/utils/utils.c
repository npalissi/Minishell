/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:00:32 by edubois-          #+#    #+#             */
/*   Updated: 2025/03/19 11:27:23 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

char	*absolute_path(t_data *data, int j)
{
	struct stat	sb;
	char		*cmd;

	cmd = data->cmd_list[j].cmd[0];
	if (ft_strncmp(cmd, "./", 2) == 0)
	{
		if (stat(cmd, &sb) == 0 && (sb.st_mode & S_IXUSR))
			return (ft_strdup(cmd));
	}
	if (cmd[0] == '/')
	{
		if (stat(cmd, &sb) == 0 && (sb.st_mode & S_IXUSR))
			return (ft_strdup(cmd));
	}
	return (NULL);
}

int	check_for_cmd(t_data *data, int i)
{
	int	j;
	int	cmd_count;

	cmd_count = 0;
	j = 0;
	while (data->cmd_list[i].cmd && data->cmd_list[i].cmd[j])
	{
		if (ft_strchr("<>", data->cmd_list[i].cmd[j][0]) && j++)
			continue ;
		if ((data->cmd_list[i].cmd[j + 1]
				&& data->cmd_list[i].cmd[j + 1][0] != '<'
			&& data->cmd_list[i].cmd[j + 1][0] != '>')
			&& (j > 0 && (data->cmd_list[i].cmd[j - 1][0] != '>'
				&& data->cmd_list[i].cmd[j - 1][0] != '<')))
			cmd_count = 1;
		if (j > 0 && !data->cmd_list[i].cmd[j + 1]
			&& !ft_strchr("<>", data->cmd_list[i].cmd[j - 1][0]))
			cmd_count = 1;
		j++;
	}
	return (cmd_count);
}
