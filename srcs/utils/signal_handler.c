/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:23:29 by edubois-          #+#    #+#             */
/*   Updated: 2025/02/20 13:38:16 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void    signal_handler(int sig)
{
    if (sig == SIGINT)
	{
		rl_replace_line("", 1);
    	printf("\n", NULL);
		rl_on_new_line();
		rl_redisplay();
	}
}
