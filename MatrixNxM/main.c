#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"

#define MAX 0
#define MIN -100


typedef struct {
    int Height;
    int Width;
    float* pMat;
} Matrix;

void GeneratingMatrix(Matrix Data) {
    srand(time(NULL));
    for(int i = 0; i < Data.Height; i++) {
        for(int j = 0; j < Data.Width; j++) {
//            scanf("%f", (Data.pMat + j + (i * Data.Width)));
            *(Data.pMat + j + (i * Data.Width)) = (rand() % (MAX - MIN + 1) + MAX);
        }
    }
}

void Minor(Matrix Data, Matrix Data1, int a, int b) {
    int Stl = 0;
    int Str = 0;
    for(int i= 0; i < Data.Width; i++) {
        for (int j = 0; j < Data.Height; j++) {
            if (i != a && j != b) {
                if (Stl == Data1.Width) {
                    Stl = 0;
                    Str++;
                }
                *(Data1.pMat + Stl + (Data1.Width * Str)) = *(Data.pMat + j + (Data.Width * i));
                Stl++;
            }
        }
    }
}

void PrintMatrix (Matrix Data) {
    for(int i = 0; i < Data.Height; i++) {
        for(int j = 0; j < Data.Width; j++) {
            printf("%f\t", *(Data.pMat + j + (Data.Width * i)));
        }
        printf("\n");
    }
}

float DetMatrix (Matrix Data) {
    float Det;
    if (Data.Height != Data.Width) {
        printf("Determinant does not exist\n");
        return 0;
    }
    if ((Data.Height == 1) && (Data.Width == 1)) {
        Det = *(Data.pMat);
    }
    else {
        Det = 0;
        for(int i = 0; i < Data.Width; i++) {
            Matrix Data1;
            Data1.Height = Data1.Width = (Data.Width - 1);
            Data1.pMat = malloc(sizeof(float) * Data1.Height * Data1.Width);
            Minor(Data, Data1, 0, i);
            Det = Det + (pow(-1,((i+1)+1)) * *(Data.pMat + i) * DetMatrix(Data1));
            free(Data1.pMat);
        }
    }
    return Det;
}

void InverseMatrix (Matrix Data, float Det) {
    if (Det == 0) {
        printf("Inverse matrix does not exist\n");
        return;
    }
    Matrix InvData;
    InvData.Height = InvData.Width = Data.Width;
    InvData.pMat = malloc(sizeof(float) * InvData.Height * InvData.Width);
    for(int i = 0; i < InvData.Width; i++) {
        for(int j = 0; j < InvData.Height; j++) {
            Matrix Data1;
            Data1.Height = Data1.Width = (Data.Width - 1);
            Data1.pMat = malloc(sizeof(float) * Data1.Height * Data1.Width);
            Minor(Data, Data1, j, i);
            float MinorDet = DetMatrix(Data1);
            *(InvData.pMat + j + (i * InvData.Width)) = ((powf(Det, -1) * (int)pow(-1,(i+1)+(j+1)) * MinorDet));
            free(Data1.pMat);
        }
    }
    printf("Inverse Matrix:\n");
    PrintMatrix(InvData);
    free(InvData.pMat);
}

void MatrixSum(Matrix Data) {
    Matrix Data1;
    Data1.pMat = malloc(sizeof(float) * Data.Height * Data.Width);
    Data1.Height = Data.Height;
    Data1.Width = Data.Width;
    GeneratingMatrix(Data1);
    printf("Matrix 2:\n");
    PrintMatrix(Data1);
    for(int i = 0; i < Data1.Height; i++) {
        for(int j = 0; j < Data1.Width; j++) {
            *(Data1.pMat + j + (i * Data1.Width)) = *(Data1.pMat + j + (i * Data1.Width)) + *(Data.pMat + j + (i * Data.Width));
        }
    }
    printf("Sum Result:\n");
    PrintMatrix(Data1);
    free(Data1.pMat);
}

void MatrixMultiplication(Matrix Data) {
    Matrix Data1;
    Data1.pMat = malloc(sizeof(float) * Data.Height * Data.Width);
    Data1.Height = Data.Height;
    Data1.Width = Data.Width;
    GeneratingMatrix(Data1);
    printf("Matrix 2:\n");
    PrintMatrix(Data1);
    Matrix ResData;
    ResData.pMat = malloc(sizeof(float) * ResData.Height * ResData.Width);
    ResData.Height = Data.Height;
    ResData.Width = Data.Width;
    float Sum = 0;
    for(int i = 0; i < ResData.Height; i++) {
        for(int j = 0; j < ResData.Width; j++) {
            for(int k = 0; k < ResData.Height; k++) {
                Sum = Sum + *(Data.pMat + k + (i * Data.Width)) * *(Data1.pMat + j + (k * Data.Width));
            }
            *(ResData.pMat + j + (i * ResData.Width)) = Sum;
            Sum = 0;
        }
    }
    printf("Multiplication Result:\n");
    PrintMatrix(ResData);
    free(ResData.pMat);
}

int main() {
    Matrix Data;
    printf("Matrix Height:\n");
    scanf("%d", &Data.Height);
    printf("Matrix Width:\n");
    scanf("%d", &Data.Width);
    Data.pMat = malloc(sizeof(float) * Data.Height * Data.Width);
    GeneratingMatrix(Data);
    printf("Source Matrix:\n");
    PrintMatrix(Data);
    printf("Determinant = %f\n", DetMatrix(Data));
    float Det = DetMatrix(Data);
    InverseMatrix(Data, Det);
    MatrixSum(Data);
    MatrixMultiplication(Data);
    free(Data.pMat);
    return 0;
}