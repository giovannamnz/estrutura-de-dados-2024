#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    printf("\n%s %s\n", argv[1], argv[2]);

#ifndef _teste
#error "Chame a funcao teste()"
#endif

    exit(0);
}