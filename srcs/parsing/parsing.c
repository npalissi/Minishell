/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:06:28 by edubois-          #+#    #+#             */
/*   Updated: 2025/02/19 11:15:04 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void merge_to_cmd(t_data *data, int j, int i)
{
	int h;
	t_cmd tmp;

	tmp = data->cmd_list[i];
	h = 0;
	while (data->cmd_list[i].cmd[h])
		ft_strapp(&data->cmd_list[j].cmd, data->cmd_list[i].cmd[h++]);
	while (data->cmd_list[++j].cmd)
		data->cmd_list[j] = data->cmd_list[j + 1];
	free(tmp.path);
}

void parse_cmd(t_data *data)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (data->cmd_list[i].cmd)
	{
		if (data->cmd_list[j].cmd)
			i = j + 1;
		while (data->cmd_list[i].cmd && data->cmd_list[i].cmd[0] && data->cmd_list[i].cmd[0][0] != '|')
			merge_to_cmd(data, j, i);
		j = i + 1;
	}
}
