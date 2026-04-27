#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error: falta un número.\n");
        return 1;
    }

    char *fin;
    float valor = strtof(argv[1], &fin);

    if (*fin != '\0') {
        printf("Error: '%s' no es un numero valido.\n", argv[1]);
        return 1;
    }

    printf("[strtof] Valor convertido: %.2f\n", valor);
    return 0;
}