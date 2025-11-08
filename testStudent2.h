#ifndef TESTSTUDENT2_H
#define TESTSTUDENT2_H
#include "functionsStudent2.h"

void Test1(void);
void Test2(void);
void Test3(void);
void Test4(void);
void Test5(void);
void Test6(void);
void Test7(void);
void Test8(void);
void Test9(void);
void Test10(void);

#endif

void Test1()
{
    int countNumbers = 4;
    char *arrayNumbers[] = {"15.7", "D.A", "1101.101", "25.75", "\0"}; 
    int arrayBaseSystem[] = {8, 16, 2, 10};

    Analyze((const char**)arrayNumbers, arrayBaseSystem, countNumbers);

    printf("Expected output:\n");
    printf("Sorted: 13.625, 13.625, 13.875, 25.75\n");
    printf("Min: 13.625, Max: 25.75, Mean: 16.71875, Median: 13.75\n");
    printf("\n");
}

void Test2()
{
    int countNumbers = 4;
    char *arrayNumbers[] = {"A", "1001.1", "12.3", "20"}; 
    int arrayBaseSystem[] = {16, 2, 8, 10};

    Analyze((const char**)arrayNumbers, arrayBaseSystem, countNumbers);

    printf("Expected output:\n");
    printf("Sorted: 9.5, 10, 10.375, 20\n");
    printf("Min: 9.5, Max: 20, Mean: 12.46875, Median: 10.1875\n");
    printf("\n");
}

void Test3()
{
    int countNumbers = 3;
    char *arrayNumbers[] = {"a.f", "1C", "101.01"}; 
    int arrayBaseSystem[] = {16, 16, 2};

    Analyze((const char**)arrayNumbers, arrayBaseSystem, countNumbers);
    printf("Expected output:\n");
    printf("Sorted: 5.25, 10.9375, 28\n");
    printf("Min: 5.25, Max: 28, Mean: 14.72916666666667, Median: 10.9375\n");
    printf("\n");
}

void Test4()
{
    int countNumbers = 1;
    char *arrayNumbers[] = {"101"}; 
    int arrayBaseSystem[] = {20};

    Analyze((const char**)arrayNumbers, arrayBaseSystem, countNumbers);

    printf("Expected output:\n");
    printf("Invalid base input.\n");
    printf("Error: couldn't convert a number\n");
    printf("No valid numbers to analyze.\n");
    printf("\n");
}

void Test5()
{
    int countNumbers = 1;
    char *arrayNumbers[] = {"19"}; 
    int arrayBaseSystem[] = {8};

    Analyze((const char**)arrayNumbers, arrayBaseSystem, countNumbers);

    printf("Expected output:\n");
    printf("Error: couldn't convert a number\n");
    printf("No valid numbers to analyze.\n");
    printf("\n");
}

void Test6()
{
    int countNumbers = 3;
    char *arrayNumbers[] = {"5", "10", "15"}; 
    int arrayBaseSystem[] = {10, 10, 10};

    Analyze((const char**)arrayNumbers, arrayBaseSystem, countNumbers);

    printf("Expected output:\n");
    printf("Sorted: 5, 10, 15\n");
    printf("Min: 5, Max: 15, Mean: 10, Median: 10\n");
    printf("\n");
}

void Test7()
{
    int countNumbers = 5;
    char *arrayNumbers[] = {"1", "2", "3", "4", "5"}; 
    int arrayBaseSystem[] = {10, 10, 10, 10, 10};

    Analyze((const char**)arrayNumbers, arrayBaseSystem, countNumbers);

    printf("Expected output:\n");
    printf("Sorted: 1, 2, 3, 4, 5\n");
    printf("Min: 1, Max: 5, Mean: 3, Median: 3\n");
    printf("\n");
}

void Test8()
{
    int countNumbers = 3;
    char *arrayNumbers[] = {"1.1", "10.01", "0.111"}; 
    int arrayBaseSystem[] = {2, 2, 2};

    Analyze((const char**)arrayNumbers, arrayBaseSystem, countNumbers);

    printf("Expected output:\n");
    printf("Sorted: 0.875, 1.5, 2.25\n");
    printf("Min: 0.875, Max: 2.25, Mean: 1.541666666666667, Median: 1.5\n");
    printf("\n");
}

void Test9()
{
    int countNumbers = 0;
    char *arrayNumbers[0]; 
    int arrayBaseSystem[0];

    Analyze((const char**)arrayNumbers, arrayBaseSystem, countNumbers);

    printf("Expected output:\n");
    printf("No valid numbers to analyze.\n");
    printf("\n");
}

void Test10()
{
    int countNumbers = 3;
    char *arrayNumbers[] = {"1A", "9Z", "111"}; 
    int arrayBaseSystem[] = {16, 16, 2};

    Analyze((const char**)arrayNumbers, arrayBaseSystem, countNumbers);

    printf("Expected output:\n");
    printf("Error: couldn't convert a number\n");
    printf("Sorted: 7, 26\n");
    printf("Min: 7, Max: 26, Mean: 16.5, Median: 16.5\n");
    printf("\n");
}