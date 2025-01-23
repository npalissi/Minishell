/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:56:16 by npalissi          #+#    #+#             */
/*   Updated: 2025/01/23 12:24:24 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int main(int arg_c, char **arg_v, char **env)
{
    // char *rl;
    (void)arg_c;
    (void)arg_v;
    (void)env;

    t_data data;
    data.pwd = 0;

    reload_pwd(&data);
    printf("avant cd : \n%s\n", data.pwd);
    t_cmd *cmd;
    cmd = malloc(sizeof(t_cmd));
    cmd->cmd = malloc(sizeof(char *) * 3);
    cmd->cmd[0] = "cd";
    cmd->cmd[1] = ft_strdup("../../gnl");
    cmd->cmd[3] = NULL;

    cd(&data,cmd);
    printf("apres cd : \n%s\n",data.pwd);
    return 0;
}