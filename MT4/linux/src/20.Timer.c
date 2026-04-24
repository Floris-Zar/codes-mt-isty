/*!
 * \file 20.Timer.c
 * \brief Programme de test pour l'utilisation du timer
 *
 * Programme qui utilise un timer pour déclencher un signal SIGALRM à intervalles réguliers.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void gestionnaire (int sig);


int iter = 0;

int main (int argc, char **argv) {

	if (signal(SIGALRM, gestionnaire) == SIG_ERR) {
		fprintf(stderr,"Erreur association SIGALRM \n");
		exit(0);
	}
	
	fprintf(stderr, "Début de la Boucle\n");
	system("date +\"%H:%M:%S:%N\"");
	alarm (7);
	while (1) {
		/* --- Simu Traitement --- */
	}   
	
	return EXIT_SUCCESS;
}


void gestionnaire (int sig) {
	if (sig == SIGALRM)
		fprintf(stderr,"SIGALRM recu : iteration %d\n", iter); 
	system("date +\"%H:%M:%S:%N\"");
	iter++;
	alarm (3);
}