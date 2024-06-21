#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "FieldInfo.h"

typedef struct Vector {
    FieldInfo *typeInfo;
    size_t size; 
    void *array; 
} Vector;

Vector *allocateVector(FieldInfo *typeInfo, size_t size);
void freeVectorMemory(Vector *vector);
void initVector(Vector *vector, void *source);
void setValueToVector(Vector *vector, size_t index, void *value);
void getValueFromVector(Vector *vector, size_t vectorNum, void *result);
size_t getVectorType(Vector *vector);


