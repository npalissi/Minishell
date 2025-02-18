/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_dir_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:22:04 by edubois-          #+#    #+#             */
/*   Updated: 2025/02/18 11:16:57 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void    make_split(char **t, int i[2], int index[2], char ***tab)
{
    if (index[1])
	    ft_strapp(tab, ft_substr(t[i[0]], index[0],
	    	index[1] - index[0]));
	if (t[i[0]][index[1] + 1] == i[1])
	{
		index[1]++;
		ft_strapp(tab, ft_strndup(dup_char(i[1], 2), 2, 1));
	}
	else
		ft_strapp(tab, ft_strndup(dup_char(i[1], 1), 1, 1));
	index[0] = index[1] + 1;
}

char	**make_dir_split(char **t, int i[2], int index[2], int iq[2])
{
	char	**tab;

	tab = NULL;
	while (t && t[i[0]])
	{
		index[0] = 0;
		index[1] = 0;
		while (index[1] <= (int)ft_strlen(t[i[0]]) && t[i[0]][index[1]])
		{
			if (t[i[0]][index[1]] == '"' && iq[1] == 0 && ((i[0] == 0)
				|| (i[0] > 0 && t[i[0]][index[1] - 1] != '\\')))
				iq[0] = !iq[0];
			if (t[i[0]][index[1]] == '\'' && iq[0] == 0 && ((i[0] == 0)
				|| (i[0] > 0 && t[i[0]][index[1] - 1] != '\\')))
				iq[1] = !iq[1];
			if (t[i[0]][index[1]] == i[1] && !iq[0] && !iq[1])
                make_split(t, i, index, &tab);
			index[1]++;
		}
		if (index[0] != index[1])
			ft_strapp(&tab, ft_substr(t[i[0]], index[0], index[1] - index[0]));
		i[0]++;
	}
    return (tab);
}

char	**manage_dir(char **t, int c)
{
	char	**tab;
	int		i[2];
	int		index[2];
	int		iq[2];

	i[0] = 0;
    i[1] = c;
	iq[0] = 0;
	iq[1] = 0;
	index[0] = 0;
	index[1] = 0;
	tab = make_dir_split(t, i, index, iq);
	ft_free_tab(t);
	return (tab);
}
