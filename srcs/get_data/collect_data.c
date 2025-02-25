/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:33:11 by edubois-          #+#    #+#             */
/*   Updated: 2025/02/10 16:08:28 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void    collect_data(t_data *data)
{
    char *path;
    char **paths;

    path = getenv("PATH");
    paths = ft_split(path, ':');
	if (!paths)
		error_exit(*data, -1, NULL);
	data->paths = paths;
	data->pwd = getenv("PWD");
}
