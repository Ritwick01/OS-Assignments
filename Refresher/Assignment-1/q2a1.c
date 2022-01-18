#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void divide2(char in[], unsigned char rem[], int cnt, int more) {
    int n1 = strlen(in);
    if ((n1 <= strlen("256"))) {
        if (in[0] == -1)
            in[0] = 0;
        if (in[1] == -1)
            in[1] = 0;
        if (in[2] == -1)
            in[2] = 0;
        if (n1 == 3) {
            int n = 100*in[0] + 10*in[1] + in[2];
            if ((n/256) < 1) {
                rem[cnt] = n%256;
                return;
            }
        }

        else if (n1 == 2) {
            int n = 10*in[0] + 1*in[1];
            if ((n/256) < 1) {
                rem[cnt] = n%256;
                return;
            }
        }

        else if (n1 == 1) {
            int n = 1*in[0];
            if ((n/256) < 1) {
                rem[cnt] = n%256;
                return;
            }
        }
    }
    char quot[159] = {0};
    char result[159] = {0};
    int mod = 0;
    int i = 0;
    for (; i < n1; i++) {
        if (in[i] == -1)
            in[i] = 0;
        int digit = in[i];
        mod = mod * 10 + digit;
        int quo = mod / 256;
        quot[159 - n1 + i] = quo; 
        mod = mod % 256;
    }
    
    bool flag = false;
    int store = 0;
    for (int j = 0; j < 159; j++) {
        if (quot[j] == 0 && flag == false) {
            store = j + 1;
            continue;
        }
        flag = true;
        if (quot[j] == 0) 
            quot[j] = -1;
        result[j - store] = quot[j];
    }
    
    rem[cnt] = mod;
    cnt -= 1;
    divide2(result, rem, cnt, more);

}

void divide(char in[], unsigned char rem[], int cnt, int more) {
    char quot[159] = {0};
    char result[159] = {0};
    int mod = 0;
    int i = 0;
    for (; i < strlen(in); i++) {
        int digit = in[i] - '0';
        mod = mod * 10 + digit;
        int quo = mod / 256;
        quot[159 - strlen(in) + i] = quo; 
        mod = mod % 256;
    }
    
    bool flag = false;
    int store = 0;
    for (int j = 0; j < 159; j++) {
        if (quot[j] == 0 && flag == false) {
            store = j + 1;
            continue;
        }
        flag = true;
        if (quot[j] == 0) 
            quot[j] = -1;
        result[j - store] = quot[j];
    }
    
    rem[cnt] = mod;
    cnt -= 1;
    divide2(result, rem, cnt, more);

}

void add(unsigned char add1[], unsigned char add2[], unsigned char res[]) {
    int carry = 0;
    for (int i = 31; i >= 0; i--) {
        int temp = add1[i] + add2[i] + carry;
        if (temp > 255) {
            temp -= 256;
            carry = 1;
        }
        else {
            carry = 0;
        }
        res[i] = temp;
    }

}


int main() {
    char input1[159];
    int count = 31;
    unsigned char remain1[32] = {0};
    char input2[159];
    unsigned char remain2[32] = {0};
    unsigned char result[32] = {0};
    printf("Enter number1: ");
    scanf("%s", input1);
    printf("\nEnter number2: ");
    scanf("%s", input2);
    divide(input1, remain1 ,count, 0);
    divide(input2, remain2 ,count, 0);
    for (int i = 0; i <= 31; i++) {
        printf(" %d", remain1[i]);
    }
    printf("\n");
    for (int i = 0; i <= 31; i++) {
        printf(" %d", remain2[i]);
    }
    printf("\n");
    add(remain1, remain2, result);
    for (int i = 0; i <= 31; i++) {
        printf(" %d", result[i]);
    }
    return 0;
}