#include <stdio.h>
#include "stdlib.h"
#include "math.h"

int Minimum(int* pArr, int SizeOfArray) {
    int min = 0;
    for (int i = 0; i < SizeOfArray; i++) {
        for (int j = 0; j < SizeOfArray; j++) {
            if (pArr[i] > pArr[j])
                break;
            else if (j + 1 == SizeOfArray)
                min = pArr[i];
        }
    }
    return min;
}

int Maximum(int* pArr, int SizeOfArray) {
    int max = 0;
    for (int i = 0; i < SizeOfArray; i++) {
        for (int j = 0; j < SizeOfArray; j++) {
            if (pArr[i] < pArr[j])
                break;
            else if (j + 1 == SizeOfArray)
                max = pArr[i];
        }
    }
    return max;
}

float Mean(int* pArr, int SizeOfArray) {
    int summ = 0;
    for (int i = 0; i < SizeOfArray; i++)
        summ = summ + *(pArr + i);
    return ((float)summ/SizeOfArray);
}

float RMS(int* pArr, int SizeOfArray) {
    float summ = 0;
    float mean = Mean(pArr, SizeOfArray);
    for (int i = 0; i < SizeOfArray; i++)
        summ = summ + powf((*(pArr + i) - mean), 2);
    return (sqrtf(summ/SizeOfArray));
}



int main() {
    int SizeOfArr;
    printf("Amount of elements\n");
    scanf("%d", &SizeOfArr);
    int* pArr;
    pArr = malloc(sizeof(int)*SizeOfArr);
    for(int i = 0; i < SizeOfArr; i++) {
        printf("m[%d]\n", i);
        scanf("%d", (pArr + i));
    }
    printf("Min = %d\n", Minimum(pArr, SizeOfArr));
    printf("Max = %d\n", Maximum(pArr, SizeOfArr));
    printf("Mean = %f\n", Mean(pArr, SizeOfArr));
    printf("RMS = %f\n", RMS(pArr, SizeOfArr));
    free(pArr);
    return 0;
}