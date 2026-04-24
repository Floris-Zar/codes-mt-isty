/*!
 * \file 10.Pere2FilsDiSym.c
 * \brief Pere 2 fils Di Symetrique
 *
 * Programme qui crée un processus père qui crée deux processus fils. Le père et les fils sont en symétrie.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>

int main (int argc, char **argv) {
	pid_t ret[2];
	fprintf(stderr, "Pere avant creation (A) pid : %d \n", getpid());
	
	/* --- Creation du Processus Fils1 --- */
	ret[0] = fork();
	if (ret[0] < 0)	{
		fprintf(stderr,"Erreur de Creation \n");
		exit(0);
	} else if (ret[0] == 0) { // Fils1
		fprintf(stderr,"Fils1 (C): pid %d, ppid %d \n", getpid(), getppid());
		while(1);
		exit(0);
	}

	/* --- Père à nouveau --- */
	fprintf(stderr, "Pere apres creation Fils1 (B) pid : %d, ret : %d\n", getpid(), ret[0]);

	/* --- Creation du Processus Fils2 --- */
	ret[1] = fork();
	if (ret[1] < 0)	{
		fprintf(stderr, "Erreur de Creation \n");
		exit(0);
	} else if (ret[1] == 0) { // Fils2
		fprintf(stderr, "Fils2 (E): pid %d, ppid %d \n", getpid(), getppid());
		while(1);
		exit(0);
	}
	/* --- Père à nouveau --- */
	fprintf(stderr, "Père apres création Fils2 (D) pid : %d, ret : %d\n", getpid(), ret[1]);
	while(1);
		
	return EXIT_SUCCESS;
}


/* Affichage sur le terminal de 10.Pere2FilsDiSym.c :

Pere avant creation (A) pid : 741798 
Pere apres creation Fils1 (B) pid : 741798, ret : 741799
Père apres création Fils2 (D) pid : 741798, ret : 741800
Fils2 (E): pid 741800, ppid 741798 
Fils1 (C): pid 741799, ppid 741798

*/