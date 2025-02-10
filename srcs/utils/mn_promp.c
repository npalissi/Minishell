/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_promp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:56:55 by npalissi          #+#    #+#             */
/*   Updated: 2025/02/10 10:21:45 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

char *bt_prompt(t_data data)
{
	char	*prompt;
	char	*folder;
	char	*rl;

	prompt = "\e[1;32m➜  \e[1;36m";
	folder = ft_strrchr(data.pwd,'/') + 1;
	if (!folder)
		folder = "/";
	prompt = ft_strjoin(prompt,folder);
	prompt = ft_strjoinfree(prompt,"\e[0m ",FREE_S1);
	rl = readline(prompt);
	free(prompt);
	return (rl);
}