/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:46:21 by edubois-          #+#    #+#             */
/*   Updated: 2025/03/12 17:19:56 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	check_for_dir(t_data *data, int i)
{
	struct stat path_stat;
	int	valid;

	valid = 0;
    if (!stat(data->cmd_list[i].path, &path_stat))
		valid = S_ISDIR(path_stat.st_mode);
	if (valid)
		ft_printf(2, "Shellokitty: %s: Is a directory\n", data->cmd_list[i].cmd[0]);
	return (valid);
}


void	check_exec_error(t_data data)
{
	int	i;

	i = 0;
	while (data.cmd_list[i].cmd)
	{
		if (check_for_dir(&data, i))
			data.exit_status = 126;			
		else if (data.cmd_list[i].cmd[0][0] == '|' && i++)
			continue ;
		else if (!ft_strncmp(data.cmd_list[i].cmd[0], "./", 2)
			&& access(data.cmd_list[i].path, F_OK) == -1)
			ft_printf(2, "Shellokitty: %s: file not found\n",
				data.cmd_list[i].cmd[0]);
		else if (!data.cmd_list[i].path && !(ft_strchr("<>", data.cmd_list[i].cmd[0][0])))
			ft_printf(2, "Shellokitty: %s: command not found\n",
				data.cmd_list[i].cmd[0]);
		else if (access(data.cmd_list[i].path, X_OK) == -1 && !(ft_strchr("<>", data.cmd_list[i].cmd[0][0])))
			ft_printf(2, "Shellokitty: %s permision denied\n",
				data.cmd_list[i].cmd[0]);
		i++;
	}
}
