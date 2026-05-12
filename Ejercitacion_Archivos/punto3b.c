#include<stdio.h>

#define ARCHIVO "productos.dat"
typedef struct punto2
{
    int codigo;
    float precio;  
    char descrip [50]; /* data */
} Producto;

void MostrarArchivo (const char *nombreArchivo);
void modificarPrecioDeTodo (const char *nombreArchivo, float porc);

int main(int argc, char *argv[]){
    if(argc !=3){
        printf("Uso del programa: %s [archivo] [porcentaje]\n", argv[0]);
        return 1;
    }
 // Tambien se puede hacer
 // char *nombreArchivo = argv[1];
 // y evitamos la harcodeada del define
    float porc=0;
    sscanf(argv[2], "%f", &porc);
    //float num = atof (argv[2]);
    printf("Mostrando Estado inicial del Archivo Binario\n");
    MostrarArchivo(ARCHIVO);
    
    printf("\nAplicando la modificación de %.2f%%...\n", porc);
    modificarPrecioDeTodo(ARCHIVO, porc);

    printf("\nMostrando el archivo modificado\n");
    MostrarArchivo(ARCHIVO);

    return 0;
}
void modificarPrecioDeTodo (const char *nombreArchivo, float porc){
    FILE *fp = fopen(nombreArchivo,"r+");
    if (!fp){
        perror("Error al abrir el archivo");
        return;
    }
    Producto p;
    rewind(fp); //fseek (fp, 0, SEEK_SET);
    while((fread(&p, sizeof(Producto), 1, fp))==1){
        p.precio +=p.precio*(porc/100);
        fseek(fp, -sizeof(Producto), SEEK_CUR);
        fwrite(&p, sizeof(Producto), 1, fp);
        fseek(fp, 0, SEEK_CUR);
    }
    
    fclose(fp);
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

