/*!
 * \file 2.Sleep.c
 * \brief Exemple d'utilisation de la fonction sleep()
 *
 * Ce programme affiche son PID et son PPID, puis attend 20 secondes avant de se terminer.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char **argv) {
  fprintf(stderr,"PID = %d, PPID = %d \n", getpid(), getppid());
  sleep(20);
  fprintf(stderr,"Terminaison processus %d\n", getpid());  
  return EXIT_SUCCESS;
}