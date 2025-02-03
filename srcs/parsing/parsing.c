/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:06:28 by edubois-          #+#    #+#             */
/*   Updated: 2025/02/03 17:25:26 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void    parse_command(t_data *data)
{
	int	i;

	i = 0;
	while (data->cmd_list[i].cmd)
	{
		if (!data->cmd_list[i].path && access(data->cmd_list[i].cmd[0], F_OK) == -1 && i == 0)
			
		
		if (!data->cmd_list[i].path && access(data->cmd_list[i].cmd[0], F_OK) == -1 && i != 0)
			ft_printf(2, "bash: command not found: %s\n", data->cmd_list[i].cmd[0]);
		i++;
	}
}