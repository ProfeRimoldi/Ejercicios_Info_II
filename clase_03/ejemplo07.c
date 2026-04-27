#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    char *verbose = getenv("USER");
    if (verbose != NULL) {
        printf("La variable USER es: %s\n", verbose);
    } else {
        printf("USER no esta definida.\n");
    }
    return 0;
}