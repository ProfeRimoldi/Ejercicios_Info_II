/*
4. Realizar un programa que busque una palabra en un archivo de texto y si está varias veces indicar cuántas. La palabra se debe ingresar como argumento del main.
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    if(argc<2){
        printf("Uso: <palabra>\n");
        return 1;
    }
    FILE *fp;
    fp=fopen("texto.txt","rt");
    if(fp==NULL){
        printf("Documento corrupto\n");
        return 1;
    }

    char palabra[100];
    int cant=0;
    while(fscanf(fp, "%s", palabra)!=EOF){
        if(strcmp(palabra, argv[1])==0)
        cant++;
    }
    if(!cant)
        printf("No se encontro la palabra '%s'\n", argv[1]);
    if(cant)
        printf("'%s', esta '%d' veces en el texto.\n", argv[1], cant);
    fclose(fp);
    return 0;
}