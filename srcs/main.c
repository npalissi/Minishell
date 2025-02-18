/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:56:16 by npalissi          #+#    #+#             */
/*   Updated: 2025/02/18 11:57:32 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int main(int arg_c, char **arg_v, char **env)
{
    char * rl;
    
	t_data data = {env, NULL, NULL, NULL, 0, 0, NULL, 0, 0};
	collect_data(&data);
    signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, signal_handler);
	while (1 && !data.exit)
    {
		rl = readline("cacashell->");
		if (!rl || fill_line_data(&data, rl))
			break ;
		manage_exec_dir(&data);
		// make_exec(data, rl);
		// clear_data(data);
	}
	free(rl); 
	error_exit(data, 130, NULL);
	(void)arg_c;
	(void)arg_v;
}