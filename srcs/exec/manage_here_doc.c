/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_here_doc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:32:17 by edubois-          #+#    #+#             */
/*   Updated: 2025/02/19 19:05:00 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

char *random_name(void)
{
	int fd;
	char *s;

	s = ft_calloc(11, 1);
	if (!s)
		return (NULL);
	fd = open("/dev/urandom", O_RDONLY);
	if (fd >= 0)
		read(fd, s, 10);
	close(fd);
	return (s);
}

int start_here_doc(char *lim)
{
	int fd;
	char *line;
	char *rdm_name;

	rdm_name = ft_strjoin(".", random_name());
	line = NULL;
	fd = open(rdm_name, O_CREAT, 0644);
	while (fd > 0 && lim)
	{
		line = readline("heredoc: ");
		if (!ft_strcmp(lim, line))
			ft_putstr_fd(line, fd);
		else
			break;
		free(line);
	}
	unlink(rdm_name);
	free(rdm_name);
	free(line);
	return (fd);
}
