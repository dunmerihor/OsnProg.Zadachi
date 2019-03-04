#include "stdio.h"
#include "math.h"

int main() {
    float a, b, c;
    printf("ax^2+bx+c=0\n");
    printf("a = ");
    scanf("%f", &a);
    printf("b = ");
    scanf("%f", &b);
    printf("c = ");
    scanf("%f", &c);
    if (a == 0 && b == 0 && c == 0) {
        printf("Incorrect input\n");
    } else if (a == 0 && b != 0) {
        printf("x = %f\n", (-c) / b);
    } else if (a != 0) {
        float D = b * b - 4 * a * c;
        if (D > 0) {
            printf("x1 = %f\n", ((-b) + sqrtf(D)) / (2 * a));
            printf("x2 = %f\n", ((-b) - sqrtf(D)) / (2 * a));
        } else if (D == 0) {
            printf("x = %f\n", ((-b) / (2 * a)));
        } else {
            printf("No Real roots\n");
        }
    }
    scanf("%f", &a);
    return 0;
}