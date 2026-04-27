#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error: falta un numero.\n");
        return 1;
    }

    float valor = atof(argv[1]);  // Convierte sin verificar
    printf("[atof] Valor convertido: %.2f\n", valor);

    return 0;
}