#include <stdio.h>
//#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv, char *envp[]) {
    char *args[] = {"/bin/ls", "-l", NULL}; // Liste d'arguments pour le programme à exécuter

    // Exécuter le programme /bin/ls avec les arguments spécifiés
    // Le premier argument est le chemin vers le programme à exécuter,
    // le deuxième argument est un tableau d'arguments pour ce programme,
    // le troisième argument est un tableau d'environnement pour le programme.
    execve("/bin/ls", args, envp);

    // Si execve retourne, cela signifie qu'il y a eu une erreur
    perror("execve");
    return 1;
}
