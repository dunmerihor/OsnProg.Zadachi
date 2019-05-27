#include "stdio.h"
#include "math.h"


double Func(double x) {
    double y = (x - sin(x) - 0.25);
    return y;
}

double dFunc(double x) {
    double y = (1 - cos(x));
    return y;
}

int main() {
    double x;
    int n;
    printf("x = \n");
    scanf("%lf", &x);
    printf("Start point:\n");
    scanf("%d", &n);
    double x1 = 0;
    do {
        x1 = x;
        double f = Func(x);
        double df = dFunc(x);
        x = x - f/df;
    } while (fabsl(x1 - x) > pow(10, -n));
    printf("x = %lf\n", x);
    scanf("%d", &n);
    return 0;
}