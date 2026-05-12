#include<stdio.h>

#define ARCHIVO "productos.dat"
typedef struct punto2
{
    int codigo;
    float precio;  
    char descrip [50]; /* data */
} Producto;

void MostrarArchivo (const char *nombreArchivo);

int main(){
    printf("Mostrando Archivo Binario");
    MostrarArchivo(ARCHIVO);
    getchar();

    return 0;
}

void MostrarArchivo (const char *nombreArchivo){
    FILE *fp = fopen(nombreArchivo, "r+");
    if (!fp){
        perror("Error al abrir el archivo");
        return;
    }
    Producto p;
    while (fread(&p, sizeof(Producto), 1, fp) == 1) {
        printf("Codigo: %3d | Precio: $%7.2f | Descripcio: %-15s\n", p.codigo, p.precio, p.descrip);
    }
    fclose(fp);
}

