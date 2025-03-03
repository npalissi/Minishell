/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42angouleme>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:46:21 by edubois-          #+#    #+#             */
/*   Updated: 2025/03/03 13:36:52 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	check_exec_error(t_data data)
{
	int	i;

	i = 0;
	while (data.cmd_list[i].cmd)
	{
		if (data.cmd_list[i].cmd[0][0] == '|' && i++)
			continue ;
		if (!ft_strncmp(data.cmd_list[i].cmd[0], "./", 2)
			&& access(data.cmd_list[i].path, F_OK) == -1)
			ft_printf(2, "Shellokitty: %s: file not found\n",
				data.cmd_list[i].cmd[0]);
		else if (!data.cmd_list[i].path)
			ft_printf(2, "Shellokitty: %s: command not found\n",
				data.cmd_list[i].cmd[0]);
		else if (access(data.cmd_list[i].path, X_OK) == -1)
			ft_printf(2, "Shellokitty: %s permision denied\n",
				data.cmd_list[i].cmd[0]);
		i++;
	}
}
