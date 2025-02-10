/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:56:16 by npalissi          #+#    #+#             */
/*   Updated: 2025/02/10 17:33:51 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int main(int arg_c, char **arg_v, char **env)
{
    char * rl;
    
    t_data data = {env, NULL, NULL, NULL, 0, 0, NULL, 0, 0};
	collect_data(&data);
    while (1 && !data.exit)
    {
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, signal_handler);
		rl = readline("cacashell->");
		if (!rl || fill_line_data(&data, rl))
			break ;
		make_exec(data, rl);
	}
	free(rl); 
	error_exit(data, 0, NULL);;
	(void)arg_c;
	(void)arg_v;
}