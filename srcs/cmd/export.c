/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:10:28 by npalissi          #+#    #+#             */
/*   Updated: 2025/02/11 11:12:56 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static int is_env_char(char c)
{
	return (ft_isalnum(c) || c == '_' );
}

static int get_bigger(char *str1, char *str2)
{
	int i;
	i = 0;
	while(str1[i] && str2[i] && str1[i] == str2[i] && str1[i + 1] != '=' && str2[i + 1] != '=')
		i++;
	return (str1[i] > str2[i]);
}

char **sort_array(char ** tab)
{
	t_sort tmp_sort;
	int i;
	int j;

	i = 0;
	while(tab[i])
	{
		j = i + 1;
		tmp_sort = (t_sort){i, 0, tab[i]};
		while(tab[j])
		{
			if (!get_bigger(tab[j],  tmp_sort.str))
				tmp_sort = (t_sort){j, 0, tab[j]};
			j++;
		}

		tab[tmp_sort.pos] = tab[i];
		tab[i] = tmp_sort.str;
		i++;
	}
	return (tab);
}


static char** split_env(char* str)
{
	char **tab;
	char j;
	int i;

	tab = malloc(sizeof(char *) * 3);
	if (!tab)
		return (0);
	i = 0;
	while(str[i] && str[i] != '=')
		i++;
	tab[0] = malloc(i + 1);
	i = 0;
	while(str[i] && str[i] != '=')
	{
		tab[0][i] = str[i];
		i++; 
	}
	tab[0][i] = 0;
	if (!str[i] || !str[i+1])
		tab[1] = ft_strdup("''");
	else
	{
		tab[1] = malloc(ft_strlen(str) - i + 1);
		if (!tab[1])
			return (0);
		i++;
		j = 0;
		while(str[i])
			tab[1][j++] = str[i++];
		tab[1][j] = 0;
	}
	tab[2] = 0;
	return (tab);
}



int export(t_data *data, char **cmds)
{
	int i;
	char **env;
	char **key;

	if (!cmds[1])
	{		
		env = sort_array(data->env);
		while(*env)
		{
			write(1,*env,ft_strlen(*env));
			write(1,"\n",1);
			env++;
		}
		return (0);
	}
	i = 1;
	while(cmds[i])
	{
		key = split_env(cmds[i]);
		printf("%s=%s\n",key[0],key[1]);
		i++;
	}
	return (1);
}

// int main(int c, char **v, char **env)
// {
// 	(void)c;

// 	t_data data = {ft_arraydupe(env), NULL, NULL, NULL, 0};
// 	char *cmds[] = {
// 		"export",
// 		"test  =1",
// 		"coucou",
// 		"coucou=",
// 		NULL
// 	};
// 	export(&data,cmds);
// }