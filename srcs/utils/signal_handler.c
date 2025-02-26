/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42angouleme>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:23:29 by edubois-          #+#    #+#             */
/*   Updated: 2025/02/26 22:47:11 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		rl_replace_line("", 1);
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
	}
}
