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

int main(){
    float porc=0;
    printf("Mostrando Archivo Binario");
    MostrarArchivo(ARCHIVO);
    getchar();
    printf("Ingrece un porcentaje: ");
    scanf("%f", &porc);
    modificarPrecioDeTodo(ARCHIVO, porc);
    MostrarArchivo(ARCHIVO);
    getchar();

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
    }
    fseek(fp, 0, SEEK_CUR);
    /*fseek(fp, 0, SEEK_SET);
    Producto p;
    fread(&p, sizeof(Producto),1, fp); 
    p.precio*=porc;
    fseek(fp, -1, SEEK_CUR);
    fwrite(&p, sizeof(Producto), 1, fp);*/
    //leo, modifico en struct auxiliar, me corro una estructura para atras, pego con fwrite
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

