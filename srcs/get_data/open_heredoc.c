/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:40:02 by edubois-          #+#    #+#             */
/*   Updated: 2025/03/17 17:59:50 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	ft_strswap(t_data *data, int i[2], char *from, char *to)
{
	char	*save;

	save = from;
	data->cmd_list[i[0]].cmd[++i[1]] = to;
	dh_free(save);
}

int	create_here_doc(t_data *data)
{
	int		i[2];
	char	*filename;
	char	*delim;

	i[0] = 0;
	while (data->cmd_list[i[0]].cmd)
	{
		i[1] = 0;
		filename = NULL;
		while (data->cmd_list[i[0]].cmd[i[1]])
		{
			filename = NULL;
			if (ft_strcmp("<<", data->cmd_list[i[0]].cmd[i[1]])
				&& data->cmd_list[i[0]].cmd[i[1] + 1])
			{
				filename = start_here_doc(data,
						data->cmd_list[i[0]].cmd[i[1] + 1]);
				delim = data->cmd_list[i[0]].cmd[i[1] + 1];
			}
			if (filename && access(filename, F_OK) == -1)
			{
				ft_printf(2, BOLD RED"/!\\ " BOLD BEIGE
					"Heredoc file deleted !\n" RESET);
				return (0);
			}
			if (filename)
			{
				ft_strswap(data, i, delim, filename);
				filename = NULL;
			}
			else if (ft_strcmp("<<", data->cmd_list[i[0]].cmd[i[1]]))
				return (0);
			i[1]++;
		}
		i[0]++;
	}
	return (1);
}
