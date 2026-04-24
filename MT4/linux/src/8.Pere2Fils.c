/*!
 * \file 8.Pere2Fils.c
 * \brief Pere 2 fils
 *
 * Programme qui crée un processus père qui crée deux processus fils.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>

int main (int argc, char **argv) { 
	pid_t ret[2]; // ret = [pid_pere, pid_fils1, pid_fils2]
	
	fprintf(stderr,"Pere avant creation (A) pid : %d \n", getpid());
	
	ret[0] = fork();
	if (ret[0] < 0) {
		fprintf(stderr,"Erreur de Creation Fils1 \n");
		exit(0);
	} else if (ret[0] > 0) { // Pere
		fprintf(stderr,"Pere apres creation Fils1 (B) pid : %d, ret %d\n", getpid(), ret[0]);
			
		ret[1] = fork();
		if (ret[1] < 0)	{
			fprintf(stderr, "Erreur de Creation Fils2 \n");
			exit(0);
		}
		else if (ret[1] > 0) { // Pere
			fprintf(stderr,"Pere apres creation Fils2 (D) pid : %d, ret %d\n", 
				getpid(), ret[1]);
			while(1);
			exit(0);
		} // fin du pere
		else { // Fils2 ret == 0
			fprintf(stderr,"Fils2(E) pid : %d, ppid %d\n", getpid(), getppid());
			while(1);
			exit(0);
		} //  fils 2   
	} else { // Fils1 ret == 0
		fprintf(stderr, "Fils1 (C) pid : %d, ppid %d\n", getpid(), getppid());
		while(1);
		exit(0);
	} 	
	return EXIT_SUCCESS;
}