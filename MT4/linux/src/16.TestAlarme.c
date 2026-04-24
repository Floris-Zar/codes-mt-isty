/*!
 * \file 16.TestAlarme.c
 * \brief Test du Signal SIGALRM
 * 
 * Programme qui utilise la fonction alarm pour déclencher une alarme après un certain temps. Le programme affiche l'heure avant de déclencher l'alarme, puis attend un certain temps avant d'afficher l'heure à nouveau. Si le temps d'attente dépasse la durée de l'alarme, le processus est détruit par le signal SIGALRM.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main (int argc, char **argv) { 
#if 0 
	// Sans Interferences
	fprintf(stderr,"Alarme : \n");
	system("date +\"%H:%M:%S:%N\"");
	alarm (10);
	sleep (3);
	fprintf(stderr,"Fin Processus : \n");
	system("date +\"%H:%M:%S:%N\"");
#endif

	// Avec Interferences => destruction du processus
	fprintf(stderr,"Alarme : \n");
	system("date +\"%H:%M:%S:%N\"");
	alarm (10);
	sleep (20);
	fprintf(stderr,"Fin Processus : \n");
	system("date +\"%H:%M:%S:%N\"");

	return EXIT_SUCCESS;
}