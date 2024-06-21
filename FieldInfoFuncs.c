#include "stdio.h"
#include <assert.h>

void plusInt(void *operandA, void *operandB, void *result) {
    assert(operandA && operandB && result);
    *(int *)result = *(int *)operandA + *(int *)operandB;
}

void multiplyInt(void *operandA, void *operandB, void *result) {
    assert(operandA && operandB && result);
    *(int *)result = (*(int *)operandA) * (*(int *)operandB);
}

void printInt(void *operand) {
    assert(operand);
    printf("%3d", *(int *)operand);
}

void plusFloat(void *operandA, void *operandB, void *result) {
    assert(operandA && operandB && result);
    *(float *)result = *(float *)operandA + *(float *)operandB;
}

void multiplyFloat(void *operandA, void *operandB, void *result) {
    assert(operandA && operandB && result);
    *(float *)result = (*(float *)operandA) * (*(float *)operandB);
}

void printFloat(void *operand) {
    assert(operand);
    printf(" %.1f ", *(float *)operand);
}

void zeroIntValue(void *operand) {
    assert(operand);
    *(int *)operand = 0;
}

void zeroFloatValue(void *operand) {
    assert(operand);
    *(float *)operand = 0.0f;
}

int compareIntValue(void *operandA, void *operandB) {
    if (*(int *)operandA == *(int *)operandB) {
        return 1;
    }
    else {
        return 0;
    }
}

int compareFloatValue(void *operandA, void *operandB) {
    if (*(float *)operandA == *(float *)operandB) {
        return 1;
    }
    else {
        return 0;
    }
}
