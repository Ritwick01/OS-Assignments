#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdbool.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<errno.h>
#include<string.h>
#include "C.c"

extern void funcB(int64_t arg);

void funcA() {
    printf("Mike Testing from Function A\n");
    int64_t n = 1283768152851;
    funcB(n);
}

int main(int argc, char *argv[]) {
    funcA();
    return 0;
}