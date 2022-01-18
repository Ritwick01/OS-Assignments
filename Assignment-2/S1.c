#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<wait.h>
#include<sys/time.h>
#include<time.h>
#include<signal.h>
#include<stdint.h>
#include<inttypes.h>
#include<string.h>

void HANDLER(int signumber, siginfo_t* Si, void* ucontext) {
    int randvar = Si->si_value.sival_int;
    pid_t rpid = Si->si_pid;
    printf("Sigterm handled\nPid received %d\nRandom value obtained %d\n", rpid, randvar);
}

int main(int argc, char const *argv[])
{
    pid_t S1 = fork();
    if (S1 > 0) {       
        pid_t ST = fork();
        if (ST > 0) {
            pid_t SR = fork();
            if (SR > 0) {
                printf("IN SR\n");
                while (1 > 0) {
                    int sum = 0;
                    sum++;
                } 
            }
            else {
                if (SR == 0) {
                    char StringS1[15];
                    sprintf(StringS1, "%d", S1);        
                    execl("SR", StringS1, NULL);
                }
                else {
                    printf("Error occured : Could not produce child");
                }
            }
        }
        else {
            if (ST == 0) {
                char StringS1[15];
                sprintf(StringS1, "%d", S1);        
                execl("ST", StringS1, NULL);
            }
            else {
                printf("Error occured : Could not produce child");
            }
        }
    }
    else {
        if (S1 == 0) {
            struct sigaction sigact;
            memset(&sigact, 0, sizeof(sigact));
            sigact.sa_flags = SA_SIGINFO;
            sigact.sa_sigaction = &HANDLER;
            sigaction(SIGTERM, &sigact, NULL);
            while (1 > 0) {
                int sum = 0;
                sum++;
            } 
        }
        else {
            printf("Error occured : Could not produce child");
        }
    }
    return 0;
}
