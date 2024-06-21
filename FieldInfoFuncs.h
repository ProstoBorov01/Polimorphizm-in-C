#pragma once

void plusInt(void *operandA, void *operandB, void *result);
void multiplyInt(void *operandA, void *operandB, void *result);
void printInt(void *operand);

void plusFloat(void *operandA, void *operandB, void *result);
void multiplyFloat(void *operandA, void *operandB, void *result);
void printFloat(void *operand);

void zeroIntValue(void *operand);
void zeroFloatValue(void *operand);

int compareIntValue(void *operandA, void *operandB);
int compareFloatValue(void *operandA, void *operandB);