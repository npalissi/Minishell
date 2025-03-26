/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:08:43 by npalissi          #+#    #+#             */
/*   Updated: 2025/03/26 14:00:33 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	pwd(void)
{
	char	path[1024];

	getcwd(path, sizeof(path));
	printf("%s\n", path);
	return (0);
}

int	reload_pwd(t_data *data)
{
	char	*path;
	t_env	*node_old_pwd;
	t_env	*node_pwd;
	int		exit_code;

	path = getcwd(NULL, 0);
	if (!dh_add_ptr(path))
		return (-1);
	if (ms_create_node_ifno(data, "OLDPWD", &node_old_pwd) == -1)
		return (-1);
	exit_code = ms_create_node_ifno(data, "PWD", &node_pwd);
	if (exit_code == -1)
		return (-1);
	if (!exit_code)
		return (0);
	ms_swap_node(&node_old_pwd->key, &node_pwd->key);
	if (!ms_edit_env_lst(data, "PWD", path, ft_buildstr("%s=%s", "PWD", path)))
		return (-1);
	ms_build_array_env(data);
	return (0);
}
