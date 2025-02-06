#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void execute_echo(const char *text) {
    pid_t pid;
    char *args[] = {
        "/bin/echo",
		"-n",  // Le chemin vers la commande echo
        "$PWD", // Le texte à afficher
        NULL         // La liste doit se terminer par NULL
    };


    
        execve("/bin/echo", args, NULL);
        perror("execve");
        exit(EXIT_FAILURE);

}

int main() {
    // Test avec un message simple
    execute_echo("Hello $PWD World!");
    return 0;
}