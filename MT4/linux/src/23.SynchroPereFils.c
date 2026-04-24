/*!
 * \file 23.SynchroPereFils.c
 * \brief Programme de test pour la synchronisation entre père et fils
 *
 * Programme qui teste la synchronisation entre processus père et fils.
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
		/* --- Emetteur : SIGUSR1 toute les 5 s --- */
		while(1) {
			sleep(5);
			kill(ret, SIGUSR1);
			fprintf(stderr,"Pere : PID = %d : SIGUSR1 envoye : iteration %d \n", getpid(), iter++);
			system("date +\"%H:%M:%S:%N\"");
		}
		exit(0);
	} else { // Fils ret == 0 
		fprintf(stderr,"Fils : PID = %d, PPID = %d \n",
		getpid(), getppid());
		if (signal(SIGUSR1, gestionnaire) == SIG_ERR) {
			fprintf(stderr,"Erreur association SIGUSR1 \n");
			exit(0);
		}
		while(1) {
			pause();
			sleep(2);
		}

		exit(0);
	}
		
	return EXIT_SUCCESS;
}

 void gestionnaire (int sig) {
	if (sig == SIGUSR1)
		fprintf(stderr,"Processus : %d : SIGUSR1 recu : itération %d \n", getpid(), iter++);
	
	system("date +\"%H:%M:%S:%N\"");
}