/*!
 * \file Affiche.c
 * \brief Programme d'affichage d'informations sur le processus
 *
 * Programme qui affiche le PID, le PPID et un message passé en argument.
 * Est utilisé pour montrer le recouvrement du code 14.Recouvert.c
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char **argv) { 
	if (argc != 2) {
		fprintf(stderr, "USAGE : Affiche nom \n");
		exit(0);
	}
	fprintf(stderr,"Programme Affiche pid %d, ppid %d, affiche : %s\n",
		getpid(), getppid(), *++argv);
	return EXIT_SUCCESS;
}