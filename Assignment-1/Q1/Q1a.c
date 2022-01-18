#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdbool.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<errno.h>
#include<string.h>

void averageout(char *sect) {
    double amarks[6] = {0};
    char chr;
    char string[10000];
    int count = 1;
    int temp = 0;
    int file = open("student_record.csv", O_RDONLY);
    if (file == -1) {
        printf("File cannot be opened");
        exit(0);
    }
    int n = 0;
    while (read(file, &chr, 1) > 0) {
        temp++;
        if (chr == '\n') {
            string[temp] = '\0';
            if (count > 1) {
                char *token = strtok(string, ",");
                token = strtok(NULL, ",");
                if (strcmp(token, sect) == 0) {
                    n++;
                    token = strtok(NULL, ",");
                    for (int i = 0; token != NULL; i++) {
                        amarks[i] += atof(token);
                        token = strtok(NULL, ",");
                        
                    }
                }
            }
            count++;
            temp = 0;
        }
        if (count > 1) {
            string[temp] = chr;
            
        }
    }
    for (int i = 0; i < 6; i++) {
        printf("Average Marks of Section %s in Assignment %d = %lf" , sect, i+1, amarks[i]/n);
        printf("\n");
    }
    if (close(file) < 0)
    {
        printf("Error in closing the file");
        exit(1);
    }
    
}

int main(int argc, char *argv[]) {
    pid_t pid = fork();
    if (pid < 0) {
        printf("Creation of child class failed.");
        exit(1);
    }
    else if (pid == 0) {
        averageout("A");
    }
    else {
        waitpid(pid, NULL, 0);
        averageout("B");
    }
}