#include "../../headers/minishell.h"


static int is_env_char(char c)
{
	return (ft_isalnum(c) || c == '_' || c == '?');
}

static char *get_var_env(char *str)
{
	int size;
	char *env;
	char *save_env;
	char *save_str;

	save_str = str;
	while(*str && is_env_char(*str))
		str++;
	size = str - save_str;
	env = malloc(size + 1);
	if (!env)
		return (0);
	save_env = env;
	while(*save_str && is_env_char(*save_str))
		*env++ = *save_str++;
	*env = 0;
	return (save_env);
}

static char *strinstr(char *src, int pos, char *dest)
{
	char *str;


	str = ft_substr(src,0,pos);
	str = ft_strjoinfree(str,dest,FREE_S1);
	pos++;
	while(is_env_char(src[pos]))
		pos++;
	str = ft_strjoinfree(str, src + pos,FREE_S1);
	free(dest);
	return (str);
}

static char*get_env(char *str, t_data data)
{
	char *env;

	(void)data;
	if (ft_strcmp(str, "?"))
	{
		free(str);
		return (ft_strdup("100")); // a faire avec le exit status
	}
	env = getenv(str);
	if (!env)
		env = ft_strdup("");
	else
		env = ft_strdup(env);
	free(str);
	return (env);	
}

char *replace_var_env(char *str, t_data data)
{
	char *save_str;
	char *env;

	(void)data;
	save_str = str;
	while(*str)
	{	

		if (*str == '$' && is_env_char(*(str + 1)))
		{
			env = get_var_env(str + 1);
			env = get_env(env,data);
			if (!env)
				env = "";
			return (replace_var_env(strinstr(save_str,str - save_str,env), data));
		}
		str++;
	}
	return (save_str);
}