/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 22:02:11 by edubois-          #+#    #+#             */
/*   Updated: 2025/03/12 16:49:03 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	check_all_error(t_data *data, int i, int j, int error)
{
	if (!data->cmd_list[i].cmd[j + 1] && add_error(data, i, &error, 2))
	{
		ft_printf(2, "shellokitty: syntax error near \"<\"\n", NULL);
		data->exit_status = 2;
	}
	else if (access(data->cmd_list[i].cmd[j + 1], F_OK) == -1
		&& add_error(data, i, &error, 1))
	{
		ft_printf(2, "shellokitty: %s: %s: No such file or directory\n",
			data->cmd_list[i].cmd[0], data->cmd_list[i].cmd[j + 1]);
			data->exit_status = 1;
	}	
	else if (access(data->cmd_list[i].cmd[j + 1], R_OK) == -1
		&& add_error(data, i, &error, 1))
	{
		ft_printf(2, "shellokitty: %s: %s: Permission denied \n",
			data->cmd_list[i].cmd[0], data->cmd_list[i].cmd[j + 1]);
		data->exit_status = 1;
	}
}
