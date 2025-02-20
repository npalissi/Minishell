/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:56:16 by npalissi          #+#    #+#             */
/*   Updated: 2025/02/20 19:41:49 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int main(int arg_c, char **arg_v, char **env)
{
	t_data data;
	char *rl;

	data = (t_data){0};
	data.env = env;
	collect_data(&data);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, signal_handler);
	rl = readline("cacashell-> ");
	while (rl && !data.exit)
	{
		if (!rl)
			break;
		if (rl && !fill_line_data(&data, rl) && !check_pipe(&data, rl))
			make_exec(data, rl);
		// printcmd(&data);
		free(rl);
		rl = readline("cacashell-> ");
	}
	free(rl);
	error_exit(data, 130, NULL);
	(void)arg_c;
	(void)arg_v;
}
