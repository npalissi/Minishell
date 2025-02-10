/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:06:28 by edubois-          #+#    #+#             */
/*   Updated: 2025/02/10 16:08:32 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	merge_to_cmd(t_data *data, int j, int i)
{
	int	h;
	t_cmd tmp;

	tmp = data->cmd_list[i];
	h = 0;
	while (data->cmd_list[i].cmd[h])
		ft_strapp(&data->cmd_list[j].cmd, data->cmd_list[i].cmd[h++]);	
	while (data->cmd_list[++j].cmd)
		data->cmd_list[j] = data->cmd_list[j + 1];
	free(tmp.path);
}

void    parse_cmd(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = j + 1;
	while (data->cmd_list[i].cmd && data->cmd_list[i].cmd[0][0] != '|')
		merge_to_cmd(data, j, i);
}
































	
    // int i;
	// int	j;
	
	// data->tmp_fd = ft_calloc(nb_cmd(data) + 1, 4);
	// if (!data->tmp_fd)
	// 	return ;
	// i = 0;
	// j=  0;
	// while(data->cmd_list[i].cmd)
	// {
	// 	if (!data->cmd_list[i].path && access(data->cmd_list[i].cmd[0], F_OK) == -1)
	// 	{
	// 		data->tmp_fd[j] = create_tmp_file();
	// 		while (data->cmd_list[i].cmd && !data->cmd_list[i].path)
	// 		{
	// 			add_to_file(data->cmd_list[i], data->tmp_fd[j]);				
	// 			delete_cmd(data, i);
	// 		}
	// 	}
	// 	else if (!data->cmd_list[i].path && !access(data->cmd_list[i].cmd[0], F_OK))
	// 		{
	// 			data->tmp_fd[j++] = open(data->cmd_list[i].cmd[0], O_RDONLY , 0644);
	// 			delete_cmd(data, i);		
	// 		}
	// 	if (data->cmd_list[i].cmd)
	// 		i++;
	// }
