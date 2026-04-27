#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc > 1 && (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)) {
        printf("Uso: %s <text 1> <text 2> ... <text n>\n", argv[0]);
        return 0;
    }
    if (argc < 3) {
        printf("Error: se esperan minimo 2 argumentos.\n");
        return 1;
    }
        printf("Numero de argumentos (argc): %d\n", argc);

    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    return 0;
}