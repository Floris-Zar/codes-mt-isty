/*!
 * \file 19.TimeOut.c
 * \brief Programme de test pour le timeout
 *
 * Programme qui teste le timeout en attendant un certain temps.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void gestionnaire (int sig);

int fTimeOut = 0;

int main (int argc, char **argv) { 

	if (signal(SIGALRM, gestionnaire) == SIG_ERR) {
		fprintf(stderr,"Erreur association SIGUSR1 \n");
		exit(0);
	}
	
	fprintf(stderr, "Debut de la Boucle\n");
	system("date +\"%H:%M:%S:%N\"");
	alarm (5);
	while (1) {
		/* --- Simu Traitement --- */
		if (fTimeOut == 1)
			break;
	}
	fprintf(stderr, "Sortie de Boucle  \n");
	system("date +\"%H:%M:%S:%N\"");
	 
	return EXIT_SUCCESS;
}

void gestionnaire (int sig) {
	if (sig == SIGALRM)
		fprintf(stderr,"SIGUSR1 recu \n");
	fTimeOut = 1; 
	system("date +\"%H:%M:%S:%N\"");
}