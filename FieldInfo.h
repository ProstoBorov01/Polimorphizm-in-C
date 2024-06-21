#pragma once

#include <stdio.h>

typedef struct FieldInfo {
    size_t elementSize;
    void (*plus)(void* operandA, void* operandB,void* result);
    void (*multiply)(void* operandA, void* operandB,void* result); 
    void (*print)(void* operand);
    void (*zeroValue)(void *object);
    int (*compareValue)(void *operandA, void *operandB);
} FieldInfo;

FieldInfo *INT_INFO();
FieldInfo *FLOAT_IN3FO();