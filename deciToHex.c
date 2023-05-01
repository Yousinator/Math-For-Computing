#include <stdio.h>

int main() {
    int decimal,temp,i;
    char hexadecimal[100];

    scanf("%d", &decimal);
    for ( i = 0; decimal > 0; i++){
        temp = (decimal % 16);
        if (temp < 10) {
            hexadecimal[i] = '0' + temp;
        }
        else {
            if (temp == 10) {
                hexadecimal[i] = 'A';
            }
            else if (temp == 11) {
                hexadecimal[i] = 'B';
            }
            else if (temp == 12) {
                hexadecimal[i] = 'C';
            }
            else if (temp == 13) {
                hexadecimal[i] = 'D';
            }
            else if (temp == 14) {
                hexadecimal[i] = 'E';
            }
            else if (temp == 15) {
                hexadecimal[i] = 'F';
            }
        }
        
        decimal /= 16;

    }

    for (int  j= i; j >= 0; j--) {
        printf("%c", hexadecimal[j]);
    }

}