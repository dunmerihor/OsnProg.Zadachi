#include "stdio.h"
#include "math.h"

int main() {
	int N;
	scanf("%d", &N);
	int i = 2;
	while (i <= N) {
		int border = sqrt(i);
		int j = 1;
		while (j <= border) {
			if ((i % j == 0) && (j != 1))
				break;
			if (j == border) {
				printf("%d\n", i);
			}
			j++;
		}
		i++;
	}
	scanf("%d", &N);
	return 0;
}