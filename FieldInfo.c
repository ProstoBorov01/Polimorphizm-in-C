#include <stdlib.h>
#include "FieldInfo.h"
#include "FieldInfoFuncs.h"

FieldInfo *INT_INFO() {
    FieldInfo *INTEGER_DATA = (FieldInfo *)malloc(sizeof(FieldInfo));
    INTEGER_DATA -> elementSize = sizeof(int);
    INTEGER_DATA -> plus = &plusInt;
    INTEGER_DATA -> multiply = &multiplyInt;
    INTEGER_DATA -> print = &printInt;
    INTEGER_DATA -> zeroValue = &zeroIntValue;
    INTEGER_DATA -> compareValue = &compareIntValue;
    return INTEGER_DATA;
}

FieldInfo *FLOAT_INFO() {
    FieldInfo *FLOAT_DATA = (FieldInfo *)malloc(sizeof(FieldInfo));
    FLOAT_DATA -> elementSize = sizeof(int);
    FLOAT_DATA -> plus = &plusFloat;
    FLOAT_DATA -> multiply = &multiplyFloat;
    FLOAT_DATA -> print = &printFloat;
    FLOAT_DATA -> zeroValue = &zeroFloatValue;
    FLOAT_DATA -> compareValue = &compareFloatValue;
    return FLOAT_DATA;
}