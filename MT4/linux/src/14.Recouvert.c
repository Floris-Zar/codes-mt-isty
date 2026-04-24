/*!
 * \file 14.Recouvert.c
 * \brief Recouvrement de processus
 *
 * Programme qui utilise la fonction execl pour remplacer le processus courant par un autre programme.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char **argv) { 
	fprintf(stderr,"Processus Recouvert %d de Père %d\n", getpid(), getppid());
	// execl("/bin/ls", "ls", "-al", (char *)NULL);
	execl("/home/isty/Isty2026/MT4/Linux/bin/Affiche", "Affiche", "Bonjour", (char *)NULL);
	// équivalent de la ligne de commande dans le terminal : ../bin/Affiche Bonjour
	fprintf(stderr,"Vu ???\n");
	return EXIT_SUCCESS;
}