/*!
 * \file 24.DoubleSyncrhoPereFils.c
 * \brief Programme de test pour la double synchronisation entre père et fils
 *
 * Programme qui teste la double synchronisation entre un processus père et un processus fils.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void gestionnaire (int sig);

int iter = 0;
int pid_pere;

int main(int argc, char **argv) {

    pid_t ret;
    pid_pere = getpid();

    ret = fork();

    if (ret < 0) {
        fprintf(stderr,"Erreur de Creation \n");
        exit(0);
    }

    else if (ret > 0) { // Pere

        fprintf(stderr,"Pere : PID = %d, PPID = %d \n", getpid(), getppid());
        if (signal(SIGUSR1, gestionnaire) == SIG_ERR) {
            fprintf(stderr,"Erreur association SIGUSR1 \n");
            exit(0);
        }
        sleep(1);
        /* --- Emetteur : SIGUSR1 toute les 5 s --- */
        while(1) {
            sleep(5);
            fprintf(stderr,"Père : PID = %d : SIGUSR1 envoyé : iteération %d \n", getpid(), iter++);
            system("date +\"%H:%M:%S:%N\"");
            kill(ret, SIGUSR1);
            exit(0);
        }
        exit(0);

    } else { // Fils ret == 0 
        fprintf(stderr,"Fils : PID = %d, PPID = %d \n", getpid(), getppid());
        if (signal(SIGUSR1, gestionnaire) == SIG_ERR) {
            fprintf(stderr,"Erreur association SIGUSR1 \n");
            exit(0);
        }
        sleep(1);
        while(1) {
            pause();
            sleep(5);
            fprintf(stderr,"Fils : PID = %d : SIGUSR1 envoyé : itération %d \n", getpid(), iter++);
            system("date +\"%H:%M:%S:%N\"");
            kill(pid_pere, SIGUSR1);
        }

        exit(0);
    }
        
    return EXIT_SUCCESS;
}


 void gestionnaire (int sig) {
    if (getpid() == pid_pere) {
        if (sig == SIGUSR1)
            fprintf(stderr,"Père : PID = %d : SIGUSR1 recu : itération %d \n", getpid(), iter++);
    } else {
        fprintf(stderr,"Fils : PID = %d : SIGUSR1 recu : itération %d \n", getpid(), iter++);
    }
    
    system("date +\"%H:%M:%S:%N\"");
}