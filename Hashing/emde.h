#ifndef EMDE_H
#define EMDE_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    uint64_t size; // This is the total size of the input in bytes
    uint32_t buffer[4];
    uint8_t input[64]; // Input buffer for partial blocks
    uint8_t digest[16];
} MD5Context;

void md5Init(MD5Context *ctx);
void md5Update(MD5Context *ctx, uint8_t *input, size_t input_len);
void md5Finalize(MD5Context *ctx);
void md5Step(uint32_t *buffer, uint32_t *input);
void md5String(char *input, uint8_t *result);
#endif