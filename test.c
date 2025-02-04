#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void execute_echo(const char *text) {
	int fds[2];
	pipe(fds);
	char buffer[7];
	pid_t pid = fork();
	if (!pid)
	{
		close(fds[0]);
		dup2(fds[1],STDOUT_FILENO);
		close(fds[1]);
		write(1,"coucou",6);
	}else
	{
		close(fds[1]);
		read(fds[0],buffer,7);
		write(1,"test\n",5);
		write(1,buffer,3);
		close(fds[0]);
	}
}

int main() {
    execute_echo("coucou");
    return 0;
}