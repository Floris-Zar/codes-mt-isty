/*!
 * \file 13.PereFilsWait.c
 * \brief Pere Fils et Wait
 *
 * Programme qui crée un processus fils. Le père affiche son PID et celui de son père, puis attend la fin du fils. Le fils affiche son PID et celui de son père, puis termine.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int argc, char **argv) {
	pid_t ret;
	int retWait;

	ret = fork();
	if (ret < 0) {
		fprintf(stderr,"Erreur de Creation \n");
		exit(0);
	} else if (ret > 0)	{ // Pere
		fprintf(stderr,"Pere %d de Père %d\n",
				getpid(), getppid());
		sleep(2);
		fprintf (stderr,"Père : Arrivee\n");
		system("date +\"%H:%M:%S:%N\"");
		wait (&retWait);
		fprintf (stderr,"Père : Terminaison\n");
		system("date +\"%H:%M:%S:%N\"");
		exit(0);

	} else { // Fils ret == 0
		fprintf(stderr,"Fils %d de Pere %d\n",
			getpid(), getppid());
		sleep(10); 
		fprintf (stderr,"Fils : Terminaison  \n"); 
		system("date +\"%H:%M:%S:%N\"");
		exit(0);
	}
		
	return EXIT_SUCCESS;
}

