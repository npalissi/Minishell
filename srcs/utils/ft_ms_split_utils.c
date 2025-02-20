/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ms_split_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:00:01 by edubois-          #+#    #+#             */
/*   Updated: 2025/02/19 19:13:01 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int check_quote(char *str)
{
	int iq;
	int idq;
	int i;

	i = 0;
	idq = 0;
	iq = 0;
	while (str && str[i])
	{
		if (str[i] == '"' && iq == 0 && ((i == 0) || (i > 0 && str[i - 1] != '\\')) && idq == 0)
			idq = 1;
		else if (str[i] == '"' && iq == 0 && ((i == 0) || (i > 0 && str[i - 1] != '\\')) && idq == 1)
			idq = 0;
		else if (str[i] == '\'' && idq == 0 && ((i == 0) || (i > 0 && str[i - 1] != '\\')) && iq == 0)
			iq = 1;
		else if (str[i] == '\'' && idq == 0 && ((i == 0) || (i > 0 && str[i - 1] != '\\')) && iq == 1)
			iq = 0;
		i++;
	}
	if (idq || iq)
		return (1);
	return (0);
}

void add_quoted_word(char **word, char **str, int *idq, int *iq)
{
	int i;
	char *s;
	char *w;
	char *save_w;

	s = *str;
	w = *word;
	save_w = w;
	i = 0;
	if (*iq)
		*w++ = '\'';
	else
		*w++ = '"';
	while (s[i] && (*idq || *iq || (s[i] != ' ' && s[i + 1] != '|')))
	{
		*w++ = s[i];
		if (s[i] == '"' && *iq == 0 && ((i == 0) || (i > 0 && s[i - 1] != '\\')) && *idq == 1)
			*idq = 0;
		else if (s[i] == '\'' && *idq == 0 && ((i == 0) || (i > 0 && s[i - 1] != '\\')) && *iq == 1)
			*iq = 0;
		i++;
	}
	*word = save_w;
	*str = s + i;
}

void add_simple_word(char **word, char **str)
{
	char *s;
	char *w;
	char *s_w;
	int i;
	int iq[2];

	s = *str;
	w = *word;
	s_w = w;
	i = 0;
	iq[0] = 0;
	iq[1] = 0;
	while (s[i] && !iq[0] && !iq[1] && s[i] != ' ' && s[i] != '|')
	{
		*w++ = s[i];
		if (s[i] == '"' && iq[0] == 0 && ((i == 0) || (i > 0 && s[i - 1] != '\\')) && iq[1] == 0)
			iq[1] = 1;
		else if (s[i] == '\'' && iq[1] == 0 && ((i == 0) || (i > 0 && s[i - 1] != '\\')) && iq[0] == 0)
			iq[0] = 1;
		i++;
	}
	while (s[i] && (iq[0] || iq[1]))
	{
		*w++ = s[i];
		if (s[i] == '"' && iq[0] == 0 && ((i == 0) || (i > 0 && s[i - 1] != '\\')) && iq[1] == 1)
			iq[1] = 0;
		else if (s[i] == '\'' && iq[1] == 0 && ((i == 0) || (i > 0 && s[i - 1] != '\\')) && iq[0] == 1)
			iq[0] = 0;
		i++;
	}
	while (s[i] && s[i] != ' ' && s[i] != '|')
		*w++ = s[i++];
	*word = s_w;
	*str = s + i;
}
