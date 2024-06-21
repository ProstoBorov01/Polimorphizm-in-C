cmake_minimum_required(VERSION 3.27)
project(lab_01 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab_01 main.c
        Check.c
        Check.h
        FieldInfo.c
        FieldInfo.h
        FieldInfoFuncs.c
        FieldInfoFuncs.h
        MatrixOperations.c
        MatrixOperations.h
        MatrixService.c
        MatrixService.h
        messages.c
        messages.h
        TestCore.c
        TestCore.h
        VectorService.c
        VectorService.h)