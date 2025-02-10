/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:09:55 by edubois-          #+#    #+#             */
/*   Updated: 2025/02/10 16:08:46 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	delete_cmd(t_data *data, int i)
{
	t_cmd	cmd_tmp;

	cmd_tmp = data->cmd_list[i];
	while (data->cmd_list[i].cmd)
	{
		data->cmd_list[i] = data->cmd_list[i + 1];
		i++;
	}
	free(cmd_tmp.path);
}