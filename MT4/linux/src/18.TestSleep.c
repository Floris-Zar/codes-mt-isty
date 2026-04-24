/*!
	\file 18.TestSleep.c
	\brief Programme de test pour la fonction sleep
	*
	* Programme qui teste la fonction sleep en attendant un certain temps.
	* 
	*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void gestionnaire (int sig);

int main (int argc, char **argv) {
	unsigned int duree= 60;
	fprintf(stderr,"Recepteur pid = %d\n", getpid());

	if (signal(SIGUSR1, gestionnaire) == SIG_ERR) {
		fprintf(stderr,"Erreur association SIGUSR1 \n");
		exit(0);
	}
	
	fprintf(stderr, "Debut Sleep \n");
	system("date +\"%H:%M:%S:%N\"");
	
	do
		duree = sleep(duree);
	while (duree > 0);
	
	fprintf(stderr, "Fin Sleep : reste a dormir %d \n", duree);
	system("date +\"%H:%M:%S:%N\"");
	
	return EXIT_SUCCESS;
}

void gestionnaire (int sig) {
	if (sig == SIGUSR1)
		fprintf(stderr,"SIGUSR1 recu \n");
	
	system("date +\"%H:%M:%S:%N\"");
}