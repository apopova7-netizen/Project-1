#include "student1.h"

int main(void) {
    int baseNumberSystem1, baseNumberSystem2;
    char *number = malloc((MAX_LENGTH_OF_NUMBER + 1) * sizeof(char));

    if (number == NULL) {
        puts("Memory Error");
        return 0;
    }

    /* Asks for the bases of the number systems, the number, and checks that the data has been read */
    puts("Enter the initial, final number systems and number");

    if (scanf("%d %d %13s", &baseNumberSystem1, &baseNumberSystem2, number) != 3){
        puts("Bad input");
        free(number);
        return 0;
    }
    /* Check that no extra data has been entered */
    if (CheckInput() == 0) {
        puts("Bad input");
        free(number);
        return 0;
    }

    if (ValidateBase(baseNumberSystem1) == 0 || ValidateBase(baseNumberSystem2) == 0) {
        puts("Bad input");
        free(number);
        return 0;
    }

    /* Checks if the number is entered correctly. */
    int valid = ValidateNumber(number, baseNumberSystem1);

    if (valid == 0) {
        puts("Bad input");
        free(number);
        return 0;
    }

    if (valid == MEMORY_ERROR_INT) {
        puts("Memory Error");
        free(number);
        return 0;
    }

    /* Converts the number to the decimal number system from the initial
     * number system. */
    double numberInDecimal = StringToDecimal(number, baseNumberSystem1);

    if (numberInDecimal == MEMORY_ERROR_DOUBLE) {
        puts("Memory Error");
        free(number);
        return 0;
    }

    /* Converts the number from the decimal number system to the final number system. */
    char * result = DecimalToString(numberInDecimal, baseNumberSystem2);

    if (result == MEMORY_ERROR_CHAR) {
        puts("Memory Error");
        free(number);
        return 0;
    }

    /* Rounds a number to 12 decimal places. */
    char* roundingResult = Rounding(result,baseNumberSystem2);

    if (roundingResult == MEMORY_ERROR_CHAR) {
        puts("Memory Error");
        free(number);
        free(result);
        return 0;
    }

    printf("%s\n", roundingResult);

    free(number);
    free(result);
    free(roundingResult);
    return 0;
}


