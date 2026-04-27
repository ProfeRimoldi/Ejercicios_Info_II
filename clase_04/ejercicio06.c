/*
Realizar un programa que copie un archivo a otro cuyos nombres estarán indicados como argumentos del main. Así: copy archivo_original.txt archivo_copia.txt.
*/

#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]){
    if (argc<3){
        printf("Uso: <archivo_fuente>, <archivo_destino");
        return 1;
    }
    FILE *fp1;
    FILE *fp2;
    fp1=fopen(argv[1], "rt");
    if(fp1==NULL){
        printf("No se pudo abrir <archivo_fuente>");
        return 1;
    }
    fp2=fopen(argv[2], "w");
    int a;
    if(fp2==NULL){
        printf("No hay permiso de escritura en este disco");
    }

    while((a=fgetc(fp1))!=EOF){
        fputc(a, fp2);
    }
    printf("Fin de la copia");



    fclose(fp1);
    fclose(fp2);
    return 0;
}