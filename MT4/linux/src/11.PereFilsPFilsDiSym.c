/*!
 * \file 11.PereFilsPFilsDiSym.c
 * \brief Pere 2 fils Di Symetrique
 *
 * Programme qui crée un processus père qui crée un processus fils, puis le processus fils crée un processus petit-fils. Le pèrele fils et le petit-fils sont en symétrie. Chacun affiche son PID et celui de son père. Le père attend la fin du fils, le fils attend la fin du petit-fils.
 *
 */

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>

int main (int argc, char **argv) {
	pid_t ret[2];
	fprintf(stderr,"Pere avant creation (A) pid : %d \n", getpid());
	
	/* --- Creation du Processus Fils --- */
	ret[0] = fork();
	if (ret[0] < 0) {
		fprintf(stderr,"Erreur de Creation \n");
		exit(0);
	} else if (ret[0] > 0) { // Pere
		fprintf(stderr,"Pere (B): pid %d, ret %d \n", getpid(), ret[0]);
		while(1);
		exit(0);
	}
	/* --- Fils --- */
	fprintf(stderr,"Fils apres creation Petit Fils (C) pid : %d, ppid : %d\n", getpid(), getppid());

	/* --- Creation du Processus Petit Fils --- */
	ret[1] = fork();
	if (ret[1] < 0) {
		fprintf(stderr,"Erreur de Creation \n");
		exit(0);
	} else if (ret[1] > 0) { // Fils
		fprintf(stderr,"Fils (D): pid %d, ret %d \n", getpid(), ret[1]);
		while(1);
		exit(0);
	}
	/* --- Petit Fils --- */
	fprintf(stderr,"Petit Fils (E) pid : %d, ppid : %d\n", getpid(), getppid());
	while(1);
		
	return EXIT_SUCCESS;
}


/* Affichage sur le terminal de 11.PereFilsPFilsDiSym.c :

Pere avant creation (A) pid : 742874 
Pere (B): pid 742874, ret 742875 
Fils apres creation Petit Fils (C) pid : 742875, ppid : 742874
Fils (D): pid 742875, ret 742876 
Petit Fils (E) pid : 742876, ppid : 742875

*/