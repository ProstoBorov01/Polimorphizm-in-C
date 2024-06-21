#pragma once

#include <stdio.h>
#include "VectorService.h"
#include "MatrixService.h"

void outOfBoundsCheck(size_t vector, size_t index);
void emptyDatasetCheck(void *dataset[]);
void safemallocCheck(void *object);
void nullCheck(void *value);
void objectIsAlreadyEmptyCheck(void *object);
void matrixWithUncorrectSizesCheck(Matrix *object1, Matrix *object2);
void matrixWithDifferentTypesCheck(Matrix *object1, Matrix *object2);
void matrixWithDifferentSizesCheck(Matrix *object1, Matrix *object2);
void matrixWithDifferentSizesAndTypeInfoCheck(Matrix *object1, Matrix *object2);
void matrixWithUncorrectSizesAndTypeInfoCheck(Matrix *object1, Matrix *object2);