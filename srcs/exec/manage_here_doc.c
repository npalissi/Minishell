/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_here_doc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:32:17 by edubois-          #+#    #+#             */
/*   Updated: 2025/02/20 22:40:16 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	g_sigint;

void	sigheredoc(int sig)
{
	if (sig && !g_sigint)
	{
    	printf("\n", NULL);
		rl_replace_line("", 1);
		g_sigint = sig;
		exit(sig);
	}
}

int	destroy_here_doc(t_data *data)
{
	while(data->here_doc_name && *data->here_doc_name)
	{
		unlink(*data->here_doc_name);
		free(*data->here_doc_name);
		data->here_doc_name++;
	}
	return (0);
}

char *random_name(void)
{
	int fd;
	char *s;

	s = ft_calloc(14, 1);
	if (!s)
		return (NULL);
	*s = '.';
	fd = open("/dev/random",O_RDONLY);
	if (fd >= 0)
		read(fd, s + 1, 9);
	printf("%s\n", s);
	close(fd);
	return (s);
}

char *start_here_doc(t_data *data, char *lim)
{
	int fd;
	char *line;
	char *rdm_name;
	int	pid;
	int	e;

	g_sigint = 0;
	signal(SIGINT, sigheredoc);
	pid = fork();
	line = NULL;
	if (!pid)
	{
		rl_catch_signals = 1;
		rdm_name = random_name();
		printf("%s\n", rdm_name);
		fd = open(rdm_name, O_CREAT | O_WRONLY, 0644);
		printf("%s\n", rdm_name);
		ft_strapp(&data->here_doc_name, rdm_name);
		printf("%s\n", rdm_name);
		while (fd > 0 && lim)
		{
			line = readline("heredoc: ");
			if (line && !ft_strcmp(line, lim))
			{
				line = ft_strjoinfree(line, "\n", 1);
				ft_putstr_fd(line, fd);
			}
			else
				exit(0);
		}
		close(fd);
	}
	else
	{
		e = 0;
		signal(SIGINT, SIG_IGN);
		waitpid(pid, &e, 0);
		signal(SIGINT, signal_handler);
		if (WIFSIGNALED(e))
		g_sigint = WTERMSIG(e);
	}
	if (!line && !g_sigint)
		ft_printf(2, "shellokitty: warning: here-document delimited by end-of-file (wanted `%s')\n", lim);
	else
		free(line);
	if (g_sigint)
	{
		destroy_here_doc(data);
		rdm_name = NULL;
		data->exit_status = WTERMSIG(e) + 128;
	}
	return (rdm_name);
}
