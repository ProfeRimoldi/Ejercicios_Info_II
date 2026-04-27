/*
Concatenar dos archivos de texto (poner uno a continuación del otro en un mismo archivo).
*/
#include <stdio.h>

int main (){
    FILE *fp1;
    FILE *fp2;

    fp1=fopen("docuA.txt", "rt"); //Docu de lectura
    fp2=fopen("docuB.txt", "a");
    if (fp1==NULL){
        perror("Error abriendo archivo de lectura\n");
        return 1;
    }
    if (fp2==NULL){
        perror("Error abriendo archivo modo appendn\n");
    }
    
    int a;

    while((a=fgetc(fp1))!=EOF){
        fputc(a, fp2);
    }

    printf("Archivo escrito en documento de destino\n");

    fclose(fp1);
    fclose(fp2);
}