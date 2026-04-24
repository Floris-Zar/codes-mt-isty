/*!
 * \file 21.ProcessPeriod.c
 * \brief Programme de test pour les processus périodiques
 *
 * Programme qui teste la création de processus périodiques à l'aide d'un timer.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void gestionnaire (int sig);

int iter = 0;

int main (int argc, char **argv) {
	if (signal(SIGALRM, gestionnaire) == SIG_ERR) {
		fprintf(stderr,"Erreur association SIGUSR1 \n");
		exit(0);
	}

	fprintf(stderr, "Debut de la Boucle\n");
	system("date +\"%H:%M:%S:%N\"");
	alarm (7);
	while (1) {
		/* --- Simu Traitement --- */
	}
	return EXIT_SUCCESS;
}

void gestionnaire (int sig) {

	pid_t ret;
	if (sig == SIGALRM)
		fprintf(stderr,"SIGUSR1 recu : iteration %d\n", iter);
	system("date +\"%H:%M:%S:%N\"");

	alarm (3);
	ret = fork();
	if (ret < 0) {
		fprintf(stderr,"Erreur de Creation \n");
		exit(0);
	}
	else if (ret == 0) { // fils
		fprintf(stderr,"Fils %d de Père %d\n", getpid(), getppid());
		exit(0);
	}
	iter++;
}