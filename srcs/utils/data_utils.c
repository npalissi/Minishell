/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:09:55 by edubois-          #+#    #+#             */
/*   Updated: 2025/02/04 15:22:04 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

// int nb_cmd(t_data *data)
// {
//     int	c;
// 	int	i;

// 	i = 0;
// 	c = 0;
// 	while (data->cmd_list[i++].cmd)
// 		c++;
// 	return (c);
// }

// void	add_to_file(t_cmd cmd,  int fd)
// {
// 	int	i;
	
// 	i = 0;
// 	while (cmd.cmd[i])
// 	{
// 		ft_putstr_fd(cmd.cmd[i++], fd);
// 		ft_putchar_fd(' ', fd);
// 	}
// }

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