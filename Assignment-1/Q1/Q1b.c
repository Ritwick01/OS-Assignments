#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdbool.h>
#include<pthread.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<errno.h>
#include<string.h>

double forA[7] = {0};
double forB[7] = {0};

void* averageoutA(void* arg) {
    double amarks[6] = {0};
    char chr;
    char string[10000];
    int count = 1;
    int temp = 0;
    char *sec = "\r";
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
                if (strcmp(token, "A") == 0) {
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
            printf("Average Marks of Section A in Assignment %d = %lf" , i+1, amarks[i]/n);
            printf("\n");
            forA[i] = amarks[i];

        }
        forA[6] = n;
    
    
    
    printf("\n");
    
    
}

void* averageoutB(void* arg) {
    double amarks[6] = {0};
    char chr;
    char string[10000];
    int count = 1;
    int temp = 0;
    char *sec = "\r";
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
                if (strcmp(token, "B") == 0) {
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
            printf("Average Marks of Section B in Assignment %d = %lf" , i+1, amarks[i]/n);
            printf("\n");
            forB[i] = amarks[i];
        }
        forB[6] = n;
    
    
    printf("\n");
    
    
}

int main(int argc, char *argv[]) {
    pthread_t thd1;
    pthread_t thd2;
    if (pthread_create(&thd1, NULL,&averageoutA, NULL) != 0) {
        printf("Error reporting.\n");
        exit(1);
    }

    if (pthread_join(thd1,NULL)) {
        printf("Error reporting.\n");
        exit(1);
    }

    if (pthread_create(&thd2, NULL,&averageoutB, NULL) != 0) {
        printf("Error reporting.\n");
        exit(1);
    }
    
    if (pthread_join(thd2,NULL)) {
        printf("Error reporting.\n");
        exit(1);
    }

    for (int i = 0; i < 6; i++) {
            printf("Average Marks in Assignment %d = %lf" , i+1, (forA[i] + forB[i])/(forA[6] + forB[6]));
            printf("\n");
    }
    
    

}