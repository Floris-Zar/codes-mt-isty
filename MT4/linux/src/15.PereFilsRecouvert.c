/*!
 * \file 15.PereFilsRecouvert.c
 * \brief Programme de test pour la création d'un processus fils et le recouvrement du processus fils par un autre programme
 *
 * Programme qui crée un processus fils, affiche les PID du père et du fils, puis le fils recouvre son image par celle d'un autre programme (Affiche).
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main (int argc, char **argv) {
	pid_t ret;

	/* --- Creation Processus Fils --- */
	ret = fork();
	if (ret < 0) {
		fprintf(stderr,"Erreur de Creation \n");
		exit(0);
	} else if (ret > 0) { // Pere
		fprintf(stderr,"Père %d de Père %d\n", getpid(), getppid());
		sleep(1);
		exit(0);
	} else { // Fils ret == 0
		fprintf(stderr,"Fils %d de Père %d\n", getpid(), getppid());
		execl("/home/isty/Isty2026/MT4/Linux/bin/Affiche", 
		"Affiche", "Bonjour", (char *)NULL);
		fprintf (stderr,"Fils : Terminaison  \n"); // <-- Cette ligne ne s'exécutera pas car le processus a été recouvert par execl
		exit(0);
	}
			
	return EXIT_SUCCESS;
}