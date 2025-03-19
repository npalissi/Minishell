/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:33:11 by edubois-          #+#    #+#             */
/*   Updated: 2025/03/19 11:18:03 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	collect_data(t_data *data)
{
	char	*path;
	char	**paths;

	path = getenv("PATH");
	paths = ft_split(path, ':');

	data->paths = paths;
	data->pwd = getenv("PWD");
}
