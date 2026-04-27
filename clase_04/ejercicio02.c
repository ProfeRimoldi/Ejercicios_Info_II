/*
Hacer un programa que compare dos archivos de texto e indique si tienen o no igual contenido.
*/
#include <stdio.h>

int main(){
    FILE *fp1;
    FILE *fp2;
    fp1 = fopen("docuA.txt", "rt");
    fp2 = fopen("docuB.txt", "rt");
    if (fp1 == NULL){
        printf("No se puede abrir docuA\n");
        return 1;
    }
    if (fp2 == NULL){
        printf("No se puede abrir docuB\n");
        return 1;
    }
    int a = 0;
    int b = 0;
    int iguales = 1;//Si empiezo con 0, si ambos archivos están vacíos dice que son distintos
    //while((a=fgetc(fp1))!= EOF && (b=fgetc(fp2))!= EOF){ si uno es EOF ya no consulta por el otro y da "distintos"
    while ((a=fgetc(fp1))== (b=fgetc(fp2)) && a!=EOF)
    {
            iguales = 1;
    }
    if(a!=b){
        iguales = 0; //Por si ambos archivos están vacíos
    }
    if (iguales == 1 && a == EOF && b == EOF) //si uno termina antes no marca que son distintos.
        printf("Los archivos son iguales\n");
    else
        printf("Los archivos son distintos\n");
    fclose(fp1);
    fclose(fp2);
    return 0;

}