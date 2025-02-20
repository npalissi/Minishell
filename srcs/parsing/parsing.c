/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:06:28 by edubois-          #+#    #+#             */
/*   Updated: 2025/02/20 18:16:34 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void merge_to_cmd(t_data *data, int j, int i)
{
	int h;
	t_cmd tmp;

	tmp = data->cmd_list[i];
	h = 0;
	while (data->cmd_list[i].cmd[h])
		ft_strapp(&data->cmd_list[j].cmd, data->cmd_list[i].cmd[h++]);
	while (data->cmd_list[++j].cmd)
		data->cmd_list[j] = data->cmd_list[j + 1];
	free(tmp.path);
}

void parse_cmd(t_data *data)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (data->cmd_list[i].cmd)
	{
		if (data->cmd_list[j].cmd)
			i = j + 1;
		while (data->cmd_list[i].cmd && data->cmd_list[i].cmd[0] && data->cmd_list[i].cmd[0][0] != '|')
			merge_to_cmd(data, j, i);
		if (data->cmd_list[i].cmd && data->cmd_list[i].cmd[0][0] == '|' && !data->cmd_list[i + 1].cmd)
			break ;
		j = i + 1;
	}
}

int	add_error(int *error, int error_code)
{
	*error += error_code;
	return (1);
}

int	finish_check_error(t_data *data, int i, int j, int *error)
{
	if (ft_strcmp(data->cmd_list[i].cmd[j], ">>"))
	{
		if(!data->cmd_list[i].cmd[j + 1] && add_error(error, 2))
			ft_printf(2, "shellokitty: syntax error near \"<\"\n", NULL);
		else if (access(data->cmd_list[i].cmd[j + 1], F_OK) != -1 && access(data->cmd_list[i].cmd[j + 1], W_OK) == -1 && add_error(error, 1))
			ft_printf(2, "shellokitty: %s: %s: Permission denied \n", data->cmd_list[i].cmd[0], data->cmd_list[i].cmd[j + 1]);
	}
	else if(ft_strcmp(data->cmd_list[i].cmd[j], ">"))
	{
		if(!data->cmd_list[i].cmd[j + 1] && add_error(error, 2))
			ft_printf(2, "shellokitty: syntax error near \">\"\n", NULL);
	}
	return (1);
}

int	check_error(t_data *data, int i, int j, char *redir)
{
	int error;

	error = 0;
	if (!data->cmd_list[i].path)
		error = 127;
	else if (ft_strcmp(redir, "<"))
	{
		if(!data->cmd_list[i].cmd[j + 1] && add_error(&error, 2))
			ft_printf(2, "shellokitty: syntax error near \"<\"\n", NULL);
		else if(access(data->cmd_list[i].cmd[j + 1], F_OK) == -1 && add_error(&error, 1))
			ft_printf(2, "shellokitty: %s: %s: No such file or directory\n", data->cmd_list[i].cmd[0], data->cmd_list[i].cmd[j + 1]);
		else if (access(data->cmd_list[i].cmd[j + 1], R_OK) == -1 && add_error(&error, 1))
			ft_printf(2, "shellokitty: %s: %s: Permission denied \n", data->cmd_list[i].cmd[0], data->cmd_list[i].cmd[j + 1]);
	}
	else if(ft_strcmp(redir, "<<"))
	{
		if(!data->cmd_list[i].cmd[j + 1] && add_error(&error, 2))
			ft_printf(2, "shellokitty: syntax error near \"<<\"\n", NULL);
	}
	if (finish_check_error(data, i, j, &error) && error != 0)
	{
		destroy_here_doc(data);
		exit(error);
	}
	return (0);
}
