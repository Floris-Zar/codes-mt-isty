// Pere Disparait, Fils rattaché au processus Init
/*!
 * \file 5.PereFilsZombie.c
 * \brief Programme qui crée un processus fils qui termine avant le père, créant ainsi un processus zombie.
 *
 * Ce programme illustre la création d'un processus fils qui termine avant le processus père, ce qui entraîne la création d'un processus zombie. Le père attend ensuite que le fils termine pour éviter de laisser un processus zombie.
 *
 */

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>

int main (int argc, char **argv) {
	int Core;
	pid_t ret;

	Core = sched_getcpu();

	fprintf(stderr,"Nombre CPU : %d\n", sysconf(_SC_NPROCESSORS_ONLN));
	fprintf(stderr,"PID = %d, PPID = %d sur coeur : %d\n",
		getpid(), getppid(), Core);

	ret = fork();
	
	if (ret < 0) {
		fprintf(stderr,"Erreur de Creation \n");
		exit(0);
	} else if (ret > 0)	{ // Pere
		while(1);
		exit(0);
	} else { // Fils ret == 0
		sleep(15);
		fprintf(stderr,"Fils Terminaison : \n");
		exit(0);
	}
		
	return EXIT_SUCCESS;
}