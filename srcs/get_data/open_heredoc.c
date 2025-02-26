/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42angouleme>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:40:02 by edubois-          #+#    #+#             */
/*   Updated: 2025/02/24 16:45:50 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	ft_strswap(t_data *data, int i, int j, char *from, char *to)
{
	char	*save;

	save = from;
	data->cmd_list[i].cmd[++j] = to;
	free(save);
}

int	create_here_doc(t_data *data)
{
    int i;
    int j;
	char *filename;
	char *delim;

	i = 0;
	while (data->cmd_list[i].cmd)
	{
		j = 0;
		filename = NULL;
		while (data->cmd_list[i].cmd[j])
		{
			filename = NULL;
			if (ft_strcmp("<<", data->cmd_list[i].cmd[j]) && data->cmd_list[i].cmd[j + 1])
			{
				filename = start_here_doc(data, data->cmd_list[i].cmd[j + 1]);
				delim = data->cmd_list[i].cmd[j + 1];
			}
			if (filename)
			{
				ft_strswap(data, i, j, delim, filename);
				filename = NULL;
			}
			else if (ft_strcmp("<<", data->cmd_list[i].cmd[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
