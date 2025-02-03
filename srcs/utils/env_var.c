#include "../../headers/minishell.h"


static int is_env_char(char c)
{
	return (ft_isalnum(c) || c == '_');
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

char *replace_var_env(char *str)
{
	// char *save_str;

	// printf("%s",str);
	while(*str)
	{
		
		if (*str == '$' && is_env_char(*(str + 1)))
			printf("%s",get_var_env(str + 1));

		str++;
	}
	return (str);
}