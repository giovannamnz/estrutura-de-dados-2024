#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Uso: %s <numero>\n", argv[0]);
        return 1;
    }
 
    int num = atoi(argv[1]);
    if (num <= 1 || (num != 2 && num % 2 == 0)) {
        printf("false\n");
        return 0;
    }
 
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            printf("false\n");
            return 0;
        }
    }
 
    printf("true\n");
    return 0;
}