/*!
 * \file 9.PereFilsPFils.c
 * \brief Programme de test pour la création d'un processus fils et petit-fils
 *
 * Programme qui crée un processus père qui crée un processus fils, puis le processus fils crée un processus petit-fils. Le père, le fils et le petit-fils affichent leur PID et celui de leur père.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>

int main (int argc, char **argv) {
	
	pid_t ret[2];
	
	fprintf(stderr,"Pere avant creation (A) pid : %d \n", getpid());
	
	ret[0] = fork();
	if (ret[0] < 0)	{
		fprintf(stderr,"Erreur de Creation Fils1 \n");
		exit(0);

	} else if (ret[0] == 0) { // Fils
		fprintf(stderr,"Fils avant creation Petit Fils (C) pid : %d, ppid %d\n", 
			getpid(), getppid());
			
		ret[1] = fork();
		if (ret[1] < 0)	{
			fprintf(stderr,"Erreur de Creation Fils2 \n");
			exit(0);
		} else if (ret[1] > 0) { // Fils
			fprintf(stderr,"Fils apres creation Petit Fils (D) pid : %d, ret %d\n", 
				getpid(), ret[1]);
			while(1);
			exit(0);
		} else { // Petit Fils ret == 0
			fprintf(stderr,"Petit Fils (E) pid : %d, ppid %d\n", 
				getpid(), getppid());
			while(1);
			exit(0);
		} //  fils 2  

	} else { // Pere
		fprintf(stderr,"Pere (B) pid : %d, ret %d\n", 
			getpid(), ret[0]);
		while(1);
		exit(0);
	} 	
	return EXIT_SUCCESS;
}

/* Affichage terminal de 9.PereFilsPFils.c :

Pere avant creation (A) pid : 741529 
Pere (B) pid : 741529, ret 741530
Fils avant creation Petit Fils (C) pid : 741530, ppid 741529
Fils apres creation Petit Fils (D) pid : 741530, ret 741531
Petit Fils (E) pid : 741531, ppid 741530

*/