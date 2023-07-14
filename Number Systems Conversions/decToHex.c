/*
    Writer's notes
    ========================
    ! This file is an implementation for decimal to Hexadecimal algorthim.
    * It only works for integers.
    ! It is recommended to use "Better Comments" extension when reading this.

*/

/*
    Explaining the Algorithm
    ========================
    ! 1 > To convert from decimal to Hexadecimal the original number has to be divided by 16.
    ! 2 > The remainder of the division is taken (0 - 16). => the remainder for (55/16) is 7 and 3 remains.
    ! 3 > Now the remaining number(s) (3) are divided by 16 to repeat the process until the remaining number is 0.

*/

/*
    Explaining the code
    ========================
    ? 1 > We scan for the decimal that is to be converted.
    ? 2 > We start a loop to repeat the division until the remaining number is 0.
    ? 3 > We take the remainder of dividing the number by 16 and then store it inside an array
    ?    because a number as 55 would have a 2 digit binary number.
    ? 4 > We continue to divide the number by 16 to complete the algorithm as mentioned above.
    ? 5 > If a number is greater than 9 it is stored as a letter so we apply an (if-statement) before stroing in the array.
    ? 6 > we start a loop to print all the the numbers in the array from last to first.

*/

// ======================================================== The Code ======================================================== //

#include <stdio.h>

int main()
{
    int decimal, remainder, firstCounter, original;
    char hexadecimal[10000];

    printf("Please enter a decimal to be converted to Hexadecimal\n");
    scanf("%d", &decimal); //? 1 > We scan for the decimal that is to be converted.
    original = decimal;
    for (firstCounter = 0; decimal > 0; firstCounter++) //? 2 > We start a loop to repeat the division until the remaining number is 0.
    {
        remainder = (decimal % 16);
        if (remainder < 10) //? 3 > We take the remainder of dividing the number by 16 and then store it inside an array
        {
            hexadecimal[firstCounter] = '0' + remainder;
        }
        else
        {
            if (remainder == 10) //? 5 > If a number is greater than 9 it is stored as a letter so we apply an (if-statement) before stroing in the array.
            {
                hexadecimal[firstCounter] = 'A';
            }
            else if (remainder == 11)
            {
                hexadecimal[firstCounter] = 'B';
            }
            else if (remainder == 12)
            {
                hexadecimal[firstCounter] = 'C';
            }
            else if (remainder == 13)
            {
                hexadecimal[firstCounter] = 'D';
            }
            else if (remainder == 14)
            {
                hexadecimal[firstCounter] = 'E';
            }
            else if (remainder == 15)
            {
                hexadecimal[firstCounter] = 'F';
            }
        }

        decimal /= 16; //? 4 > We continue to divide the number by 16 to complete the algorithm as mentioned above.
    }
    printf("The Binary for the decimal number [%i] is => ", original);
    for (int secondCounter = firstCounter; secondCounter >= 0; secondCounter--) //? 6 > we start a loop to print all the the numbers in the array from last to first.
    {
        printf("%c", hexadecimal[secondCounter]);
    }
}