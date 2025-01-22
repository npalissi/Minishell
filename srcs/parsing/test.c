#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int ft_parsing(char *str)

int main(int c, char **v)
{
    char *rl;
    while(1)
    {
        rl = readline("➜ ");
        printf("%s\n", rl);
        free(rl);
    }
    return (0);
}