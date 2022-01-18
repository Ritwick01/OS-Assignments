#include <stdio.h>
#include <math.h>
void add(double a, double b) {
    printf("Addition of %lf and %lf = %lf\n", a, b, a+b);
}
void sub(double a, double b) {
    printf("Subtraction of %lf and %lf = %lf\n", a, b, a-b);
}
void mul(double a, double b) {
    printf("Multiplication of %lf and %lf = %lf\n", a, b, a*b);
}
void div(double a, double b) {
    printf("Division of %lf and %lf = %lf\n", a, b, a/b);
}
void expn(double a, double b) {
    printf("Exponentiation of %lf and %lf = %lf\n", a, b, pow(a,b));
}

int main() {
    void (*fnc_array[])(double, double) = {add, sub, mul, div, expn};
    int n;
    double n1, n2;
    printf("Enter first number: ");
    scanf(" %lf", &n1);
    printf("Enter second number: ");
    scanf(" %lf", &n2);
    printf("Please input the number for executing the function: \n");
    printf("1 for Addition \n");
    printf("2 for Subtraction \n");
    printf("3 for Multiplication \n");
    printf("4 for Division \n");
    printf("5 for Exponentiation \n");
    printf("Enter the number: ");
    scanf("%d", &n);
  
    (*fnc_array[n - 1])(n1, n2);
  
    return 0;
}