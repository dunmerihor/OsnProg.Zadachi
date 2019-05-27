#include <stdio.h>
#include "stdlib.h"
#include "math.h"
#include "string.h"

char* AddMemory(char* pStr, int length) {
    char* pStr1 = pStr;
    pStr = malloc(sizeof(char)*(length+1));
    for(int i = 0; i != length; i++) {
        *(pStr + i) = *(pStr1 + i);
    }
    *(pStr + (length)) = '\0';
    return pStr;
}

void DelSpaceBehind(char* pStr, int a) {
    for(int i = a; *(pStr + i) != '\0'; i++) {
        *(pStr + (i - 1)) = *(pStr + i);
    }
}

void DelSpace(char* pStr, int a) {
    for(int i = a; *(pStr + i) != '\0'; i++) {
        *(pStr + i) = *(pStr + (i + 1));
    }
}

void AddSpace(char* pStr, int a) {
    char hold;
    for(int i = a; i != '\0'; i++) {
        if (i == a) {
            hold = *(pStr + i);
            pStr[i] = ' ';
        }
        else if (pStr[i+1] == '\0') {
            char hold1 = *(pStr + i);
            *(pStr + i) = hold;
            *(pStr + (i + 1)) = hold1;
            *(pStr + (i + 2)) = '\0';
            break;
        }
        else {
            char hold1 = *(pStr + i);
            *(pStr + i) = hold;
            hold = hold1;
        }
    }
}

char* GetText(FILE* stream, char terminator) {
  char* pStr;
  pStr = malloc(sizeof(char)*20);
  char d = getc(stream);
  *pStr = getc(stream);
  int k = 1;
  for(int i = 1; *(pStr + i) != terminator; i++) {
      if (i % 20 == 0) {
          k++;
          char* pStr1 = pStr;
          pStr = malloc(sizeof(char)*20*k);
          for(int j = 0; j != i; j++) {
              *(pStr + j) = *(pStr1 + j);
          }
      }
      *(pStr + i) = getc(stream);
      if (*(pStr + i) == terminator) {
          break;
      }
  }
  int NumbOfSymb = 0;
  for(int i = 0; *(pStr + i) != terminator; i++) {
      NumbOfSymb++;
  }
  char* pStr1 = pStr;
  pStr = malloc(sizeof(char)*(NumbOfSymb+1));
  for(int i = 0; i != NumbOfSymb; i++) {
      *(pStr + i) = *(pStr1 + i);
  }
    *(pStr + (NumbOfSymb)) = '\0';
    return pStr;
}


int main() {
    char* pStr;
    printf("In end of the string print '#'\n");
    printf("1 - read from file, 2 - read from console\n");
    int n;
    scanf("%d", &n);
    if (n == 1) {
        FILE *fp;
        if((fp = fopen("String.txt", "r")) == NULL) {
            printf("Can't open file");
            return 0;
        }
        pStr = GetText(fp, '#');
    }
    else if(n == 2) {
        pStr = GetText(stdin, '#');
    }
    else {
        printf("ERROR");
        return 1;
    }
    int length = strlen(pStr);
    for(int i = 0; *(pStr + i) != '\0'; i++) {
        if (((i == 0) || (*(pStr + (i-2)) == '.')) && ((*(pStr + i) >= 'a') && (*(pStr + i) <= 'z'))) {    /*Замена маленькой буквы на большую*/
            *(pStr+i) -= 32;
        }
        else if ((*(pStr + i) == ' ') && (*(pStr + i-1) == ' ')) {                             /*Удаление нескольких проблелов следующих подряд*/
            DelSpace(pStr, i);
            i--;
        }
        else if (((*(pStr + i) == ',') || (*(pStr + i) == '.')) && (*(pStr + (i-1)) == ' ')) {     /*Удаление пробелов перед точкой или запятой*/
            DelSpaceBehind(pStr, i);
            i--;
        }
        else if (((*(pStr+(i-1)) == '.') || (*(pStr+(i-1)) == ',')) && (*(pStr+i) != ' ')) {       /*Добавление пробела после точки или запятой*/
            AddMemory(pStr, length);
            AddSpace(pStr, i);
            i--;
        }
    }
    printf("%s", pStr);
    return 0;
}