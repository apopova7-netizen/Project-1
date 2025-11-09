#ifndef TESTSTUDENT2_H
#define TESTSTUDENT2_H
#include "functionsStudent2.h"

void Test2(void);

#endif

void Test2()
{
    int countNumbers1 = 4;
    char *arrayNumbers1[] = {"15.7", "D.A", "1101.101", "25.75", "\0"}; 
    int arrayBaseSystem1[] = {8, 16, 2, 10};

    Analyze((const char**)arrayNumbers1, arrayBaseSystem1, countNumbers1);

    printf("Expected output:\n");
    printf("Sorted: 13.625, 13.625, 13.875, 25.75\n");
    printf("Min: 13.625, Max: 25.75, Mean: 16.71875, Median: 13.75\n");
    printf("\n");

    int countNumbers2 = 4;
    char *arrayNumbers2[] = {"A", "1001.1", "12.3", "20"}; 
    int arrayBaseSystem2[] = {16, 2, 8, 10};

    Analyze((const char**)arrayNumbers2, arrayBaseSystem2, countNumbers2);

    printf("Expected output:\n");
    printf("Sorted: 9.5, 10, 10.375, 20\n");
    printf("Min: 9.5, Max: 20, Mean: 12.46875, Median: 10.1875\n");
    printf("\n");

    int countNumbers3 = 3;
    char *arrayNumbers3[] = {"a.f", "1C", "101.01"}; 
    int arrayBaseSystem3[] = {16, 16, 2};

    Analyze((const char**)arrayNumbers3, arrayBaseSystem3, countNumbers3);
    printf("Expected output:\n");
    printf("Sorted: 5.25, 10.9375, 28\n");
    printf("Min: 5.25, Max: 28, Mean: 14.72916666666667, Median: 10.9375\n");
    printf("\n");

    int countNumbers4 = 1;
    char *arrayNumbers4[] = {"101"}; 
    int arrayBaseSystem4[] = {20};

    Analyze((const char**)arrayNumbers4, arrayBaseSystem4, countNumbers4);

    printf("Expected output:\n");
    printf("Invalid base input.\n");
    printf("Error: couldn't convert a number\n");
    printf("No valid numbers to analyze.\n");
    printf("\n");

    int countNumbers5 = 1;
    char *arrayNumbers5[] = {"19"}; 
    int arrayBaseSystem5[] = {8};

    Analyze((const char**)arrayNumbers5, arrayBaseSystem5, countNumbers5);

    printf("Expected output:\n");
    printf("Error: couldn't convert a number\n");
    printf("No valid numbers to analyze.\n");
    printf("\n");

    int countNumbers6 = 3;
    char *arrayNumbers6[] = {"5", "10", "15"}; 
    int arrayBaseSystem6[] = {10, 10, 10};

    Analyze((const char**)arrayNumbers6, arrayBaseSystem6, countNumbers6);

    printf("Expected output:\n");
    printf("Sorted: 5, 10, 15\n");
    printf("Min: 5, Max: 15, Mean: 10, Median: 10\n");
    printf("\n");

    int countNumbers7 = 5;
    char *arrayNumbers7[] = {"1", "2", "3", "4", "5"}; 
    int arrayBaseSystem7[] = {10, 10, 10, 10, 10};

    Analyze((const char**)arrayNumbers7, arrayBaseSystem7, countNumbers7);

    printf("Expected output:\n");
    printf("Sorted: 1, 2, 3, 4, 5\n");
    printf("Min: 1, Max: 5, Mean: 3, Median: 3\n");
    printf("\n");

    int countNumbers8 = 3;
    char *arrayNumbers8[] = {"1.1", "10.01", "0.111"}; 
    int arrayBaseSystem8[] = {2, 2, 2};

    Analyze((const char**)arrayNumbers8, arrayBaseSystem8, countNumbers8);

    printf("Expected output:\n");
    printf("Sorted: 0.875, 1.5, 2.25\n");
    printf("Min: 0.875, Max: 2.25, Mean: 1.541666666666667, Median: 1.5\n");
    printf("\n");

    int countNumbers9 = 0;
    char *arrayNumbers9[0]; 
    int arrayBaseSystem9[0];

    Analyze((const char**)arrayNumbers9, arrayBaseSystem9, countNumbers9);

    printf("Expected output:\n");
    printf("No valid numbers to analyze.\n");
    printf("\n");

    int countNumbers10 = 3;
    char *arrayNumbers10[] = {"1A", "9Z", "111"}; 
    int arrayBaseSystem10[] = {16, 16, 2};

    Analyze((const char**)arrayNumbers10, arrayBaseSystem10, countNumbers10);

    printf("Expected output:\n");
    printf("Error: couldn't convert a number\n");
    printf("Sorted: 7, 26\n");
    printf("Min: 7, Max: 26, Mean: 16.5, Median: 16.5\n");
    printf("\n");
}
