#include <stdlib.h>

#include "Check.h"


void multiplyMatrix(Matrix* matrix1, Matrix *matrix2, Matrix *resultMatrix) {
    matrixWithUncorrectSizesAndTypeInfoCheck(matrix1, matrix2);
    matrixWithDifferentTypesCheck(matrix1, matrix2);
    matrixWithUncorrectSizesCheck(matrix1, matrix2);
    void *value = malloc(matrix1 -> content[0] -> typeInfo-> elementSize);
    void *elem1 = malloc(matrix1 -> content[0] -> typeInfo -> elementSize);
    void *elem2 = malloc(matrix1 -> content[0] -> typeInfo -> elementSize);
    void *product = malloc(matrix1 -> content[0] -> typeInfo -> elementSize);
    safemallocCheck(value);
    safemallocCheck(elem1);
    safemallocCheck(elem2);
    safemallocCheck(product);
    matrix1 -> content[0] -> typeInfo -> zeroValue(value);
    matrix1 -> content[0] -> typeInfo -> zeroValue(elem1);
    matrix1 -> content[0] -> typeInfo -> zeroValue(elem2);
    matrix1 -> content[0] -> typeInfo -> zeroValue(product);

    for (size_t i = 0; i < matrix1 -> countOfRows; i ++) {

        for (size_t j = 0; j < matrix2 -> countOfColumns; j ++) {

    
            for (size_t k = 0; k < matrix1 -> countOfColumns; k ++) { 
                getValueFromMatrix(matrix1, i, k, elem1);
                getValueFromMatrix(matrix2, k, j, elem2);
                matrix1 -> content[0] -> typeInfo -> multiply(elem1, elem2, product);
                matrix1 -> content[0] -> typeInfo -> plus(value, product, value); 
            }

            setValueToVector(resultMatrix -> content[i], j, value);
            matrix1 -> content[0] -> typeInfo -> zeroValue(value);
        }

    }

    nullCheck(elem1);
    nullCheck(elem2);
    nullCheck(product);
    nullCheck(value);
    free(elem1);
    free(elem2);
    free(product);
    free(value);
}

void plusMatrix(Matrix *matrix1, Matrix *matrix2, Matrix *resultMatrix) {
    matrixWithDifferentSizesAndTypeInfoCheck(matrix1, matrix2);
    matrixWithDifferentTypesCheck(matrix1, matrix2);
    matrixWithDifferentSizesCheck(matrix1, matrix2);
    size_t countOfRows = matrix1 -> countOfRows;
    size_t countOfColumns = matrix1 -> countOfColumns;
    void *value = malloc(matrix1 -> content[0] -> typeInfo-> elementSize);
    void *elem1 = malloc(matrix1 -> content[0] -> typeInfo -> elementSize);
    void *elem2 = malloc(matrix1 -> content[0] -> typeInfo -> elementSize);
    void *sum = malloc(matrix1 -> content[0] -> typeInfo -> elementSize);
    safemallocCheck(value);
    safemallocCheck(elem1);
    safemallocCheck(elem2);
    safemallocCheck(sum);
    matrix1 -> content[0] -> typeInfo -> zeroValue(value);
    matrix1 -> content[0] -> typeInfo -> zeroValue(elem1);
    matrix1 -> content[0] -> typeInfo -> zeroValue(elem2);
    matrix1 -> content[0] -> typeInfo -> zeroValue(sum);

    for (size_t i = 0; i < countOfRows; i ++) {

        for (size_t j = 0; j < countOfColumns; j ++) {
            getValueFromMatrix(matrix1, i, j, elem1);
            getValueFromMatrix(matrix2, i, j, elem2);
            matrix1 -> content[0] -> typeInfo -> plus(elem1, elem2, value);
            matrix1 -> content[0] -> typeInfo -> plus(value, sum, value); 
            setValueToVector(resultMatrix -> content[i], j, value);
        }

    }

    nullCheck(elem1);
    nullCheck(elem2);
    nullCheck(sum);
    nullCheck(value);
    free(elem1);
    free(elem2);
    free(sum);
    free(value);
}

void transpositionMatrix(Matrix *matrix, Matrix *resultMatrix) {
    size_t countOfVectors = matrix -> countOfRows;
    size_t countOfColumns = matrix -> countOfColumns;
    void *value = malloc(matrix -> content[0] -> typeInfo-> elementSize);
    safemallocCheck(value);
    matrix -> content[0] -> typeInfo -> zeroValue(value);
    
    for(size_t i = 0; i < countOfVectors; i ++) {
        
        for (size_t j = 0; j < countOfColumns; j ++) {
            getValueFromMatrix(matrix, i, j, value);
            setValueToVector(resultMatrix -> content[j], i, value);
        }

    }

    nullCheck(value);
    free(value);
}
