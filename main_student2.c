#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student2.h"

/*
 * Program: Base Conversion and Statistical Analysis
 * --------------------------------------------------
 * This program:
 *  1. Accepts several numbers from the user (as strings).
 *  2. Each number is entered together with its base (from 2 to 16).
 *  3. Converts all valid numbers into decimal values.
 *  4. Sorts them and calculates statistics (min, max, mean, median).
 * 
 * The program uses dynamic memory allocation for flexibility.
 */

int main() {
    // Allocate memory for pointers to strings (numbers)
    char** arrayNumbers = (char**)malloc(MAX_COUNT_OF_NUMBERS * sizeof(char*)); 
    // Allocate memory for integer bases
    int* arrayBaseSystem = (int*)malloc(MAX_COUNT_OF_NUMBERS * sizeof(int)); 

    if (!arrayNumbers || !arrayBaseSystem) {
        printf("Memory allocation error!\n");
        return 1;
    }

    int count = 0; // Number of successfully entered values
    char buffer[MAX_LENGTH_OF_NUMBER]; // Temporary input buffer for each number

    printf("Enter numbers (Press Enter on empty line to finish):\n");

    while (count < MAX_COUNT_OF_NUMBERS)
    {
        printf("Number #%d: ", count + 1);

        // Read one line from stdin
        if (!fgets(buffer, MAX_LENGTH_OF_NUMBER, stdin))
            break;

        // Remove newline if present
        buffer[strcspn(buffer, "\n")] = '\0';

        // If empty line — stop input
        if (buffer[0] == '\0')
        {
            printf("Input finished.\n");
            break;
        }

        // Allocate memory for this number string
        *(arrayNumbers + count) = (char*)malloc(strlen(buffer) + 1);
        if (!*(arrayNumbers + count))
        {
            printf("Memory allocation error!\n");
            break;
        }

        // Copy the input into dynamically allocated memory
        strcpy(*(arrayNumbers + count), buffer);

        // Ask for the base system
        int base;
        printf("Base system (2-16): ");
        if (scanf("%d", &base) != 1 || base < 2 || base > 16)
        {
            printf("Invalid base input!\n");
            free(*(arrayNumbers + count)); // Free the last allocated number
            break;
        }
        *(arrayBaseSystem + count) = base;

        // Clear leftover newline from input buffer
        getchar();

        count++;
    }

    // If at least one number was entered — analyze
    if (count > 0)
    {
        Analyze((const char**)arrayNumbers, arrayBaseSystem, count);
    }
    else
    {
        printf("No numbers entered.\n");
    }

    // Free all allocated memory
    for (int i = 0; i < count; i++)
        free(*(arrayNumbers + i));

    free(arrayNumbers);
    free(arrayBaseSystem);

    return 0;
}
