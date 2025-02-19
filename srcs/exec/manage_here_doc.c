/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_here_doc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:32:17 by edubois-          #+#    #+#             */
/*   Updated: 2025/02/19 18:23:18 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

char *random_name(t_data *data)
{
    int fd;
    char *s;

    s = ft_calloc(21, 1);
    if (!s)
        return (NULL);
    fd = open("/dev/urandom", O_RDONLY);
    if (fd >= 0)
        read(fd, s, 20);
    close(fd);
    ft_strapp(&data->here_doc_name, s);
    return (s);
}

int start_here_doc(t_data *data, char *lim)
{
    int fd;
    char *line;
    char *new_lim;

    line = NULL;
    new_lim = ft_strjoinchar(lim, '\n');
    fd = open(random_name(data), O_CREAT | O_RDONLY);
    while (fd > 0 && new_lim)
    {
        line = readline("heredoc: ");
    	printf("\n", NULL);
        rl_on_new_line();
        if (!ft_strcmp(new_lim, line))
            ft_putstr(fd, line);
        else
            break;
        free(line);
    }
    free(line);
    free(new_lim);
    return (fd);
}
