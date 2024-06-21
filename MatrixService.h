#pragma once

#include <stdio.h>
#include "VectorService.h"

typedef struct Matrix {
    size_t countOfRows;
    size_t countOfColumns;
    Vector **content;
} Matrix;

Matrix *allocateMatrix(size_t rowsCount, size_t columnsCount, FieldInfo *FieldInfo);
void initMatrixRows(Matrix *matrix, void *dataset[]);
void printMatrix(Matrix *matrix);
void freeMatrixMemory(Matrix *matrix);
void getValueFromMatrix(Matrix *matrix, size_t rowNum, size_t columnNum, void *result);
int isMatrixTypesEqual(Matrix *matrix1, Matrix *matrix2);
int isMatrixSizesEqual(Matrix *matrix1, Matrix *matrix2);
int isMatrixSizesCorrected(Matrix *matrix1, Matrix  *matrix2);
int compareMatrix(Matrix *matrix1, Matrix *matrix2);