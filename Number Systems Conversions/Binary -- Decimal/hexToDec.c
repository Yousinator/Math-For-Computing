/*
    Writer's notes
    ========================
    ! This file is an implementation for binary to decimal algorthim.
    * It only works for integers.
    ! It is recommended to use "Better Comments" extension when reading this.
    ! It is recommended to view the (Number Systems Conversions/README.md) "Binary to Decimal" subsection first.

*/

/*
    Explaining the Algorithm
    ========================
    ! 1 > To convert from binary to decimal each binary digit is multiplied by its weight (Ex: 1 * 2^2).
    ! 2 > The sum of all binary digits multiplied be their weight is taken to produce the decimal number.
    * View the (Number Systems Conversions/README.md) "Binary to Decimal" subsection for further explanation.

*/

/*
    Explaining the code
    ========================
    ? 1 > We scan for the binary number that is to be converted.
    ? 2 > We start a loop to repeat the division until the remaining number is 0.
    ? 3 > We take the remainder of dividing the number by 10 to take each digit individually.
    ? 4 > We multiply the remainder number by its weight.
    ? 5 > We continue to divide the number by two to complete the algorithm as mentioned above.
    ? 6 > we start a loop to print all the the numbers in the array from last to first.

*/

//! ======================================================== The Code ======================================================== !//
#include <stdio.h>
#include <math.h>

int main()
{
    int binaryNum, firstCounter, decimal = 0, rem;
    char number[1000];

    scanf("%s", &number);

    for (firstCounter = 0; number[firstCounter] != NULL; firstCounter++)
    {
        if (remainder == 'A') //? 5 > If a number is greater than 9 it is stored as a letter so we apply an (if-statement) before stroing in the array.
        {
            number[firstCounter] = '10';
        }
        else if (remainder == 'B')
        {
            number[firstCounter] = '11';
        }
        else if (remainder == 'C')
        {
            number[firstCounter] = '12';
        }
        else if (remainder == 'D')
        {
            number[firstCounter] = '13';
        }
        else if (remainder == 'E')
        {
            number[firstCounter] = '14';
        }
        else if (remainder == 'F')
        {
            number[firstCounter] = 'F';
        }
        rem = (char)number[firstCounter];

        decimal += rem * pow(2, firstCounter);
    }

    printf("%i", decimal);
    return 0;
}