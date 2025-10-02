#include <stdio.h>
#include <stdlib.h>

unsigned long hash(const char *str)
{
    unsigned long hash = 6969;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

int encrypt(int c, const char *key)
{
    int key_hash = hash(key);
    return c ^ key_hash;
}

int main(int argc, const char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./encrypt [key]\n");
        exit(-1);
    }
    const char *input_key = argv[1];
    int c;
    while ((c = getc(stdin)) != EOF)
    {
        int c_enc =encrypt(c, input_key);
        putc(c_enc, stdout);
    }
    
}