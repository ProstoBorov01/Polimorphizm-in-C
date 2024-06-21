#include <stdio.h>

#include "Check.h"
#include "messages.h"

Matrix *allocateMatrix(size_t vectorsCount, size_t columnsCount, FieldInfo *fieldInfo) {
    Matrix *matrix = (Matrix *)malloc(sizeof(Matrix));
    safemallocCheck(matrix);
    matrix -> countOfRows = vectorsCount;
    matrix -> countOfColumns = columnsCount;
    matrix->content = (Vector **)malloc(vectorsCount * sizeof(Vector));
    safemallocCheck(matrix -> content);

    for (size_t i = 0; i < vectorsCount; i ++) {
        matrix -> content[i] = allocateVector(fieldInfo, columnsCount);
    }

    return matrix;
}

void initMatrixRows(Matrix *matrix, void *dataset[]) {
    emptyDatasetCheck(dataset);

    for (size_t i = 0; i < matrix -> countOfRows; i ++) {
        outOfBoundsCheck(matrix -> content[0] -> size, i);
        initVector(matrix -> content[i], dataset[i]);
    }

}

void printMatrix(Matrix *matrix) {
    size_t countOfVectors = matrix -> countOfRows;
    size_t countOfColumns = matrix -> countOfColumns;
    void *operand = malloc(matrix -> content[0] -> typeInfo -> elementSize);
    safemallocCheck(operand);

    for (size_t i = 0; i < countOfVectors; i ++) {

        for (size_t j = 0; j < countOfColumns; j ++) {
            getValueFromVector(matrix -> content[i], j, operand);
            matrix -> content[i] -> typeInfo -> print(operand);
        }

        printf("\n");
    }

    printf("\n");
    free(operand);
}

void freeMatrixMemory(Matrix *matrix) {
    nullCheck(matrix);
    size_t vectors = matrix -> countOfRows;

    for (size_t i = 0; i < vectors; i ++) {
        freeVectorMemory(matrix -> content[i]);
    }

    free(matrix -> content);
    free(matrix);
}

void getValueFromMatrix(Matrix *matrix, size_t vectorNum, size_t columnNum, void *result) {
    Vector *vector = matrix -> content[vectorNum];
    safemallocCheck(vector);
    getValueFromVector(vector, columnNum, result);
    nullCheck(result);
}

int isMatrixTypesEqual(Matrix *matrix1, Matrix *matrix2) {
    return getVectorType(matrix1 -> content[0]) == getVectorType(matrix2 -> content[0]);
}

int isMatrixSizesEqual(Matrix *matrix1, Matrix *matrix2) {
    return (matrix1->countOfRows == matrix2->countOfRows) && (matrix1->countOfColumns == matrix2->countOfColumns);
}
int isMatrixSizesCorrected(Matrix *matrix1, Matrix  *matrix2) {
    return (matrix1->countOfColumns == matrix2->countOfRows);
}

int compareMatrix(Matrix *matrix1, Matrix *matrix2) {
    matrixWithDifferentSizesAndTypeInfoCheck(matrix1, matrix2);
    matrixWithDifferentTypesCheck(matrix1, matrix2);
    matrixWithDifferentSizesCheck(matrix1, matrix2);
    void *value1 = malloc(matrix1 -> content[0] -> typeInfo -> elementSize);
    void *value2 = malloc(matrix1 -> content[0] -> typeInfo -> elementSize);
    safemallocCheck(value1);
    safemallocCheck(value2);

    for (size_t i = 0; i < matrix1 -> countOfRows; ++i) {

        for (size_t j = 0; j < matrix1 -> countOfColumns; ++j) {
            getValueFromMatrix(matrix1, i, j, value1);
            getValueFromMatrix(matrix2, i, j, value2);

            if (matrix1 -> content[0] -> typeInfo -> compareValue(value1, value2) == 0) {
                matrixAreDifferentMessage();
                return 0;
            }

        }

    }

    nullCheck(value1);
    nullCheck(value2);
    free(value1);
    free(value2);
    return 1;
}