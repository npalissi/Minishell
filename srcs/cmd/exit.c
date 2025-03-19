/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:03:03 by edubois-          #+#    #+#             */
/*   Updated: 2025/03/19 16:31:04 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	ft_exit_message_only(t_data *data, int i)
{
	int	arraylen;
	int	error[2];
	int	exit_code[2];

	arraylen = ft_arraylen(data->cmd_list[i].cmd);
	error[0] = 0;
	error[1] = 0;
	if (arraylen > 1)
	{
		exit_code[0] = str_to_long(data->cmd_list[i].cmd[1], &error[0]);
		if (arraylen == 3)
			exit_code[1] = str_to_long(data->cmd_list[i].cmd[2], &error[1]);
	}
	else
		return ;
	if (arraylen >= 3 && !error[0])
		ft_printf(2, BOLD BEIGE
			"Shellokitty: exit: too many arguments\n" RESET);
	else if (error[0])
		ft_printf(2, BOLD RED "/!\\ "
			BOLD BEIGE "Shellokitty: exit: %s: numeric argument required\n"
			RESET, data->cmd_list[i].cmd[1]);
}

void	ft_exit(t_data *data, int i)
{
	int	exit_code[2];
	int	error[2];
	int	arraylen;

	if (i)
		return (ft_exit_message_only(data, i));
	arraylen = ft_arraylen(data->cmd_list[0].cmd);
	error[0] = 0;
	error[1] = 0;
	if (arraylen > 3)
	{
		ft_printf(2, BOLD RED "Exit\n/!\\ "
			BOLD BEIGE "Shellokitty: exit: too many arguments\n" RESET);
		return ;
	}
	if (arraylen > 1)
	{
		exit_code[0] = str_to_long(data->cmd_list[0].cmd[1], &error[0]);
		if (data->cmd_list[0].cmd[2])
			exit_code[1] = str_to_long(data->cmd_list[0].cmd[2], &error[1]);
	}
	else
	{
		data->exit = 1;
		printf(BOLD RED "Exit\n" RESET);
		return ;
	}
	if (error[0])
	{
		printf(RED "Exit\n" RESET);
		ft_printf(2, BOLD RED "/!\\ "
			BOLD BEIGE "Shellokitty: exit: %s: numeric argument required\n"
			RESET, data->cmd_list[0].cmd[1]);
		data->exit = 1;
		data->exit_status = 2;
	}
	else if (!error[0] && error[1])
	{
		ft_printf(2, BOLD RED "Exit\n/!\\ "
			BOLD BEIGE "Shellokitty: exit: too many arguments\n" RESET);
		return ;
	}
	else if (!error[0] && arraylen == 2)
	{
		printf(RED "Exit\n" RESET);
		data->exit = 1;
		data->exit_status = exit_code[0];
		return ;
	}
	else if (arraylen >= 3 && !error[0] && error[1])
	{
		ft_printf(2, BOLD RED "Exit\n/!\\ "
			BOLD BEIGE "Shellokitty: exit: too many arguments\n" RESET);
		data->exit = 1;
		data->exit_status = 1;
		return ;
	}
	else if (arraylen >= 3 && !error[0] && !error[1])
	{
		ft_printf(2, BOLD RED "Exit\n/!\\ "
			BOLD BEIGE "Shellokitty: exit: too many arguments\n" RESET);
		data->exit_status = 1;
	}
}
