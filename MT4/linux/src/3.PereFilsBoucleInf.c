/*!
 * \file 3.PereFilsBoucleInf.c
 * \brief Exemple de création de processus père et fils avec boucle infinie
 *
 * Ce programme crée un processus père et un processus fils, chacun exécutant une boucle infinie.
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

	/* --- Création Processus Fils --- */
	ret = fork();
	if (ret < 0) {
		fprintf(stderr,"Erreur de Création \n");
		exit(0);
	}

	else if (ret > 0) { // Pere
		fprintf(stderr, "Père\n");
		
		Core = sched_getcpu();
		fprintf(stderr, "Père : PID = %d, PPID = %d sur coeur : %d ret : %d\n",
									getpid(), getppid(),		Core,	ret);
		while(1);
		exit(0);

	} else { // Fils ret == 0
		fprintf(stderr, "Fils \n");
		Core = sched_getcpu();
	 
		fprintf(stderr, "Fils : PID = %d, PPID = %d sur coeur : %d\n",
									getpid(), getppid(),	   Core);

		while(1);
		exit(0);

	}
		
	return EXIT_SUCCESS;
}