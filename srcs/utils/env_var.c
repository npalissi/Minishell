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

char *ms_getenv(t_data data, char *key)
{
	int i;
	int j;
	char **env;

	env = data.env;
	i = 0;
	j = 0;
	while(env[i])
	{
		j = 0;
		while(key[j] && env[i][j] && env[i][j] == key[j] )
			j++;
		if(!key[j] && env[i][j] == '=')
			return (env[i] + j + 1);
		i++;
	}
	return (0);
}

static void check_quotes(char *str,int i, int *dquote, int *quote)
{
	if (i > 0 && str[i - 1 ] == '\\')
		return;
	if (str[i] == '"')
	{
		if (*dquote == -1)
			*dquote = i;
		else
			*dquote = -1;
	}
	else if (str[i] == '\'')
	{
		if (*quote == -1)
			*quote = i;
		else
			*quote = -1;
	}
}

static char *epurstr(char *str)
{
	int dquote;
	int quote;
	int i;
	int size;

	dquote = -1;
	quote = -1;
	i = -1;
	size = 0;
	while(str[i])
	{
		i++;
		check_quotes(str,i,&dquote,&quote);

		if ((dquote == -1 && quote == -1 && str[i] == '\\') || (dquote != -1 && dquote < quote && str[i] == '\\' && str[i + 1] == '\"') )
		// if ((dquote == -1 && dquote == -1 && str[i] != '\\') || (quote != -1 && dquote < quote && str[i] == '\'' ) || (dquote != -1 && quote < dquote  && str[i] == '\"') || (str[i] != '\'))
		// 	size++;
		i++;
	}
	printf("%d\n",size);
	
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
	char *env;
	int i;
	int quote;
	int dquote;
	quote = -1;
	dquote = -1;
	i = 0;
	(void)data;
	// printf("start : %s\n",str);
	while(*(str + i))
	{
		check_quotes(str,i,&dquote,&quote);
		
		if (*(str + i) == '$' && is_env_char(*(str + i + 1)) && (quote == -1 || ((dquote < quote) && dquote != -1)))
		{
			env = get_var_env(str + 1 + i);
			env = get_env(env,data);
			if (!env)
				env = "";
			str = strinstr(str,i,env);
			i += ft_strlen(env);
		}
		i++;
	}
	return (str);
}


int main(int c, char **v)
{	
	char *rl;
	char *str;
	while(1)
	{
		rl = readline("-> : ");
		if (!rl)
			break;
		epurstr(rl);
		printf("%zu\n\n",ft_strlen(rl));
		// str = replace_var_env(rl,(t_data){});
		// printf("%s\n",str);

	}
}