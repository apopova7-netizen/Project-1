
#ifndef STUDENT1_H
#define STUDENT1_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH_OF_NUMBER 13
#define MAX_LENGTH_OF_FRACTIONAL_PART 12
#define MEMORY_ERROR_CHAR NULL
#define MEMORY_ERROR_DOUBLE (-1.0)
#define MEMORY_ERROR_INT (-1)
#define ALL_DIGITS_MAX 100


inline int ValidateBase(int);
inline int CharToValue(char);
inline char ValueToChar(int);
inline char* AcceptableSymbols(int);
inline int ValidateNumber(const char*, int);
inline void SplitNumberString(const char*, char*,char*);
inline double IntStringToDecimal(const char*, int);
inline double FracStringToDecimal(const char*, int);
inline double StringToDecimal(const char*, int);
inline char* IntDecimalToString(long long, int);
inline char* FracDecimalToString(double, int);
inline char* DecimalToString(double, int);
inline char* Rounding(const char*, int);
inline int MaxDigits(const char*, int, int, int);
inline void AddingUnit(const char*, char*, int, int, int);
inline int DisappearanceOfTheFractionalPart(const char*, int);
inline char *Student1Process(int, int, const char*);

#endif

/*checks the validity of the number system*/
int ValidateBase(int base) {
    if (base >= 2 && base <= 16)
        return 1;
    return 0;
}

/* Returns the numeric value of a character using the ASCII table. */
int CharToValue(const char character) {
    if (character >= '0' && character <= '9')
        return character - '0';

    if (character >= 'a' && character <= 'f')
        return character - 'a' + 10;

    if (character >= 'A' && character <= 'F')
        return character - 'A' + 10;
    return -1;
}

/* Returns the character designation of a number using the ASCII table. */
char ValueToChar(int value) {
    if (value >= 0 && value <= 9)
        return (char)('0' + value);

    return (char)('a' + (value - 10));
}


/* Returns a list of characters that are valid in the given number system. */
char* AcceptableSymbols(int base) {
    int lenList;

    if (base <= 10)
        lenList = base + 1;

    /* For a base greater than 9, the list needs a space for uppercase
     *letters, because the function ValueToChar only returns lowercase letters */
    else
        lenList = base + (base - 10) + 1;

    char *listOfCharacters = malloc((lenList + 1) * sizeof(char));

    if (listOfCharacters == NULL)
        return MEMORY_ERROR_CHAR;

    int capitalLetters = 0;

    for (int i = 0; i < base; i++) {
        *(listOfCharacters + i) = ValueToChar(i);

        /* Adds uppercase letters, leaving space for a point */
        if (i >= 10) {
            capitalLetters++;
            *(listOfCharacters + lenList - 1 - capitalLetters) = (char)('A' + (i - 10));
        }
        }

        *(listOfCharacters + lenList - 1) = '.';
        *(listOfCharacters + lenList) = '\0';

        return listOfCharacters;
    }

/* checks that all characters in the number satisfy the given number system
 * and that there are no leading zeros, dots at the beginning and end of the
 * number, or more than one point*/
int ValidateNumber(const char *number, int base) {
    int len = (int)strlen(number);


    char *list = AcceptableSymbols(base);

    if (list == MEMORY_ERROR_CHAR)
        return MEMORY_ERROR_INT;

    if (*number == '.' || *(number + len - 1) == '.') {
        free(list);
        return 0;
    }
    int point = 0;

    for (int i = 0; i < len; i++)
        if (*(number + i) == '.') {
            point++;

            if (point > 1) {
                free(list);
                return 0;
            }
        }
    /* Checks that each character in the string appears in the list*/
    for (int i = 0; i < len; i++) {
        int validCharacter = 0;

        for (int j = 0; *(list + j) != '\0'; j++)
            if (*(number + i) == *(list + j)) {
                validCharacter = 1;
                break;
            }

        if (validCharacter == 0) {
            free(list);
            return 0;
        }
    }

    /* Checks that an integer does not start with 0 if the number is not zero */
    if (point == 0 && *number == '0' && len != 1){
    free(list);
    return 0;
}
    /* Checks that a real number can only start with 0 when its integer part
     * is zero*/
    if (point == 1 && *number == '0' && *(number + 1) != '.') {
        free(list);
        return 0;
    }
    free(list);
    return 1;
}

/*Splits a string number into its integer and fractional parts.*/
void SplitNumberString(const char* number, char* integerPart, char* fractionalPart) {

    int pointIndex = -1;

    for (int i = 0; *(number + i) != '\0'; i++) {
        if (*(number + i) == '.') {
            pointIndex = i;
            break;
        }
    }
    /* If there is no dot in the number,copies the integer part and
     * leaves the fractional part empty.*/
    if (pointIndex == -1) {
        strcpy(integerPart, number);
        *fractionalPart = '\0';
    }
    else {
        /* copies the integer part*/
        strncpy(integerPart, number, pointIndex);
        *(integerPart + pointIndex) = '\0';

        /* copies the fractional part*/
        strcpy(fractionalPart, number + pointIndex + 1);
    }
}

/* Converts an integer part from a certain number system to decimal using
 * the Gorner algorithm */
double IntStringToDecimal(const char* integerPart, int base) {
    double result = 0;

    for (int i = 0; *(integerPart + i) != '\0'; i++)
        result = result * base + CharToValue(*(integerPart + i));

    return result;
}

/* Converts a fractional part from a certain number system to decimal. */
double FracStringToDecimal(const char* fractionalPart, int base) {
    int len = (int)strlen(fractionalPart);
    double result = 0;

    for (int i = len - 1; i >= 0; i--)
        result = (result + CharToValue(*(fractionalPart + i))) / base;
    return result;
}

/* Converts the integer and fractional parts of a number to the decimal system
 *and sums the results*/
double StringToDecimal(const char* number, int base) {
    char* integerPart = malloc( (MAX_LENGTH_OF_NUMBER + 1) * sizeof(char));

    if (integerPart == NULL)
        return MEMORY_ERROR_DOUBLE;

    char* fractionalPart = malloc( (MAX_LENGTH_OF_FRACTIONAL_PART + 1) * sizeof(char));

    if (fractionalPart == NULL) {
        free(integerPart);
        return MEMORY_ERROR_DOUBLE;
    }

    SplitNumberString(number, integerPart, fractionalPart);

    double intPartInDecimal = IntStringToDecimal(integerPart, base);
    double FracPartInDecimal = FracStringToDecimal(fractionalPart, base);

    double result = intPartInDecimal + FracPartInDecimal;

    free(integerPart);
    free(fractionalPart);

    return result;
}

/* Converts an integer from decimal to a certain number system. */
char* IntDecimalToString(long long number, int base) {
    if (number == 0) {
        char *res = malloc(2 * sizeof(char));

        if (res == NULL)
            return MEMORY_ERROR_CHAR;

        *res = '0';
        *(res + 1) = '\0';
        return res;
    }

    int lenRes = 0;
    long long copyNum = number;

    /* Defines the length of the converted number. */
    while (copyNum > 0) {
        lenRes++;
        copyNum /= base;
    }

    char *result = malloc((lenRes + 1)  * sizeof(char));

    if (result == NULL)
        return MEMORY_ERROR_CHAR;

    *(result + lenRes) = '\0';

    /* Fills an array with characters in reverse order. */
    int i = lenRes - 1;
    while (number > 0) {
        char character = ValueToChar((int)(number % base));
        *(result + i) = character;
        number /= base;
        i--;
    }

    return result;
}

/* Converts the fractional part of a number from decimal to a certain number
 * system. Multiplies the fractional part by the base of the number system.
 * The character designation of the integer part of the resulting number
 * is the first digit after the decimal point of the converted number.
 * The fractional remainder is then converted in a similar manner. */
char* FracDecimalToString(double number, int base) {
    int signsAfterPoint = 0;

    char *result = malloc((MAX_LENGTH_OF_FRACTIONAL_PART + 1 + 1) * sizeof(char));

    if (result == NULL)
        return MEMORY_ERROR_CHAR;

    /* Needs to get the first 13 digits after decimal point for rounding*/
    while (signsAfterPoint < MAX_LENGTH_OF_FRACTIONAL_PART + 1) {
        char character = ValueToChar((int)(number * base));

        *(result + signsAfterPoint) = character;
        signsAfterPoint ++;

        number = number * base - (int)(number * base);

        /* Returns the result earlier if there are fewer than 13 digits after
         * the decimal point.*/
        if (number == 0) {
            break;
        }
    }
    *(result + signsAfterPoint) = '\0';
    return result;
}

/*Converts a number from the decimal number system to the finite number system*/
char* DecimalToString(double number, int base) {

    long long integerPart = (long long)number ;
    double fractionalPart = number - (double)integerPart ;

    /*If the number does not contain a fractional part, simply convert it.*/
    if (fractionalPart == 0.0) {
        char* result = IntDecimalToString(integerPart, base);
        return result;
    }

    /* If there is a fractional part, it converts the integer and fractional parts
     * separately and combines the results*/
    char* convIntPart = IntDecimalToString(integerPart, base);

    if (convIntPart == NULL) {
        return MEMORY_ERROR_CHAR;
    }

    char* convFracPart = FracDecimalToString(fractionalPart, base);
    if (convFracPart == NULL) {
        free(convIntPart);
        return MEMORY_ERROR_CHAR;
    }

    /* Determines the length of the result, including the point */
    int lenRes = (int)strlen(convIntPart) + (int)strlen(convFracPart) + 1;

    char* result = malloc((lenRes + 1) * sizeof(char));

    if (result == NULL)
        return MEMORY_ERROR_CHAR;

    int pointIndex = 0;
    for (int i = 0; i < strlen(convIntPart); i++) {
        *(result + i) = *(convIntPart + i);
        pointIndex = i + 1;
    }

    *(result + pointIndex) = '.';
    int j = 0;
    for (int i = pointIndex + 1; i <= pointIndex + strlen(convFracPart); i++) {
        *(result + i) = *(convFracPart + j);
        j++;
    }

    *(result + lenRes) = '\0';

    free(convFracPart);
    free(convIntPart);

    return result;
}

/* if all the digits on this segment are equal to the maximum digit in this
 * number system, then returns ALL_DIGITS_MAX, otherwise returns the index
 * of the digit that is less than base - 1 and occupies the rightmost position. */
int MaxDigits(const char* number, int index1, int index2, int base) {
    for (int i = index2; i >= index1; i--)
        if (CharToValue(*(number + i)) < base - 1)
            return i;
    return ALL_DIGITS_MAX;
}

/* Increases the number with a digit less than base -1 by one */
void AddingUnit(const char *number,char *result, int index1, int index2, int noMaxDigitIndex) {
    int flag = 0;
    int flagPoint = 0;

    for (int i = index1; i <= index2; i++) {
        if (*(number + i) == '.')
            flagPoint = 1;

        /* The digit at the position whose index was found using
         * the MaxDigits function is increased by 1.*/
        if (i == noMaxDigitIndex) {
            int valueChar = CharToValue(*(number + i));
            *(result + i) = ValueToChar(valueChar + 1) ;
            flag = 1;
        }

        /*All numbers before the one being changed are copied*/
        else if (flag == 0)
            *(result + i) = *(number + i);

        /* If the digit being changed is in the fractional
         * part, then the remaining digits are discarded,
         * if in an integer, then they are replaced by zeros.*/
        else

            if (*(number + i) == '.')
                *(result + i) = '.';

            else if (flagPoint == 0)
                *(result + i) = '0';

            else {
                *(result + i) = '\0';
                break;
            }
    }
    *(result + index2 + 1) = '\0';
}

/* Checks that the fractional part of a number consists only of zeros. */
int DisappearanceOfTheFractionalPart(const char* number, int pointIndex) {
    for (int i = pointIndex + 1; *(number + i) != '\0'; i++)
        if (*(number + i) != '0')
            return 0;
    return 1;
}

/* Rounds the number to 12 decimal places */
char* Rounding(const char* number, int base) {
    int len = (int)strlen(number);
    int pointIndex = -1;

    for (int i = 0; i < len; i++) {
        if (*(number + i) == '.') {
            pointIndex = i;
            break;
        }
    }
    /* If number is an integer, returns it */
    if (pointIndex == -1) {
        char *result = malloc((len + 1) * sizeof(char));

        if (result == NULL)
            return MEMORY_ERROR_CHAR;

        strcpy(result, number);
        return result;
    }

    int lenFracPart = len - pointIndex - 1;

    /* If the number has no more than 12 decimal places, returns it */
    if (lenFracPart <= MAX_LENGTH_OF_FRACTIONAL_PART) {
        char *result = malloc((len + 1) * sizeof(char));

        if (result == NULL)
            return MEMORY_ERROR_CHAR;

        strcpy(result, number);
        return result;
    }
        /* If the value of the last digit is less than half the base of the number
         * system, simply discards the last digit and returns number */
        int valueLastDigit = CharToValue(*(number + len - 1));
        if (valueLastDigit < (double)base / 2) {
            char* result = malloc(len * sizeof(char));

            if (result == NULL)
                return MEMORY_ERROR_CHAR;

            strncpy(result, number, len-1);
            *(result + len - 1) = '\0';

            /* If only zeros remain after discarding the last digit in the
             * fractional part, only the integer part should be returned. */
            if (DisappearanceOfTheFractionalPart(result, pointIndex))
                *(result + pointIndex) = '\0';
            return result;
        }

        /* If the first 12 digits of the fractional part are equal to the maximum
         * in the given number system, returns the integer part of the number
         * increased by 1 */
        int digitFracPart = MaxDigits(number, pointIndex + 1, len - 2, base);

        if (digitFracPart == ALL_DIGITS_MAX) {
            int digitIntPart = MaxDigits(number, 0, pointIndex - 1, base);

            /*If all digits of the integer part are equal to the maximum
             *possible in a given number system, returns 100...0, Where the
             *number of zeros is equal to the length of the integer part
             *of the given number  */
            if (digitIntPart== ALL_DIGITS_MAX) {
                int lenRes = pointIndex + 1;

                char *result = malloc((lenRes + 1) * sizeof(char));

                if (result == NULL)
                    return MEMORY_ERROR_CHAR;

                *result = '1';
                for (int i = 1; i < lenRes; i++)
                    *(result + i) = '0';

                *(result + lenRes) = '\0';
                return result;
            }

            /* If not all digits of the integer part are equal to the maximum
             * in a given number system, uses the function AddingUnit */
            char *result = malloc((pointIndex + 1) * sizeof(char));

            if (result == NULL)
                return MEMORY_ERROR_CHAR;

            AddingUnit(number,result,0,pointIndex - 1, digitIntPart);
            return result;
        }

        /* If not first 12 digits of the fractional part are equal to the maximum
        * in a given number system, uses the function AddingUnit */
        char *result = malloc(len * sizeof(char));

        if (result == NULL)
            return MEMORY_ERROR_CHAR;

        AddingUnit(number, result, 0, len - 2, digitFracPart);
        return result;
    }
char *Student1Process(int baseNumberSystem1,int baseNumberSystem2, const char *number) {

    /* Checks that the length of a number is not greater than 13 */
    if (strlen(number) > MAX_LENGTH_OF_NUMBER){
        puts("Bad input");
        return NULL;
    }
     /* Сhecks that the bases of the number systems are entered correctly */
    if (ValidateBase(baseNumberSystem1) == 0 || ValidateBase(baseNumberSystem2) == 0) {
        puts("Bad input");
        return NULL;
    }

    /* Checks if the number is entered correctly. */
    int valid = ValidateNumber(number, baseNumberSystem1);

    if (valid == 0) {
        puts("Bad input");
        return NULL;
    }

    if (valid == MEMORY_ERROR_INT) {
        puts("Memory Error");
        return NULL;
    }

    /* Converts the number to the decimal number system from the initial
     * number system. */
    double numberInDecimal = StringToDecimal(number, baseNumberSystem1);

    if (numberInDecimal == MEMORY_ERROR_DOUBLE) {
        puts("Memory Error");
        return NULL;
    }

    /* Converts the number from the decimal number system to the final number system. */
    char *result = DecimalToString(numberInDecimal, baseNumberSystem2);

    if (result == MEMORY_ERROR_CHAR) {
        puts("Memory Error");

        return NULL;
    }

    /* Rounds a number to 12 decimal places. */
    char* roundingResult = Rounding(result,baseNumberSystem2);

    if (roundingResult == MEMORY_ERROR_CHAR) {
        puts("Memory Error");
        free(result);
        return NULL;
    }

    free(result);
    return roundingResult;
}







