//
// Created by Lenovo on 05.11.2025.
//

#ifndef PROJECT_1_STUDENT2_H
#define PROJECT_1_STUDENT2_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COUNT_OF_NUMBERS 100
#define MAX_LENGTH_OF_NUMBER 14

inline void BubbleSortDouble(double*, int);
inline void SwapDouble(double*, double*);
inline void SortNumbers(double*, int);
inline double CalculateMean(const double*, int);
inline double CalculateMedian(double*, int);
inline void FindMinMax(const double*, int, double*, double*);
inline int ValidateAndConvertNumber(const char*, int, double*);
inline int ConvertNumbers(const char**, const int*, int, double*);
inline void PrintSortedResults(const double*, int);
inline void PrintStatistics(double, double, double, double);
inline void Analyze(const char**, const int*, int);

#endif //PROJECT_1_STUDENT2_H

/*
 * Function: BubbleSortDouble
 * ---------------------------
 * Sorts an array of doubles in ascending order using the Bubble Sort algorithm.
 *
 * Parameters:
 *  arr  - pointer to the array of doubles
 *  size - number of elements in the array
 */
void BubbleSortDouble(double* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if(arr[j] > arr[j+1])
                SwapDouble(arr + j, arr + j + 1);
}

/*
 * Function: SwapDouble
 * ---------------------
 * Swaps the values of two double variables by their pointers.
 *
 * Parameters:
 *  a, b - pointers to the two doubles to be swapped
 */
void SwapDouble(double* a, double* b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

/*
 * Function: SortNumbers
 * ----------------------
 * Sorts an array of doubles using the BubbleSortDouble function.
 *
 * Parameters:
 *  numbers - pointer to the array of doubles
 *  count   - number of elements in the array
 */
void SortNumbers(double* numbers, int count)
{
    BubbleSortDouble(numbers, count);
}

/*
 * Function: CalculateMean
 * ------------------------
 * Calculates the arithmetic mean (average) of an array of numbers.
 *
 * Parameters:
 *  numbers - pointer to the array of doubles
 *  count   - number of elements in the array
 *
 * Returns:
 *  The mean value (0.0 if the array is empty)
 */
double CalculateMean(const double* numbers, int count)
{
    if(count == 0)
        return 0.0;

    double sum = 0.0;
    for (int i = 0; i < count; i++)
        sum += *(numbers + i);

    return sum / count;
}

/*
 * Function: CalculateMedian
 * --------------------------
 * Calculates the median value of an array of doubles.
 *
 * The function creates a copy of the array, sorts it,
 * and returns the middle value (or the average of the two middle values if even count).
 *
 * Parameters:
 *  numbers - pointer to the array of doubles
 *  count   - number of elements in the array
 *
 * Returns:
 *  The median value
 */
double CalculateMedian(double* numbers, int count)
{
    if(count == 0)
        return 0.0;

    double* copyNumbers = (double*)malloc(count * sizeof(double));
    if(!copyNumbers)
        return 0.0;

    for (int i = 0; i < count; i++)
        *(copyNumbers + i) = *(numbers + i);

    SortNumbers(copyNumbers, count);

    double median;
    if(count % 2 == 0)
        median = (*(copyNumbers + count/2) + *(copyNumbers + count/2 - 1)) / 2.0;
    else
        median = *(copyNumbers + count/2);

    free(copyNumbers);
    return median;
}

/*
 * Function: FindMinMax
 * ---------------------
 * Finds the minimum and maximum values in an array of doubles.
 *
 * Parameters:
 *  numbers - pointer to the array
 *  count   - number of elements in the array
 *  min     - pointer to store the minimum value
 *  max     - pointer to store the maximum value
 */
void FindMinMax(const double* numbers, int count, double* min, double* max)
{
    if(count == 0)
        return;

    *min = *max = *(numbers + 0);
    for (int i = 0; i < count; i++)
    {
        if(*(numbers + i) < *min)
            *min = *(numbers + i);
        if(*(numbers + i) > *max)
            *max = *(numbers + i);
    }
}

/*
 * Function: ValidateAndConvertNumber
 * -----------------------------------
 * Validates a number represented as a string in a given base (2–16),
 * and converts it into a decimal (base 10) double value.
 *
 * Supports fractional parts separated by '.'.
 *
 * Parameters:
 *  numberString - string representing the number
 *  base         - base of the number (2–16)
 *  result       - pointer to store the converted value
 *
 * Returns:
 *  1 if the conversion was successful, 0 otherwise
 */
int ValidateAndConvertNumber(const char* numberString, int base, double* result)
{
    if(!numberString || base < 2 || base > 16)
        return 0;

    const char* symbols = "0123456789ABCDEF";
    char* copyNumberString = (char*)malloc(strlen(numberString) + 1);
    if (!copyNumberString)
        return 0;

    strcpy(copyNumberString, numberString);

    // Convert all letters to uppercase for consistency
    for (int i = 0; *(copyNumberString + i) != '\0'; i++)
        *(copyNumberString + i) = toupper(*(copyNumberString + i));

    char* dot = strchr(copyNumberString, '.');
    double integerPart = 0.0;
    double fractionalPart = 0.0;

    // Split integer and fractional parts
    if(dot)
        *dot = '\0';

    // Process the integer part
    for (int i = 0; *(copyNumberString + i) != '\0'; i++)
    {
        char* sign = strchr(symbols, *(copyNumberString + i));
        if(!sign || (sign - symbols) >= base)
        {
            free(copyNumberString);
            return 0;
        }
        // Each digit is multiplied by base and added
        integerPart = integerPart * base + (sign - symbols);
    }

    // Process the fractional part, if present
    if(dot)
    {
        char* fractional = dot + 1;
        double denominator = (double)base;

        for (int i = 0; *(fractional + i) != '\0'; i++)
        {
            char* sign = strchr(symbols, *(fractional + i));
            if(!sign || (sign - symbols) >= base)
            {
                free(copyNumberString);
                return 0;
            }
            fractionalPart += (sign - symbols) / denominator;
            denominator *= base;
        }
    }

    free(copyNumberString);
    *result = integerPart + fractionalPart;
    return 1;
}

/*
 * Function: ConvertNumbers
 * -------------------------
 * Converts an array of string-based numbers (each in a specific base)
 * into their decimal (double) equivalents.
 *
 * Parameters:
 *  numberStrings - array of string representations of numbers
 *  bases         - array of bases corresponding to each number
 *  count         - number of elements to process
 *  results       - output array for converted values
 *
 * Returns:
 *  The number of successfully converted values
 */
int ConvertNumbers(const char** numberStrings, const int* bases, int count, double* results)
{
    int validCount = 0;
    for (int i = 0; i < count; i++)
    {
        double value;
        if(ValidateAndConvertNumber(*(numberStrings + i), *(bases + i), &value))
        {
            *(results + validCount) = value;
            validCount++;
        }
        else
        {
            printf("Error: couldn't convert a number\n");
        }
    }
    return validCount;
}

/*
 * Function: PrintSortedResults
 * -----------------------------
 * Prints the sorted list of numbers to the console.
 *
 * Parameters:
 *  numbers - array of numbers
 *  count   - number of elements
 */
void PrintSortedResults(const double* numbers, int count)
{
    printf("Sorted: ");
    for (int i = 0; i < count; i++)
    {
        printf("%f", *(numbers + i));
        if(i < count - 1)
            printf(", ");
    }
    printf("\n");
}

/*
 * Function: PrintStatistics
 * --------------------------
 * Prints statistical information: minimum, maximum, mean, and median.
 */
void PrintStatistics(double min, double max, double mean, double median)
{
    printf("Min: %f, Max: %f, Mean: %f, Median: %f\n", min, max, mean, median);
}

/*
 * Function: Analyze
 * ------------------
 * Main analysis function that:
 *  1. Converts all input numbers into decimal form.
 *  2. Sorts them.
 *  3. Calculates min, max, mean, and median.
 *  4. Prints the results.
 */
void Analyze(const char** numberStrings, const int* bases, int count)
{
    double* numbers = malloc(count * sizeof(double));
    if (!numbers)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    int validCount = ConvertNumbers(numberStrings, bases, count, numbers);
    if(validCount == 0)
    {
        printf("No valid numbers to analyze.\n");
        free(numbers);
        return;
    }

    SortNumbers(numbers, validCount);

    double min, max;
    FindMinMax(numbers, validCount, &min, &max);
    double mean = CalculateMean(numbers, validCount);
    double median = CalculateMedian(numbers, validCount);

    PrintSortedResults(numbers, validCount);
    PrintStatistics(min, max, mean, median);

    free(numbers);
}
