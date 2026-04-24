/*!
 * \file 12.CreationPereFilsBoucle.c
 * \brief Creation Pere Fils Boucle
 *
 * Programme qui crée un processus père qui crée NB processus fils dans une boucle. Chaque fils affiche son PID et celui de son père. Le père attend la fin de tous les fils.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>

#define NB 5

int main (int argc, char **argv) {

	pid_t ret;
	int k;

	for (k=0 ; k<NB ; k++) {

		ret = fork();
		if (ret < 0) {
			fprintf(stderr,"Erreur de Creation \n");
			exit(0);
		} else if (ret > 0) { // Pere
			// fprintf(stderr,"Processus (PERE)%d de Pere %d\n", getpid(), getppid());
			// exit(0);
		} else { // Fils ret == 0
			fprintf(stderr,"Processus (FILS) %d de Pere %d\n", getpid(), getppid()); 
			// exit(0);
		}
	}
	sleep(30);
		
	return EXIT_SUCCESS;
}