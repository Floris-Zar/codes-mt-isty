/*!
 * \file 22.PereFilsSignaux.c
 * \brief Programme de test pour les signaux entre père et fils
 *
 * Programme qui teste l'envoi de signaux entre un processus père et un processus fils.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void gestionnaire (int sig);
int iter = 0;

int main (int argc, char **argv) {
	pid_t ret;

	ret = fork();
	if (ret < 0) {
		fprintf(stderr,"Erreur de Creation \n");
		exit(0);
	} else if (ret > 0) { // Pere
		fprintf(stderr,"Pere : PID = %d, PPID = %d \n",
		getpid(), getppid());
		/* --- Émetteur : SIGUSR1 toute les 5 s --- */
		while(1) {
			sleep(5);
			kill(ret, SIGUSR1);
		}
		exit(0);
	} else { // Fils ret == 0
		fprintf(stderr,"Fils : PID = %d, PPID = %d \n", getpid(), getppid());
		if (signal(SIGUSR1, gestionnaire) == SIG_ERR) {
			fprintf(stderr, "Erreur association SIGUSR1 \n");
			exit(0);
		}
		while(1)
			pause();

		exit(0);
	}
		
	return EXIT_SUCCESS;
}


void gestionnaire (int sig) {
	if (sig == SIGUSR1)
		fprintf(stderr,"Processus : %d : SIGUSR1 recu : iteration %d \n", getpid(), iter++);
	system("date +\"%H:%M:%S:%N\"");
}



/* Affichage terminal de 22.PereFilsSignaux.c :

Père pid = 28053, fils pid = 28054
Fils pid = 28054, ppid = 28053

*/