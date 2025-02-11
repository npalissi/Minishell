// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

#include <stdarg.h>
#include "headers/minishell.h"

static char *ft_get_arg(char c_type, va_list args)
{
    if (c_type == 's')
        return (ft_strdup(va_arg(args,char *)));
}

char *ft_buildstr(char *str, ...)
{
    int start;
    int i;
    char *build;
    char *arg;
    va_list args;

    build = ft_strdup("");
    if (!build)
        return (0);
    va_start(args,str);
    i = 0;
    start = 0;
    while(*(str + i))
    {
        if (*(str + i) == '%' && *(str + i + 1))
        {
            arg = ft_get_arg(*(str + i + 1),args);
            build = ft_strjoinfree(build,ft_substr(str, start, i - start), FREE_ALL);
            build = ft_strjoinfree(build,arg,FREE_ALL);
            if (!build)
                return (0);
            i++;
            start = i + 1;
        }
        i++;
    }
    build = ft_strjoinfree(build,ft_substr(str, start, i), FREE_ALL);
    va_end(args);
    return (build);
}

// int main(void)
// {
//     int str;
//     str = printf("%s=%s", "PWD", "KJHHDKJSH");
//     // printf("%s",str);
//     // free(str);
// }
