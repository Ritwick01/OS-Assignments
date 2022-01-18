#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include <stdbool.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<errno.h>
#include<string.h>

void hello() {
    printf("Function C here.");
    exit(0);
}