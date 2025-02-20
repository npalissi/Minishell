/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:59:26 by edubois-          #+#    #+#             */
/*   Updated: 2025/02/20 18:59:56 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int    check_pipe(t_data *data, char *line)
{
    int i;

    i = 0;
    while (data->cmd_list[i].cmd && ((data->cmd_list[i].cmd[0][0] != '|')
		|| ((data->cmd_list[i].cmd[0][0] == '|') && (data->cmd_list[++i].cmd[0][0] != '|'))))
		i++;
	if (data->cmd_list[i].cmd && ft_charite(line, '|'))
	{
		ft_printf(2, "shellokitty: syntax error near \"|\"\n", NULL);
		return (1);
	}
	return (0);
}
