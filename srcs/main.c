/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:56:16 by npalissi          #+#    #+#             */
/*   Updated: 2025/01/22 19:28:02 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
    t_cmd cmd;
    cmd.cmd = "cd";
    cmd.flags = malloc(sizeof(char *)*2);
    cmd.flags[0] = ft_strdup("../../gnl");
    cmd.flags[1] = 0;

    cd(&data,&cmd);
    printf("apres cd : \n%s\n",data.pwd);
    return 0;
}