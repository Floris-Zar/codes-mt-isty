/*!
 * \file 7.PereFilsMemSep.c
 * \brief Programme de test pour la séparation de la mémoire entre père et fils
 *
 * Le père et le fils modifient chacun une variable locale et une variable globale, puis affichent les valeurs de ces variables pour montrer que la mémoire est séparée entre les deux processus.
 */

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>

int glob=10;

int main (int argc, char **argv) { 
	pid_t ret;
	int loc=20;
	
	ret=fork();
	if (ret < 0) {
		fprintf(stderr,"Erreur de Creation \n");
		exit(0);
	} else if (ret > 0)	{ // Pere
		sleep(1);
		fprintf(stderr, "Pere Lecture Init : loc=%d, glob=%d\n",
			loc, glob);
		loc=15;
		glob=5;
		fprintf(stderr, "Pere Modifie : loc=%d, glob=%d\n",
			loc, glob);
		exit(0);
	} else { // Fils ret == 0
		fprintf(stderr, "Fils Lecture Init : loc=%d, glob=%d\n",
			loc, glob);
		loc=25;
		glob=15;
		fprintf(stderr, "Fils Modifie : loc=%d, glob=%d\n",
			loc, glob);
		
		sleep(2);
		fprintf(stderr, "Fils Lecture Finale : loc=%d, glob=%d\n",
			loc, glob);
		exit(0);
	}
		
	return EXIT_SUCCESS;
}

/* Affichage sur le temrinal :
Fils Lecture Init : loc=20, glob=10
Fils Modifie : loc=25, glob=15
Pere Lecture Init : loc=20, glob=10
Pere Modifie : loc=15, glob=5
*/