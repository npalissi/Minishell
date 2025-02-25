/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:44:31 by npalissi          #+#    #+#             */
/*   Updated: 2025/02/24 11:02:54 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int cmd_unset(t_data *data, char **cmds)
{
	int i;
	i = 1;
	while(cmds[i])
		ms_remove_env(data, cmds[i++]);
	return (1);
}