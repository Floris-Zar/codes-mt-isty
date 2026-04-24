/*!
 * \file 17.Recepteur.c
 * \brief Programme de test pour la réception de signaux
 *
 * Programme qui attend la réception de signaux (SIGUSR1, SIGUSR2, SIGALRM) et affiche un message lorsqu'un signal est reçu.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void gestionnaire (int sig);

int main (int argc, char **argv) { 
	fprintf(stderr,"Récépteur pid = %d\n", getpid());

	// Association du Recepteur aux 3 signaux
	if (signal(SIGUSR1, gestionnaire) == SIG_ERR) {
		fprintf(stderr,"Erreur association SIGUSR1 \n");
		exit(0);
	}
	if (signal(SIGUSR2, gestionnaire) == SIG_ERR) {
		fprintf(stderr,"Erreur association SIGUSR2 \n");
		exit(0);
	}
	if (signal(SIGALRM, gestionnaire) == SIG_ERR) {
		fprintf(stderr,"Erreur association SIGALRM \n");
		exit(0);
	}
	alarm (10);
	fprintf(stderr, "Entree en Boucle d'Attente Active \n");
	system("date +\"%H:%M:%S:%N\"");
 
	while (1) {
		fprintf(stderr, "Entree en Pause \n");
		system("date +\"%H:%M:%S:%N\"");
		pause ();
		fprintf(stderr, "Sortie en Pause \n");
		system("date +\"%H:%M:%S:%N\"");
	}
	
	return EXIT_SUCCESS;
}

void gestionnaire (int sig) {
	if (sig == SIGUSR1)
		fprintf(stderr,"SIGUSR1 recu \n");
	else if (sig == SIGUSR2)
		fprintf(stderr,"SIGUSR2 recu \n");
	else if (sig == SIGALRM)
		fprintf(stderr,"SIGALRM recu \n");

	system("date +\"%H:%M:%S:%N\"");
}




/* Affichage terminal de 17.Recepteur.c :

Recepteur pid = 12403
Entree en Boucle d'Attente Active 
09:30:32:878784865
Entree en Pause 
09:30:32:880831225

*/