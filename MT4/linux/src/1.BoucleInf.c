/*!
 * \file 1.BoucleInf.c
 * \brief Boucle infinie
 *
 * Programme qui affiche le nombre de CPU et le coeur sur lequel il s'exécute, puis entre dans une boucle infinie.
 *
 */


#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>


int main (int argc, char **argv) {

	int oldCore, newCore;
	oldCore = sched_getcpu();

	fprintf(stderr,"Nombre CPU : %d\n", sysconf(_SC_NPROCESSORS_ONLN));
	fprintf(stderr,"PID = %d, PPID = %d sur coeur : %d\n", getpid(), getppid(),	oldCore);

	while(1) {
		newCore = sched_getcpu();
		if (newCore != oldCore) {
			oldCore = newCore;
			fprintf (stderr,"Transition %d => %d \n", oldCore, newCore);
		}
	}

	return EXIT_SUCCESS;
}