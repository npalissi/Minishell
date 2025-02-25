// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>



// int main(void)
// {
//     int str;
//     str = printf("%s=%s", "PWD", "KJHHDKJSH");
//     // printf("%s",str);
//     // free(str);
// }


static int ms_split_env_key(char* str, char ***tab)
{
	int i;
	i = 0;
	while(str[i] && str[i] != '=')
        i++;
    *(tab[0]) = ft_substr(str,0,i);
	if (!tab[0])
		return (0);
	return (1);
}

static int ms_split_env_value(char *str, char ***tab)
{
	int i;
	
	i = 0;
	while(str[i] && str[i] != '=')
        i++;
	if (!str[i])
		return (1);
	else if (!str[i+1])
		*(tab[1]) = ft_strdup("");
	else
		*(tab[1]) = ft_substr(str, i + 1 , ft_strlen(str) - i);
	if (!tab[1])
		return (0);
	return (1);
}

char** ms_split_env(char* str)
{
    char **tab;

    tab = ft_calloc(sizeof(char *), 3);
    if (!tab)
        return (0);
    if (!ms_split_env_key(str, &tab))
    {
        free(tab);
        return (0);
    }
    if (!ms_split_env_value(str, &tab))
	{
		ft_free_tab(tab);
		return (0);
	}
    return (tab);
}