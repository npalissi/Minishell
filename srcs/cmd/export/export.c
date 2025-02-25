/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:23:05 by npalissi          #+#    #+#             */
/*   Updated: 2025/02/25 15:19:16 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	export_var(t_data *data, char **key)
{
	char	*var;

	if (!key[1] && !ms_get_node_by_key(data, key[0]))
	{
		if (!ms_new_var(data->env_list, key[0], 0, ft_strdup(key[0])))
			return (0);
	}
	else if (key[1])
	{
		var = ft_buildstr("%s=%s", key[0], key[1]);
		if (!var)
		{
			ft_free_tab(key);
			return (0);
		}
		if (ms_get_node_by_key(data, key[0]))
			ms_edit_env_lst(data, key[0], key[1], var);
		else
			if (!ms_new_var(data->env_list, key[0], key[1], var))
				return (0);
	}
	return (1);
}

int	export(t_data *data, char **cmds)
{
	char	**key;

	if (!cmds[1])
		return (ms_print_export(*data));
	while (*(++cmds))
	{
		key = ms_split_env(*cmds);
		if (!key)
			return (-1);
		if (!is_valid_key(key[0]) || !*key[0])
		{
			printf("bash: export: `%s': not a valid identifier\n", *cmds);
			ft_free_tab(key);
			continue ;
		}
		if (!export_var(data, key))
			return (-1);
		free(key);
	}
	if (!ms_build_array_env(data))
		return (-1);
	return (1);
}
