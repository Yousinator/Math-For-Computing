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

    scanf("%i", &binaryNum);

    for (firstCounter = 0; binaryNum > 0; firstCounter++)
    {
        rem = binaryNum % 10;
        decimal += rem * pow(2, firstCounter);
        binaryNum /= 10;
    }

    printf("%i", decimal);
    return 0;
}