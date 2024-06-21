#include <stdlib.h>
#include <string.h>

#include "VectorService.h"
#include "Check.h"

Vector *allocateVector(FieldInfo *typeInfo, size_t size) {
    Vector *vector = (Vector *)malloc(sizeof(Vector));
    safemallocCheck(vector);
    void *arr = malloc(size * typeInfo -> elementSize);
    safemallocCheck(arr);
    vector -> typeInfo = typeInfo;
    vector -> size = size;
    vector -> array = arr;

    return vector;
}

void initVector(Vector *vector, void *source) {
    nullCheck(source);
    memcpy(vector->array, source, vector->size * vector->typeInfo->elementSize);
}

void freeVectorMemory(Vector *vector) {
    objectIsAlreadyEmptyCheck(vector);

    free(vector -> array);
    free(vector);
}

void setValueToVector(Vector *vector, size_t index, void *value) {
    nullCheck(value);
    memcpy(vector -> array + index * vector -> typeInfo -> elementSize, value, vector->typeInfo->elementSize);
}

void getValueFromVector(Vector *vector, size_t index, void *result) {
    outOfBoundsCheck(vector->size, index);
    memcpy(result, vector -> array + index * vector -> typeInfo -> elementSize, vector -> typeInfo -> elementSize);
}

size_t getVectorType(Vector *vector) {
    safemallocCheck(vector);

    return vector -> typeInfo -> elementSize;
}