/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:57:26 by npalissi          #+#    #+#             */
/*   Updated: 2025/02/25 15:32:35 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

// chdir("/nfs/homes/npalissi/Documents/cursus");
/*
	int chdir(const char *path);
		
		- chdir() remplace le répertoire de travail courant du processus appelant par celui indiqué dans le chemin path.
	
		EACCES
			L'accès n'est pas autorisé sur un élément du chemin . (Voir aussi path_resolution(7).)
		EFAULT
			path pointe en dehors de l'espace d'adressage accessible.
		EIO
			Une erreur d'entrée-sortie s'est produite.
		ELOOP
			path contient une référence circulaire (à travers un lien symbolique).
		ENAMETOOLONG
			path est trop long.
		ENOENT
			Le fichier n'existe pas.
		ENOMEM
			Pas assez de mémoire pour le noyau.
		ENOTDIR
			Un élément du chemin d'accès path n'est pas un répertoire.
*/ 

int cd(t_data *data, char **cmd)
{
	char *pwd;
	char *old_pwd;

	if (!cmd[1])
		return (0);
	old_pwd = ft_strdup(ms_get_env(*data,"PWD"));
	if (!old_pwd)
		return (-1);
	pwd = ft_buildstr("%s/%s",old_pwd,cmd[1]);
	if (!pwd)
		return (-1);
	printf("%s\n",pwd);
	if ( chdir(pwd) == -1)
	{
		printf("1");
		free(pwd);
		return (0);
	}
	free(pwd);
	reload_pwd(data);
	printf("%s\n",ms_get_env(*data,"PWD"));
	
	return (1);
}



// int cd(t_data *data, t_cmd *cmd)
// {
// 	char **flags;
// 	char *pwd;
// 	// flags = ft_split(cmd->flags[0],'/'); //modified by edubois-
// 	flags = ft_split(cmd->cmd[1],'/');
// 	if (!flags)
// 		return (0);
// 	pwd = ft_strdup(data->pwd);
// 	while(*flags)
// 	{
// 		if(ft_strcmp(*flags, ".."))
// 		{
// 			pwd = ft_strndup(pwd,ft_strrchr(pwd,'/') - pwd, 1);
// 			if (!pwd)
// 				return (0);
// 		}
// 		else
// 		{
// 			pwd = ft_strjoinfree(ft_strjoinfree(pwd,"/",1),*flags,1); 
// 			if (!pwd)
// 				return (0);
// 		}
// 		flags++;
// 	}
	
// 	if ( chdir(pwd) == -1)
// 	{
// 		free(pwd);
// 		return (0);
// 	}
// 	free(pwd);
// 	reload_pwd(data);
// 	return (1);
// }
