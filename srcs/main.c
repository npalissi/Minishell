/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:56:16 by npalissi          #+#    #+#             */
/*   Updated: 2025/01/23 15:11:54 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int main(int arg_c, char **arg_v, char **env)
{
    // char * rl;
    
    t_data data = {arg_v, arg_c, env, NULL, NULL, NULL};
	collect_data(&data);
    // while (1);
    // {
        // rl = readline("cacashell");
		// fill_data(&data, rl);
	// }
	error_exit(data, 0, NULL);;













    // reload_pwd(&data);
    // printf("avant cd : \n%s\n", data.pwd);
    // t_cmd *cmd;
    // cmd = malloc(sizeof(t_cmd));
    // cmd->cmd = malloc(sizeof(char *) * 3);
    // cmd->cmd[0] = "cd";
    // cmd->cmd[1] = ft_strdup("../../gnl");
    // cmd->cmd[3] = NULL;
// 
    // cd(&data,cmd);
    // printf("apres cd : \n%s\n",data.pwd);
    // return 0;
}