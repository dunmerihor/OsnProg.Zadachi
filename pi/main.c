#include "stdio.h"
#include "math.h"

int main() {
    int n;
    scanf("%d", &n);
    int i = 3;
    int j = -1;
    double slag = 0;
    double pi = 4;
    do {
        slag = 4. / i;
        pi = pi + j * slag;
        j = j * (-1);
        i = i + 2;
    } while (slag > pow(10, (-(n+1))));
    printf("%.*f\n", n, pi);
    scanf("%d", &n);
    return 0;
}
