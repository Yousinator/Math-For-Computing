/*
    Writer's notes
    ========================
    ! This file is an implementation for decimal to binary algorthim.
    * It only works for integers.
    ! It is recommended to use "Better Comments" extension when reading this.

*/

/*
    Explaining the Algorithm
    ========================
    ! 1 > To convert from decimal to binary the original number has to be divided by 2.
    ! 2 > The remainder of the division is taken (It's either 0 or 1). => the remainder for (55/2) is 1 and 27 remains.
    ! 3 > Now the remaining number(s) (27) are divided by 2 to repeat the process until the remaining number is 0.

*/

/*
    Explaining the code
    ========================
    ? 1 > We scan for the decimal that is to be converted.
    ? 2 > We start a loop to repeat the division until the remaining number is 0.
    ? 3 > We take the remainder of dividing the number by 2 and then store it inside an array.
    ?    because a number as 55 would have a 6 digit binary number.
    ? 4 > We continue to divide the number by two to complete the algorithm as mentioned above.
    ? 5 > we start a loop to print all the the numbers in the array from last to first.

*/

// ======================================================== The Code ======================================================== //

#include <stdio.h>

int main()
{

    int decimal, remainder, binary[10000], firstCounter, final;

    printf("Please enter a decimal to be converted to binary\n");
    scanf("%i", &decimal); //? 1 > We scan for the decimal that is to be converted.
    final = decimal;

    for (firstCounter = 0; decimal > 0; firstCounter++)
    { //? 2 > We start a loop to repeat the division until the remaining number is 0 or less.
        remainder = decimal % 2;
        binary[firstCounter] = remainder; //? 3 > We take the remainder of dividing the number by 2 and then store it inside an array.
        decimal = decimal / 2;            //? 4 > We continue to divide the number by two to complete the algorithm as mentioned above.
    }

    printf("The Binary for the decimal number [%i] is => ", final);
    for (int secondCounter = firstCounter - 1; secondCounter >= 0; secondCounter--)
    { //? 5 > we start a loop to print all the the numbers in the array from last to first.
        printf("%i", binary[secondCounter]);
    }

    return 0;
}