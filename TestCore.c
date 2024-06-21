#include <assert.h>

#include "messages.h"
#include "FieldInfo.h"
#include "MatrixOperations.h"

void testIntSum() {
    int operandA = -123;
    int operandB = 4543;
    int handmadeResult = operandA + operandB;
    int functionResult;
    INT_INFO() -> plus((void *)&operandA, (void *)&operandB, (void *)&functionResult);
    assert(handmadeResult == functionResult && "handmadeResult != functionResult ERROR in testIntSum function \n");
    testIntSumPassedMessage();
}

void testIntMultiply() {
    int operandA = -123;
    int operandB = 4543;
    int handmadeResult = operandA * operandB;
    int functionResult;
    INT_INFO() -> multiply((void *)&operandA, (void *)&operandB, (void *)&functionResult);
    assert(handmadeResult == functionResult && "handmadeResult != functionResult ERROR in testIntMultiply function \n");
    testIntMultiplyPassedMessage();
}

void testIntZeroValue() {
    int handmadeResult = 0;
    int functionResult;
    INT_INFO() -> zeroValue((void *)&functionResult);
    assert(handmadeResult == functionResult && "handmadeResult != functionResult ERROR in testIntZeroValue function \n");
    testIntZeroValuePassedMessage();
}

void testFloatSum() {
    float operandA = -123.442f;
    float operandB = 4543.983f;
    float handmadeResult = operandA + operandB;
    float functionResult;
    FLOAT_INFO() -> plus((void *)&operandA, (void *)&operandB, (void *)&functionResult);
    assert(handmadeResult == functionResult && "handmadeResult != functionResult ERROR in testFloatSum function \n");
    testFloatSumPassedMessage();
}

void testFloatMultiply() {
    float operandA = -123.442f;
    float operandB = 4543.983f;
    float handmadeResult = operandA * operandB;
    float functionResult;
    FLOAT_INFO() -> multiply((void *)&operandA, (void *)&operandB, (void *)&functionResult);
    assert(handmadeResult == functionResult && "handmadeResult != functionResult ERROR in testFloatMultiply function \n");
    testFloatMultiplyPassedMessage();
}

void testFloatZeroValue() {
    float handmadeResult = 0.0f;
    float functionResult;
    FLOAT_INFO() -> zeroValue((void *)&functionResult);
    assert(handmadeResult == functionResult && "handmadeResult != functionResult ERROR in testFloatZeroValue function \n");
    testFloatZeroValuePassedMessage();
}

void testMatrixIntSum() {
    printf("########################### testMatrixIntSum ###########################\n");
    printf("\n");
    Matrix *matrix1 = allocateMatrix(2, 3, INT_INFO());
    Matrix *matrix2 = allocateMatrix(2, 3, INT_INFO());
    Matrix *excpectedResult = allocateMatrix(2, 3, INT_INFO());
    Matrix *funcResult = allocateMatrix(2, 3, INT_INFO());
    int row1[] = {1, 2, 3};
    int row2[] = {4, 5, 6};
    int excpectedRow1[] = {5, 7 ,9};
    int excpectedRow2[] = {5, 7, 9};
    void *dataset1[] = {row1, row2};
    void *dataset2[] = {row2, row1};
    void *excpectedDataset[] = {excpectedRow1, excpectedRow2};
    initMatrixRows(matrix1, dataset1);
    printf("Matrix1:\n");
    printMatrix(matrix1);
    initMatrixRows(matrix2, dataset2);
    printf("Matrix2:\n");
    printMatrix(matrix2);
    initMatrixRows(excpectedResult, excpectedDataset);
    plusMatrix(matrix1, matrix2, funcResult);
    printf("Result Matrix:\n");
    printMatrix(funcResult);

    if (compareMatrix(funcResult, excpectedResult)) {
        testMatrixIntSumPassedMessage();
    }
    else {
        testMatrixIntSumNotPassedMessage();
    }

    freeMatrixMemory(matrix1);
    freeMatrixMemory(matrix2);
    freeMatrixMemory(excpectedResult);
    freeMatrixMemory(funcResult);
    printf("\n");
}

void testMatrixFloatSum() {
    printf("########################### testMatrixFloatSum ###########################\n");
    printf("\n");
    Matrix *matrix1 = allocateMatrix(2, 3, FLOAT_INFO());
    Matrix *matrix2 = allocateMatrix(2, 3, FLOAT_INFO());
    Matrix *excpectedResult = allocateMatrix(2, 3, FLOAT_INFO());
    Matrix *funcResult = allocateMatrix(2, 3, FLOAT_INFO());
    float row1[] = {1.0f, 2.0f, 3.0f};
    float row2[] = {4.0f, 5.0f, 6.0f};
    float excpectedRow1[] = {5, 7 ,9};
    float excpectedRow2[] = {5, 7, 9};
    void *dataset1[] = {row1, row2};
    void *dataset2[] = {row2, row1};
    void *excpectedDataset[] = {excpectedRow1, excpectedRow2};
    initMatrixRows(matrix1, dataset1);
    printf("Matrix1:\n");
    printMatrix(matrix1);
    initMatrixRows(matrix2, dataset2);
    printf("Matrix2:\n");
    printMatrix(matrix2);
    initMatrixRows(excpectedResult, excpectedDataset);
    plusMatrix(matrix1, matrix2, funcResult);
    printf("Result Matrix:\n");
    printMatrix(funcResult);

    if (compareMatrix(funcResult, excpectedResult)) {
        testMatrixFloatSumPassedMessage();
    }
    else {
        testMatrixFloatSumNotPassedMessage();
    }

    freeMatrixMemory(matrix1);
    freeMatrixMemory(matrix2);
    freeMatrixMemory(excpectedResult);
    freeMatrixMemory(funcResult);
    printf("\n");
}

void testMatrixIntMultiply() {
    printf("########################### testMatrixIntMultiply ###########################\n");
    printf("\n");
    Matrix *matrix1 = allocateMatrix(2, 3, INT_INFO());
    Matrix *matrix2 = allocateMatrix(3, 2, INT_INFO());
    Matrix *expectedResult = allocateMatrix(2, 2, INT_INFO());
    Matrix *funcResult = allocateMatrix(2, 2, INT_INFO());
    int row1[] = {1, 2, 3};
    int row2[] = {4, 5, 6};
    int row3[] = {7, 8};
    int row4[] = {4, 3};
    int row5[] = {4, 2};
    int expectedRow1[] = {27, 20};
    int expectedRow2[] = {72, 59};
    void *dataset1[] = {row1, row2};
    void *dataset2[] = {row3, row4, row5};
    void *expectedDataset[] = {expectedRow1, expectedRow2};
    initMatrixRows(matrix1, dataset1);
    printf("Matrix1:\n");
    printMatrix(matrix1);
    initMatrixRows(matrix2, dataset2);
    printf("Matrix2:\n");
    printMatrix(matrix2);
    initMatrixRows(expectedResult, expectedDataset);
    multiplyMatrix(matrix1, matrix2, funcResult);
    printf("Result Matrix:\n");
    printMatrix(funcResult);

    if (compareMatrix(funcResult, expectedResult)) {
        testMatrixIntMultiplyPassedMessage();
    } else {
        testMatrixIntMultiplyNotPassedMessage();
    }

    freeMatrixMemory(matrix1);
    freeMatrixMemory(matrix2);
    freeMatrixMemory(expectedResult);
    freeMatrixMemory(funcResult);
    printf("\n");
}


void testMatrixFloatMultiply() {
    printf("########################### testMatrixFloatMultiply ###########################\n");
    printf("\n");
    Matrix *matrix1 = allocateMatrix(2, 3, FLOAT_INFO());
    Matrix *matrix2 = allocateMatrix(3, 2, FLOAT_INFO());
    Matrix *expectedResult = allocateMatrix(2, 2, INT_INFO());
    Matrix *funcResult = allocateMatrix(2, 2, FLOAT_INFO());
    float row1[] = {1.0f, 2.0f, 3.0f};
    float row2[] = {4.0f, 5.0f, 6.0f};
    float row3[] = {7.0f, 8.0f};
    float row4[] = {4.0f, 3.0f};
    float row5[] = {4.0f, 2.0f};
    float expectedRow1[] = {27.0f, 20.0f};
    float expectedRow2[] = {72.0f, 59.0f};
    void *dataset1[] = {row1, row2};
    void *dataset2[] = {row3, row4, row5};
    void *expectedDataset[] = {expectedRow1, expectedRow2};
    initMatrixRows(matrix1, dataset1);
    printf("Matrix1:\n");
    printMatrix(matrix1);
    initMatrixRows(matrix2, dataset2);
    printf("Matrix2:\n");
    printMatrix(matrix2);
    initMatrixRows(expectedResult, expectedDataset);
    multiplyMatrix(matrix1, matrix2, funcResult);
    printf("Result Matrix:\n");
    printMatrix(funcResult);

    if (compareMatrix(funcResult, expectedResult)) {
        testMatrixFloatMultiplyPassedMessage();
    } else {
        testMatrixFloatMultiplyNotPassedMessage();
    }

    freeMatrixMemory(matrix1);
    freeMatrixMemory(matrix2);
    freeMatrixMemory(expectedResult);
    freeMatrixMemory(funcResult);
    printf("\n");
}

void testMatrixIntTransposition() {
    printf("########################### testMatrixIntTransposition ###########################\n");
    printf("\n");
    Matrix *matrix = allocateMatrix(2, 3, INT_INFO());
    Matrix *expectedResult = allocateMatrix(3, 2, INT_INFO());
    Matrix *funcResult = allocateMatrix(3, 2, INT_INFO());
    int row1[] = {1, 2, 3};
    int row2[] = {4, 5, 6};
    void *dataset[] = {row1, row2};
    int expectedRow1[] = {1, 4};
    int expectedRow2[] = {2, 5};
    int expectedRow3[] = {3, 6};
    void *expectedDataset[] = {expectedRow1, expectedRow2, expectedRow3};
    initMatrixRows(matrix, dataset);
    printf("Matrix1: \n");
    printMatrix(matrix);
    initMatrixRows(expectedResult, expectedDataset);
    transpositionMatrix(matrix, funcResult);
    printf("Result Matrix: \n");
    printMatrix(funcResult);
    if (compareMatrix(funcResult, expectedResult)) {
        testMatrixFloatTranspositionPassedMessage();
    } else {
        testMatrixFloatTranspositionNotPassedMessage();
    }

    freeMatrixMemory(matrix);
    freeMatrixMemory(expectedResult);
    freeMatrixMemory(funcResult);
    printf("\n");
}

void testMatrixFloatTransposition() {
    printf("########################### testMatrixFloatTransposition ###########################\n");
    printf("\n");
    Matrix *matrix = allocateMatrix(2, 3, FLOAT_INFO());
    Matrix *expectedResult = allocateMatrix(3, 2, FLOAT_INFO());
    Matrix *funcResult = allocateMatrix(3, 2, FLOAT_INFO());
    float row1[] = {1.0f, 2.0f, 3.0f};
    float row2[] = {4.0f, 5.0f, 6.0f};
    void *dataset[] = {row1, row2};
    float expectedRow1[] = {1.0f, 4.0f};
    float expectedRow2[] = {2.0f, 5.0f};
    float expectedRow3[] = {3.0f, 6.0f};
    void *expectedDataset[] = {expectedRow1, expectedRow2, expectedRow3};
    initMatrixRows(matrix, dataset);
    printf("Matrix1: \n");
    printMatrix(matrix);
    initMatrixRows(expectedResult, expectedDataset);
    transpositionMatrix(matrix, funcResult);
    printf("Result Matrix: \n");
    printMatrix(funcResult);

    if (compareMatrix(funcResult, expectedResult)) {
        testMatrixIntTranspositionPassedMessage();
    } else {
        testMatrixIntTranspositionNotPassedMessage();
    }

    freeMatrixMemory(matrix);
    freeMatrixMemory(expectedResult);
    freeMatrixMemory(funcResult);
    printf("\n");
}

void testInt() {
    printf("########################### testTypeInfoFuncs ###########################\n");
    printf("\n");
    testIntSum();
    testIntMultiply();
    testIntZeroValue();
}

void testFloat() {
    testFloatSum();
    testFloatMultiply();
    testFloatZeroValue();
    printf("\n");
}


void testIntMatrix() {
    testMatrixIntSum();
    testMatrixIntMultiply();
    testMatrixIntTransposition();
}

void testFloatMatrix() {
    testMatrixFloatSum();
    testMatrixFloatMultiply();
    testMatrixFloatTransposition();
}   
