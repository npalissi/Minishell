/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:00:32 by edubois-          #+#    #+#             */
/*   Updated: 2025/03/13 15:21:16 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	ft_strapp_off(char ***tab, char *str, int offset)
{
	char	**tmp;
	char	**save_tab;
	int		i;

	if (tab)
		save_tab = *tab;
	tmp = ft_calloc((ft_arraylen(*tab) + 2), sizeof(char *));
	if (!tmp)
		return ;
	i = 0;
	while (save_tab && save_tab[i])
	{
		tmp[i] = save_tab[i];
		i++;
	}
	tmp[i] = str;
	if (offset > 0)
		dh_free(*(tab - offset));
	else
		dh_free(*tab);
	*tab = tmp;
}

int	check_for_cmd(t_data *data, int i)
{
	int j;
	int	error;

	error = 0;
	j = 0;
	while (data->cmd_list[i].cmd && data->cmd_list[i].cmd[j])
	{
		if ((data->cmd_list[i].cmd[j + 1] && data->cmd_list[i].cmd[j + 1][0] != '<' && data->cmd_list[i].cmd[j + 1][0] != '>') && (j > 0 && (data->cmd_list[i].cmd[j - 1][0] != '>' && data->cmd_list[i].cmd[j - 1][0] != '<')))
			error = 1;	
		j++;
	}
	return (error);
}
