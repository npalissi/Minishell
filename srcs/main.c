/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:56:16 by npalissi          #+#    #+#             */
/*   Updated: 2025/02/06 15:04:05 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

// int main(int c, char **v, char **env)
// {
//     (void)c;
//     t_data data = {env, NULL, NULL, NULL, 0};
//     // printf("%s",ft_strfilter_dup("coucou\'", &QUOTE));
//     char *str = replace_var_env(v[1], data);
//     printf("%s",str);
//     free(str);
// }




// int main(int arg_c, char **arg_v, char **env)
// {
//     char * rl;
    
//     t_data data = {env, NULL, NULL, NULL, 0};
// 	collect_data(&data);
//     while (1 && !data.exit)
//     {
// 		signal(SIGQUIT, SIG_IGN);
// 		signal(SIGINT, signal_handler);
// 		rl = readline("cacashell->");
// 		if (!rl)
// 			break ;
// 		// fill_line_data(&data, rl);
// 	}
// 	free(rl); 
// 	error_exit(data, 0, NULL);;
// 	(void)arg_c;
// 	(void)arg_v;











//     // reload_pwd(&data);
//     // printf("avant cd : \n%s\n", data.pwd);
//     // t_cmd *cmd;
//     // cmd = malloc(sizeof(t_cmd));
//     // cmd->cmd = malloc(sizeof(char *) * 3);
//     // cmd->cmd[0] = "cd";
//     // cmd->cmd[1] = ft_strdup("../../gnl");
//     // cmd->cmd[3] = NULL;
// // 
//     // cd(&data,cmd);
//     // printf("apres cd : \n%s\n",data.pwd);
//     // return 0;
// }