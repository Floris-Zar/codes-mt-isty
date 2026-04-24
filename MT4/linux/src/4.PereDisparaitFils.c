/*!
 * \file 4.PereDisparaitFils.c
 * \brief Exemple de création de processus père et fils avec disparition du père
 *
 * Ce programme crée un processus père et un processus fils, le père disparaît avant le fils.
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

	/* --- Creation Processus Fils --- */
	ret = fork();
	if (ret < 0) {
		fprintf(stderr,"Erreur de Creation \n");
		exit(0);

	} else if (ret > 0) { // Pere
		sleep(15); 
		fprintf(stderr,"Pere : Terminaison \n");
		exit(0);

	} else { // Fils ret == 0
		fprintf(stderr,"Fils \n");
		Core = sched_getcpu();
	 
		fprintf(stderr,"Fils : PID = %d, PPID = %d sur coeur : %d\n",
		getpid(), getppid(),Core);
		
		sleep(20);
		fprintf(stderr,"Fils Terminaison : PID = %d, PPID = %d sur coeur : %d\n",
		getpid(), getppid(),Core);
		
		exit(0);
	}
		
	return EXIT_SUCCESS;
}