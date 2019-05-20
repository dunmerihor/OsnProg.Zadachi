#include <stdio.h>
#include "math.h"

double Func(double x) {
    return (pow(x, 3) - exp(x) + 1);
}

int main() {
    double a, b, I;
    printf("Enter a and b:\n");
    scanf("%lf%lf", &a, &b);
    int N;
    I = 0;
    printf("Enter N:\n");
    scanf("%d", &N);
    for (int i = 0; i <= N; i++) {
        double x, x1;
        x = a + i*((b-a)/N);
        x1 = a + (i+1)*((b-a)/N);
        I = I + (Func(x) + Func(x1))/2;
    }
    I = ((b - a)/N)*I;
    printf("I = %lf", I);
    return 0;
}