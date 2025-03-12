/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:00:32 by edubois-          #+#    #+#             */
/*   Updated: 2025/03/12 14:27:29 by edubois-         ###   ########.fr       */
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