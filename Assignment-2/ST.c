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
long long sic;

long long rdtsc(void) {
    long eax, edx;
    asm volatile("rdtsc\n\t": "=a" (eax), "=d" (edx));
    return (long long)eax | (long long)edx << 32;
}

void THANDLER() {
    printf("SIGTERM handled in ST.\n");
    printf("%lu sec\n", sic/(1800000000));
}

void AHANDLER(int signo) {
    union sigval Sigma;
    sic = rdtsc();
    Sigma.sival_int = sic;
    sigqueue(master, SIGTERM, Sigma);
    kill(getpid(), SIGTERM);
}


int main(int argc, char const *argv[]) {
    master = atoi(argv[0]);
    struct sigaction saction, saction2;
    struct itimerval time_it;
    time_it.it_value.tv_sec = 1;
    time_it.it_value.tv_usec = 1000;
    time_it.it_interval = time_it.it_value;
    memset(&saction, 0, sizeof(saction));
    memset(&saction2, 0, sizeof(saction2));
    saction.sa_handler = &AHANDLER;
    saction2.sa_handler = &THANDLER;
    sigaction(SIGALRM, &saction, NULL);
    sigaction(SIGTERM, &saction2, NULL);
    setitimer(ITIMER_REAL, &time_it, NULL);
    while (1 > 0) {
        int sum = 0;
        sum++;
    }
    return 0;

}