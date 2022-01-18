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

pid_t master;

int GETRAND() {
    int rand = -1;
    int i=0;
    int tout = 50;
    while (i < tout) {
        asm("rdrand %0" :"=a"(rand)::);
        if (rand) 
            break;
        i++;
    }
    return rand;
}

void AHANDLER(int signo) {
    union sigval Sigma;
    Sigma.sival_int = GETRAND();
    sigqueue(master, SIGTERM, Sigma);
}

int main(int argc, char const *argv[]) {
    master = atoi(argv[0]);
    struct sigaction saction;
    struct itimerval time_it;
    time_it.it_value.tv_sec = 1;
    time_it.it_value.tv_usec = 1000;
    memset(&saction, 0, sizeof(saction));
    saction.sa_handler = &AHANDLER;
    sigaction(SIGALRM, &saction, NULL);
    setitimer(ITIMER_REAL, &time_it, NULL);
    while (1 > 0) {
        int sum = 0;
        sum++;
    }
    return 0;

}