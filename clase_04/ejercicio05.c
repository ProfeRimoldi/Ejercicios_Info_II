#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]){
    if(argc <2){
        printf("Uso: <nombre de archivo>\n");
        return 1;
    }
    FILE *fp;
    fp=fopen(argv[0], "rt");
    if(fp==NULL){
        printf("No se pudo abrir el archivo\n");
        return 1;
    }
    int c;
    while ((c=fgetc(fp))!=EOF)
    {
        putchar(c);
    }
    fclose(fp);

}