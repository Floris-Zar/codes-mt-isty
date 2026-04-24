/*!
 * \file 6.PereFilsFichier.c
 * \brief Création d'un processus fils et l'écriture dans un fichier
 *
 * Programme avec processus père et fils écrivant dans un même fichier.
 */

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>

int main (int argc, char **argv) {
	int Core;
	pid_t ret;
	FILE *fp;

	Core = sched_getcpu();
	fprintf(stderr,"Nombre CPU : %d\n", sysconf(_SC_NPROCESSORS_ONLN));
	fprintf(stderr,"PID = %d, PPID = %d sur coeur : %d\n",
		getpid(), getppid(), Core);

	/* --- Création du fichier --- */
	if ((fp = fopen ("Toto.txt","w")) == NULL) {
		fprintf(stderr,"Erreur d'Ouverture \n");
		exit (0);
	}

	/* --- Création Processus Fils --- */
	ret = fork();
	if (ret < 0) {
		fprintf(stderr,"Erreur de Creation \n");
		exit(0);
	} else if (ret > 0) { // Pere
		fprintf(fp, "Père : \n");
		sleep(5);
		fclose (fp);
		exit(0);
	} else { // Fils ret == 0
		fprintf(fp, "Fils : \n");
		exit(0);
	}
		
	return EXIT_SUCCESS;
}