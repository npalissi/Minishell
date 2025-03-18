/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:39:58 by edubois-          #+#    #+#             */
/*   Updated: 2025/03/18 13:24:40 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	make_builtin(t_data *data, int *i)
{
	if (ft_strcmp(data->cmd_list[*i].cmd[0], "exit"))
	{
		(*i)++;
		ft_exit(data);
		return (1);	
	}
	return (0);
}