#include <stdio.h>
#include "stdlib.h"
#include "math.h"
#include "string.h"

#define MAX_STR_SIZE 100

void DelSpaceBehind(char Str[MAX_STR_SIZE], int a) {
    for(int i = a; Str[i] != '\0'; i++) {
        Str[i-1] = Str[i];
    }
}

void DelSpace(char Str[MAX_STR_SIZE], int a) {
    for(int i = a; Str[i] != '\0'; i++) {
        Str[i] = Str[i+1];
    }
}

void AddSpace(char Str[MAX_STR_SIZE], int a) {
    char hold;
    for(int i = a; i != '\0'; i++) {
        if (i == a) {
            hold = Str[i];
            Str[i] = ' ';
        }
        else if (Str[i+1] == '\0') {
            char hold1 = Str[i];
            Str[i] = hold;
            Str[i+1] = hold1;
            Str[i+2] = '\0';
            break;
        }
        else {
            char hold1 = Str[i];
            Str[i] = hold;
            hold = hold1;
        }
    }
}

int main() {
    char Str[MAX_STR_SIZE];
    char* pStr = &(Str[0]);
    printf("Max size of string %d\n", (MAX_STR_SIZE));
    gets(Str);
    int length = strlen(Str);
    for(int i = 0; *(pStr + i) != '\0'; i++) {
        if (((i == 0) || (*(pStr + (i-2)) == '.')) && ((*(pStr + i) >= 'a') && (*(pStr + i) <= 'z'))) {    /*Замена маленькой буквы на большую*/
            *(pStr+i) -= 32;
        }
        else if ((*(pStr + i) == ' ') && (*(pStr + i-1) == ' ')) {                             /*Удаление нескольких проблелов следующих подряд*/
            DelSpace(Str, i);
            i--;
        }
        else if (((*(pStr + i) == ',') || (*(pStr + i) == '.')) && (*(pStr + (i-1)) == ' ')) {     /*Удаление пробелов перед точкой или запятой*/
            DelSpaceBehind(Str, i);
            i--;
        }
        else if (((*(pStr+(i-1)) == '.') || (*(pStr+(i-1)) == ',')) && (*(pStr+i) != ' ')) {       /*Добавление пробела после точки или запятой*/
            length++;
            if (length > MAX_STR_SIZE) {
                printf("Error. Max string size");
            }
            AddSpace(Str, i);
            i--;
        }
    }
    printf("%s", Str);
    return 0;
}