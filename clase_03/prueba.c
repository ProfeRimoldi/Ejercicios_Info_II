#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    char *verbose = getenv("VERBOSE");
    if (verbose != NULL) {
        printf("La variable VERBOSE es: %s\n", verbose);
    } else {
        printf("VERBOSE no esta definida.\n");
    }
    return 0;
}