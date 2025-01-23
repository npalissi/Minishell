/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:52:17 by edubois-          #+#    #+#             */
/*   Updated: 2025/01/23 15:13:59 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	clear_data(t_data data)
{
	int i;
	
	i = 0;
	ft_free_tab(data.paths);
	while (data.cmd_list && data.cmd_list[i].cmd)
	{
		ft_free_tab(data.cmd_list[i].cmd);
		free(data.cmd_list[i].path);
		i++;
	}
	free(data.cmd_list);
}

int	error_exit(t_data data, int sig, char *name)
{
	if (sig == 127)
	{
		ft_printf(2, "bash: command not found: %s\n", name);
		clear_data(data);
		exit (127);
	}
	if (sig == -1)
	{
		clear_data(data);
		exit(EXIT_FAILURE);
	}
	clear_data(data);
	exit(sig);
}