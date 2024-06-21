#include <stdio.h>
#include <assert.h>

#include "Check.h"
#include "messages.h"

#define OUT_OF_BOUNDS_ERROR 11
#define EMPTY_DATASET 100
#define UNCORRECTED_OBJECTS 101

void outOfBoundsCheck(size_t vectorSize, size_t index) {
    if (vectorSize < index) {
        outOfBoundsMessage();
        exit(OUT_OF_BOUNDS_ERROR);
    }
}

void emptyDatasetCheck(void *dataset[]) {
    if (dataset == NULL) {
        emptyDatasetMessage();
        exit(EMPTY_DATASET);
    }
}

void safemallocCheck(void *object) {
    assert(object != NULL && "Memory allocation error \n");
}

void nullCheck(void *value) {
    assert(value != NULL && "Value == NULL \n");
}

void matrixWithDifferentTypesCheck(Matrix *object1, Matrix *object2) {
    if (isMatrixSizesEqual(object1, object2) && !isMatrixTypesEqual(object1, object2)) {
        differentTypesMessages();
        exit(UNCORRECTED_OBJECTS);
    }
}

void matrixWithUncorrectSizesCheck(Matrix *object1, Matrix *object2) {
    if (!isMatrixSizesCorrected(object1, object2) && isMatrixTypesEqual(object1, object2)) {
        uncorrectSizesMessage();
        exit(UNCORRECTED_OBJECTS);
    }
}

void matrixWithUncorrectSizesAndTypeInfoCheck(Matrix *object1, Matrix *object2) {
    if (!isMatrixTypesEqual(object1, object2) && !isMatrixSizesCorrected(object1, object2)) {
        differentTypesAndUncorrectSizesMessage();
        exit(UNCORRECTED_OBJECTS);
    }
}

void matrixWithDifferentSizesCheck(Matrix *object1, Matrix *object2) {
    if (!isMatrixSizesEqual(object1, object2)) {
        differentSizesMessage();

        exit(UNCORRECTED_OBJECTS);
    }
}
void objectIsAlreadyEmptyCheck(void *object) {
    if (object == NULL) {
        objectIsAlreadyEmptyMessage();
        exit(UNCORRECTED_OBJECTS);
    }
}

void matrixWithDifferentSizesAndTypeInfoCheck(Matrix *object1, Matrix *object2) {
    if (!isMatrixTypesEqual(object1, object2) && !isMatrixSizesEqual(object1, object2)) {
        differentTypesAndSizesMessage();
        exit(UNCORRECTED_OBJECTS);
    }
}
