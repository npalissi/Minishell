/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:03:03 by edubois-          #+#    #+#             */
/*   Updated: 2025/03/19 11:26:13 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

long	str_to_long(const char *num_str, int *error)
{
	long	num;
	int		is_negative;

	num = 0;
	is_negative = 0;
	if (*num_str == '-')
	{
		is_negative = 1;
		num_str++;
	}
	else if (*num_str == '+')
		num_str++;
	while (*num_str)
	{
		if (!ft_isdigit(*num_str))
		{
			*error = 1;
			return (0);
		}
		if (num > LONG_MAX / 10
			|| (num == LONG_MAX / 10 && *num_str - '0' > LONG_MAX % 10))
		{
			*error = 1;
			return (0);
		}
		if (num < LONG_MIN / 10
			|| (num == LONG_MIN / 10 && *num_str - '0' > -(LONG_MIN % 10)))
		{
			*error = 1;
			return (0);
		}
		num = num * 10 + (*num_str - '0');
		num_str++;
	}
	if (is_negative)
		num = -num;
	return (num);
}

void	ft_exit(t_data *data)
{
	int	exit_code[2];
	int	error[2];
	int	arraylen;

	arraylen = ft_arraylen(data->cmd_list[0].cmd);
	if (!data->cmd_list[1].cmd)
	{
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
		else if (arraylen == 3 && !error[0] && error[1])
		{
			ft_printf(2, BOLD RED "Exit\n/!\\ "
				BOLD BEIGE "Shellokitty: exit: too many arguments\n" RESET);
			data->exit = 1;
			data->exit_status = 1;
			return ;
		}
		else if (arraylen == 3 && !error[0] && !error[1])
		{
			ft_printf(2, BOLD RED "Exit\n/!\\ "
				BOLD BEIGE "Shellokitty: exit: too many arguments\n" RESET);
			data->exit_status = 1;
		}
	}
}
