#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int verbose = (getenv("VERBOSE") != NULL);

    if (argc <3 ) {
        printf("Uso: %s <num 1> <num2 2> \n", argv[0]);
        return 1;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    if (verbose) {
        printf("Argumentos recibidos: %d\n", argc);
        printf("Convirtiendo '%s' -> %d\n", argv[1], a);
        printf("Convirtiendo '%s' -> %d\n", argv[2], b);
        printf("Calculando %d + %d...\n", a, b);
    }

    printf("Resultado: %d\n", a + b);
    return 0;
}