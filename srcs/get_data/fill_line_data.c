/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_line_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:56:25 by edubois-          #+#    #+#             */
/*   Updated: 2025/02/03 17:10:42 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	fill_paths(t_data *data)
{
	char *tmp_path;
	char *tmp_path_bis;
	int		i;
	int		j;

	j = -1;
	while (data->cmd_list[++j].cmd)
	{
		i = 0;
		tmp_path = ft_strjoin(data->paths[i], "/"); 
		tmp_path_bis = ft_strjoinfree(tmp_path, data->cmd_list[j].cmd[0], 1);
		while (data->paths[++i] && access(tmp_path_bis, F_OK) == -1)
		{
			free(tmp_path_bis);
			tmp_path = ft_strjoin(data->paths[i], "/");
			tmp_path_bis = ft_strjoinfree(tmp_path, data->cmd_list[j].cmd[0], 1);
		}
		if (data->paths[i])
			data->cmd_list[j].path = tmp_path_bis;
		else
		{
			free(tmp_path_bis);
			data->cmd_list[j].path = NULL;
		}
	}
}

int	fill_flags(t_data *data, char **line, int i, int j)
{
	int c_flags;

	c_flags = 1;
	while (line[++j] && line[j][0] == '-')
	{
		ft_strapp(&data->cmd_list[i].cmd, line[j]);
		c_flags++;
		if (!data->cmd_list[i].cmd)
			return (0);
	}
	return (c_flags);
}

// void	printcmd(t_data *data)
// {
// 	int	 i = 0;
// 	int j = 0;
// 	while (data->cmd_list[i].cmd)
// 	{
// 		j = 0;
// 		while (data->cmd_list[i].cmd[j])
// 		{
// 			printf("data->cmd_list[%d]->cmd[%d] = %s\n", i, j , data->cmd_list[i].cmd[j]);
// 			j++;
// 		}
// 		printf("%s\n", data->cmd_list[i].path);
// 		printf("\n\n\n\n\n\n", NULL);
// 		i++;
// 	}
// }

void	fill_command(t_data *data, char **line)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	data->cmd_list = ft_calloc(ft_arraylen(line) + 1, sizeof(t_cmd));
	while (line[j] && data->cmd_list)
	{
		ft_strapp(&data->cmd_list[i].cmd, line[j]);
		if (!data->cmd_list->cmd)
			return ;
		j += fill_flags(data, line, i, j);
		i++;
	}
}

void    fill_line_data(t_data *data, char *line)
{
    char **full_line;

	full_line = ft_split(line, ' ');
	if (!full_line)
		return ;
	fill_command(data, full_line);
	fill_paths(data);
	// printcmd(data);
	add_history(line);
	//exec
	parse_command(data);
	free(line);
}