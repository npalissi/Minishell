/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_here_doc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:32:17 by edubois-          #+#    #+#             */
/*   Updated: 2025/03/11 13:05:49 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	g_sigint;

void	sigheredoc(int sig)
{
	if (sig && !g_sigint)
	{
    	printf("\n");
		rl_replace_line("", 1);
		g_sigint = sig;
		exit(128 + sig);
	}
}

int	destroy_here_doc(t_data *data)
{
	int i;

	i = 0;
	while(data->here_doc_name && data->here_doc_name[i])
	{
		unlink(data->here_doc_name[i]);
		free(data->here_doc_name[i]);
		i++;
	}
	free(data->here_doc_name);
	return (0);
}

char *random_name(void)
{
	int fd;
	char *s;
	char c;
	int i;

	i = 1;
	c = 0;
	s = ft_calloc(50, 1);
	if (!s)
		return (NULL);
	*s = '.';
	fd = open("/dev/urandom",O_RDONLY);
	if (fd >= 0)
	{
		while (i < 48)
		{
			read(fd, &c, 1);
			if (ft_strchr("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", c))
				s[i++] = c;	
		}
	}
	if (fd > 2)
		close(fd);
	return (s);
}

char *start_here_doc(t_data *data, char *lim, char *l)
{
	int fd;
	char *line;
	char *rdm_name;
	int	pid;
	int	e;

	g_sigint = 0;
	signal(SIGINT, sigheredoc);
	rdm_name = random_name();
	ft_strapp(&data->here_doc_name, rdm_name);
	line = NULL;
	pid = fork();
	if (!pid)
	{
		rl_clear_history();
		rl_catch_signals = 1;
		fd = open(rdm_name, O_CREAT | O_WRONLY, 0644);
		while (fd > 0 && lim)
		{
			line = readline("heredoc: ");
			if (line && !ft_strcmp(line, lim))
			{
				line = ft_strjoinfree(line, "\n", 1);
				ft_putstr_fd(line, fd);
				free(line);
			}
			else if (!line)
			{
				ft_printf(2, "shellokitty: warning: here-document delimited by end-of-file (wanted `%s')\n", lim);
				close(fd);
				reset_data_here(data, l);
				exit(0);
			}
			else
			{
				close(fd);
				reset_data_here(data, l);
				exit(0);
			}
		}
	}
	else
	{
		e = 0;
		signal(SIGINT, SIG_IGN);
		waitpid(pid, &e, 0);
		signal(SIGINT, signal_handler);
		data->exit_status = WEXITSTATUS(e);
		if (data->exit_status)
			g_sigint = 130;
	}
	if (g_sigint)
		rdm_name = NULL;
	return (rdm_name);
}
