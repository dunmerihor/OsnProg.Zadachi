#include <stdio.h>
#include "stdlib.h"
#include "math.h"

void Replace(int* pArr, int i) {
    int a = 0;
    a = *(pArr + i);
    *(pArr + i) = *(pArr + (i+1));
    *(pArr + (i+1)) = a;
}

int Compare1(int* pArr, int i) {
    int z = 0;
    if (*(pArr + i) >= *(pArr + (i+1)))
        z = 1;
    return z;
}

int Compare2(int* pArr, int i) {
    int z = 0;
    if (*(pArr + i) <= *(pArr + (i+1)))
        z = 1;
    return z;
}

void SortArr(int (*Compare)(int*, int), int SizeOfArr) {
    int* pArr;
    pArr = malloc(sizeof(int)*SizeOfArr);
    for(int i = 0; i < SizeOfArr; i++) {
        printf("Arr[%d]\n", i);
        scanf("%d", (pArr + i));
    }
    for (int i = 0; i < SizeOfArr; i++) {
        int flag = 0;
        for (int j = 0; j < (SizeOfArr - (i + 1)); j++) {
            int x = Compare(pArr, j);
            if (x == 1) {
                Replace(pArr, j);
                flag = 1;
            }
        }
        if (flag == 0) break;
    }
    for(int i = 0; i < SizeOfArr; i++) {
        printf("Arr[%d] %d \n", i, *(pArr + i));
    }
    free(pArr);
}

int main() {
    int (*Compare)(int* pArr, int x);
    int SortDir, SizeOfArr;
    printf("Sorting Direction\n");
    printf("1 - Ascending, 2 - Descending\n");
    scanf("%d", &SortDir);
    if (SortDir == 1)
        Compare = Compare1;
    else if (SortDir == 2)
        Compare = Compare2;
    else {
        printf("Incorrect input");
        return 1;
    }
    printf("Size of Array = \n");
    scanf("%d", &SizeOfArr);
    SortArr(Compare, SizeOfArr);
    return 0;
}