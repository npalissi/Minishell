/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:56:16 by npalissi          #+#    #+#             */
/*   Updated: 2025/03/12 15:24:01 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	main(int arg_c, char **arg_v, char **env)
{
	t_data	data;
	char	*rl;

	printf("start minishell\n");
	data = (t_data){0};
	data.env = env;
	collect_data(&data);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, signal_handler);
	rl = readline("cacashell-> ");
	while (rl && !data.exit)
	{
		if (!rl)
			break ;
		if (*rl)
		{
			if (!fill_line_data(&data, rl) && !check_pipe(&data, rl))
				make_exec(data, rl);
			reset_data(&data, rl);
		}
		rl = readline("cacashell-> ");
	}
	exit(data.exit_status);
	(void)arg_c;
	(void)arg_v;
}
