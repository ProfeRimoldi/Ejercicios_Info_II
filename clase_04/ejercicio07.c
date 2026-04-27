/*
Escriba un programa que lea el contenido de la variable de entorno PATH y lo almacene en un archivo de texto llamado path.txt. Como extra, que cada ruta quede en una línea distinta.
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp;
    fp=fopen("path.txt", "wt");
    if(fp==NULL){
        perror("No tiene permiso de escritura.\n");
        return 1;
    }
    int a;
    char *c=getenv("PATH");
    if(c!=NULL){
        while(*c!='\0'){
        if(*c==':'){
            fputc('\n',fp);
        }
        else{
            fputc(*c, fp);
        }
        c++;
        }
    }
    printf("Fin.\n");

    fclose(fp);
    return 0;

    //printf("%s",c);
}