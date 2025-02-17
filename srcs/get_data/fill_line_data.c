/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_line_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:56:25 by edubois-          #+#    #+#             */
/*   Updated: 2025/02/17 18:59:14 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

char *find_cmd_path(char **paths, char *word)
{
	char *tmp_path;
	char *tmp_path_bis;

	tmp_path = ft_strjoin(*paths, "/"); 
	tmp_path_bis = ft_strjoin(tmp_path, word);
	free(tmp_path);
	while (*++paths && access(tmp_path_bis, F_OK) == -1)
	{
	free(tmp_path_bis);
	tmp_path = ft_strjoin(*paths, "/"); 
	tmp_path_bis = ft_strjoin(tmp_path, word);
	free(tmp_path);
	}
	if (*paths)
		return (tmp_path_bis);
	free(tmp_path_bis);
	return (NULL);
}

static	void	fill_command(t_data *data, char **line)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	data->cmd_list = ft_calloc(ft_arraylen(line) + 1, sizeof(t_cmd));
	while (line[j] && data->cmd_list)
	{
		ft_strapp(&data->cmd_list->cmd, line[j]);
		if (!data->cmd_list->cmd)
			return ;
		if (line [j] && line[j + 1][0] == '-')
		{	
			ft_strapp(&data->cmd_list->cmd, line[j + 1]);
			if (!data->cmd_list->cmd) //a finir
				return ;
		}
		data->cmd_list[i].path = find_cmd_path(&data->cmd_list[i].cmd[0], data->cmd_list->cmd[0]);
	}
}

void    fill_line_data(t_data *data, char *line)
{
    char **full_line;

	full_line = ft_split(line, ' ');
	if (!full_line)
		return ;
	fill_command(data, full_line);
	add_history(line);
	free(line);
}