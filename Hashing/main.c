#include "emde.h"
/*
TODO: Fix the STDIN reading, it's not working properly.

"" as argument gives: d41d8cd98f00b204e9800998ecf8427e which is correct.
"" as STDIN gives: a227d42afbcc590b4e949075cde4a5b6 which is incorrect.
*/
void print_hash(uint8_t *firstelementArray)
{
    for (unsigned int i = 0; i < 16; ++i)
    {
        printf("%02x", firstelementArray[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    uint8_t result[16];

    if (argc > 1)
    {
        for (int i = 1; i < argc; ++i)
        {
            md5String(argv[i], result);
            print_hash(result);
        }
    }
    else
    {
        printf("No args found! reading from stdin...\n");
        char input[1024];
        while (fgets(input, 1024, stdin) != NULL)
        {
            md5String(input, result);
            print_hash(result);
        }
    }
}