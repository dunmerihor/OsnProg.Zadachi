#include <stdio.h>
#include "math.h"

#define MAX_SIZE 100
int arrsize;
int arr[MAX_SIZE];

int Minimum(int arr[MAX_SIZE]) {
    int* pElem = arr;
    int min = 0;
    for (int i = 0; i < arrsize; i++) {
        for (int j = 0; j < arrsize; j++) {
            if (*(pElem + i) > *(pElem + j))
                break;
            else if (j + 1 == arrsize)
                min = *(pElem + i);
        }
    }
    return min;
}

int Maximum(int arr[MAX_SIZE]) {
    int* pElem = arr;
    int max = 0;
    for (int i = 0; i < arrsize; i++) {
        for (int j = 0; j < arrsize; j++) {
            if (*(pElem + i) < *(pElem + j))
                break;
            else if (j + 1 == arrsize)
                max = *(pElem + i);
        }
    }
    return max;
}

float Mean(int arr[MAX_SIZE]) {
    int summ = 0;
    for (int i = 0; i < arrsize; i++)
        summ = summ + arr[i];
    return ((float)summ/arrsize);
}

float RMS(int arr[MAX_SIZE]) {
    float summ = 0;
    float mean = Mean(arr);
    for (int i = 0; i < arrsize; i++)
        summ = summ + powf((arr[i] - mean), 2);
    return (sqrtf(summ/arrsize));
}

int main() {
    printf("Max size of array is %d\n", MAX_SIZE);
    printf("Amount of elements\n");
    scanf("%d", &arrsize);
    if (arrsize > MAX_SIZE) {
        printf("Max size of array is %d\n", MAX_SIZE);
        return 0;
    }
    for (int i = 0; i < arrsize; i++) {
        printf("arr[%d]\n", i);
        scanf("%d", &arr[i]);
    }
    printf("Min = %d\n", Minimum(arr));
    printf("Max = %d\n", Maximum(arr));
    printf("Mean = %f\n", Mean(arr));
    printf("RMS = %f\n", RMS(arr));
    return 0;
}