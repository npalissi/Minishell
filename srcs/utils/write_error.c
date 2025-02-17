/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:46:21 by edubois-          #+#    #+#             */
/*   Updated: 2025/02/16 17:01:35 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	check_exec_error(t_data data)
{
   	int	i;

	i = 0;
	while(data.cmd_list[i].cmd)
	{
		if (data.cmd_list[i].cmd[0][0] == '|' && i++)
			continue ;
		if (!data.cmd_list[i].path)
			ft_printf(2, "Shellokitty: %s: command not found\n", data.cmd_list[i].cmd[0]);
		else if (access(data.cmd_list[i].path, X_OK) == -1)
			ft_printf(2, "Shellokitty: %s permision denied\n");
		i++;
	}
}
    