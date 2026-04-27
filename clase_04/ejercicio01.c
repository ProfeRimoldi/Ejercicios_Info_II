/*
Hacer un programa que cuente la cantidad de bytes que contiene un archivo de texto
*/
#include <stdio.h>

int main(){
    FILE *fp;
    fp = fopen("ejercicio1bytes.txt", "rt");
    if (fp==NULL){
        perror("No se pudo abrir el archivo");
        return 1;
    }
    int cant = 0;
    int c;
    while((c = fgetc(fp))!=EOF){
        cant ++;
    }
    printf("Cantidad de Bytes del archivo: %d\n", cant);
    fclose(fp);
    printf("Fin del archivo leído\n");
    return 0;
    
}
