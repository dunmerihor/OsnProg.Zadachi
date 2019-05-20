#include "stdio.h"
#include "stdlib.h"
#include "math.h"


float minor(float data[3][3], int a, int b) {
    float Minor[2][2];
    int Str = 0;
    int Stl = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if (i != a && j != b) {
                if (Stl == 2) {
                    Stl = 0;
                    Str++;
                }
                Minor[Str][Stl] = data[j][i];
                Stl++;
            }
        }
    }
    return (Minor[0][0]*Minor[1][1]-Minor[0][1]*Minor[1][0]);
}

float determinant(float data[3][3]) {
    float Slag1 = data[0][0]*data[1][1]*data[2][2];
    float Slag2 = data[1][0]*data[2][1]*data[0][2];
    float Slag3 = data[0][1]*data[1][2]*data[2][0];
    float Slag4 = (-1)*data[0][2]*data[1][1]*data[2][0];
    float Slag5 = (-1)*data[1][2]*data[2][1]*data[0][0];
    float Slag6 = (-1)*data[1][0]*data[0][1]*data[2][2];
    return (Slag1+Slag2+Slag3+Slag4+Slag5+Slag6);
}

void sum(float data[3][3]) {
    float Matrix2[3][3];
    float Result[3][3];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("[%d][%d]\n", (j+1), (i+1));
            scanf("%f", &Matrix2[i][j]);
        }
    }
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Result[i][j] = data[i][j]+Matrix2[i][j];
        }
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%.0f\t", Result[i][j]);
        }
        printf("\n");
    }
    FILE *fp;
    if((fp = fopen("SumResult.txt", "w")) == NULL) {
        printf("Can't open file");
        return;
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            fprintf(fp, "%f\t", Result[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

void mult(float data[3][3]) {
    float Matrix2[3][3];
    float Result[3][3];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("[%d][%d]\n", (i+1), (j+1));
            scanf("%f", &Matrix2[i][j]);
        }
    }
    float Sum = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            for(int Stl = 0; Stl < 3; Stl++) {
                Sum = Sum+data[i][Stl]*Matrix2[Stl][j];
            }
            Result[i][j] = Sum;
            Sum = 0;
        }
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%.0f\t", Result[i][j]);
        }
        printf("\n");
    }
    FILE *fp;
    if((fp = fopen("MultiplicationResult.txt", "w")) == NULL) {
        printf("Can't open file");
        return;
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            fprintf(fp, "%f\t", Result[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

void inverse(float data[3][3]) {
    float InvData[3][3];
    float Det = determinant(data);
    if (Det == 0) {
        printf("Inverse matrix does not exist\n");
        return;
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            InvData[i][j] = (1/Det)*powf(-1,(i+1)+(j+1))*minor(data, i, j);
        }
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%f\t", InvData[i][j]);
        }
        printf("\n");
    }
    FILE *fp;
    if((fp = fopen("InverseMatrix.txt", "w")) == NULL) {
        printf("Can't open file");
        return;
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            fprintf(fp, "%f\t", InvData[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

int main() {
    FILE *fp;
    if((fp = fopen("Matrix.txt", "r")) == NULL) {
        printf("Can't open file");
        return 0;
    }
    float data[3][3];
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            fscanf(fp, "%f", &data[i][j]);
        }
    }
    fclose(fp);
    printf("Source Matrix:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%f\t", data[i][j]);
        }
        printf("\n");
    }
    float Det = determinant(data);
    printf("Determinant = %.0f\n", Det);
    printf("Inverse Matrix:\n");
    inverse(data);
    printf("Multiplication:\n");
    mult(data);
    printf("Sum:\n");
    sum(data);
    scanf("%f", &data[0][0]);
    return 0;
}