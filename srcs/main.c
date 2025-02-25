/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:56:16 by npalissi          #+#    #+#             */
/*   Updated: 2025/02/25 15:23:27 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"


int main(int c, char **v, char **env)
{
	char *rl;
	char **cmds;
	(void)c;
	t_data data = {};
	
	ms_setup_lst_env(&data,env);
	int i;
	char *value_epur;
	rl = readline("->");
	while(rl)
	{
		i = 1;
		collect_data(&data);
		fill_line_data(&data, rl);
		while(data.cmd_list[0].cmd[i])
		{
			value_epur = build_var_env(data.cmd_list[0].cmd[i],data);
			data.cmd_list[0].cmd[i++] = value_epur;
		}
		if (!ft_strncmp(data.cmd_list[0].cmd[0],"export", ft_strlen("export")))
			export(&data,data.cmd_list[0].cmd);
		else if (!ft_strncmp(data.cmd_list[0].cmd[0],"env", ft_strlen("env")))
			cmd_env(&data);
		else if (!ft_strncmp(data.cmd_list[0].cmd[0],"clear",ft_strlen("clear")))
			system("clear");
		else if (ft_strcmp(data.cmd_list[0].cmd[0],"unset"))
			cmd_unset(&data,data.cmd_list[0].cmd);
		else if (ft_strcmp(data.cmd_list[0].cmd[0],"echo"))
			echo(data.cmd_list[0].cmd);
		else if (ft_strcmp(data.cmd_list[0].cmd[0],"exit"))
		{
			free(rl);
			clear_history();
			exit(1);
		}
		else if (ft_strcmp(data.cmd_list[0].cmd[0],"cd"))
			cd(&data, data.cmd_list[0].cmd);
		free(rl);
		rl = readline("->");			
	}
	ms_free_all_env(&data);

}

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
//     t_data data = {ft_arraydupe(env), NULL, NULL, NULL, 0};

// 	char **test;
// 	test = data.env;
	
// 	printf("%s",ms_getenv(data,"PWD"));

// 	// while(*test)
// 		// printf("%s\n",*test++);
// 	// printf("%s",data.env[0]);	
//     // char * rl;
//     // export(&data,NULL);
// 	// collect_data(&data);
// 	// bt_prompt(data);
// 	// signal(SIGQUIT, SIG_IGN);
// 	// signal(SIGINT, signal_handler);
// 	// while (1 && !data.exit)
//     // {
// 	// 	rl = bt_prompt(data);
// 	// 	if (!rl)
// 	// 		break ;
// 	// 	fill_line_data(&data, rl);
// 	// }
// 	// free(rl); 
// 	// error_exit(data, 0, NULL);;
// 	// (void)arg_c;
// 	// (void)arg_v;











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