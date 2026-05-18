
/*
Realizar la lógica correcta para mostrar la información del archivo 
“productos.txt”

Modifico la conversion a texto para hacerlo mas formal y leer hasta los pipe |
*/
#include<stdio.h>
#include<string.h>

#define ARCHIVO_BIN "productos.dat"
#define ARCHIVO_TXT "productos.txt"

typedef struct punto2
{
    int codigo;
    float precio;  
    char descrip [50]; /* data */
} Producto;

void MostrarArchivoTexto (const char *nombreArchivo);
void MostrarArchivo (const char *nombreArchivo);
void modificarPrecioDeTodo (const char *nombreArchivo, float porc);
void modificarPrecio(const char *nombreArchivo, char*descripcionBusqueda, float nuevoPrecio);
void MigrarATexto (const char *nombreBin, const char *nombreTxt);


int main(){
    char buscar[50];
    float precioNuevo;
    //printf("Mostrando Estado inicial del Archivo Binario\n");
    //MostrarArchivo(ARCHIVO_BIN);
    //printf("\nExportando datos a productos.txt\n");
    MigrarATexto(ARCHIVO_BIN, ARCHIVO_TXT);
    MostrarArchivoTexto(ARCHIVO_TXT);
    
   /*
    printf("Ingrese la descripcion del producto a modificar: \n");
    scanf(" %[^\n]", buscar); // Lee incluyendo espacios
    printf("Ingrese el nuevo precio: ");
    scanf("%f", &precioNuevo);
    */

   // modificarPrecio(ARCHIVO, buscar, precioNuevo);

   // printf("\nMostrando el archivo modificado\n");
   // MostrarArchivo(ARCHIVO);

    return 0;
}
void MigrarATexto(const char *nombreBin, const char *nombreTxt){
    FILE *bin = fopen(nombreBin, "rb");
    FILE *txt = fopen(nombreTxt, "w");
    if(!bin || !txt){
        perror("Error al abrir algún archivo\n");
        return;
    }
    Producto p;
    int contador = 0;
    while (fread(&p, sizeof(Producto), 1, bin)==1){
        fprintf(txt, "%d|%.2f|%s\n", p.codigo, p.precio, p.descrip);
        contador ++;
    }
    printf("\nFinalizada la exportación de %d productos a '%s'\n", contador, nombreTxt);
    fclose(bin);
    fclose(txt);
    
}
void modificarPrecio(const char *nombreArchivo, char*descripcionBusqueda, float nuevoPrecio){
    FILE *fp = fopen(nombreArchivo, "r+");
    if (!fp){
        perror("Error al abrir el archivo");
        return;
    }
    Producto p;
    int encontrado = 0;
    while(fread(&p, sizeof(Producto), 1, fp)==1){
        if(strstr(p.descrip, descripcionBusqueda)!=NULL){
            p.precio = nuevoPrecio;
            fseek(fp, -sizeof(Producto), SEEK_CUR);
            fwrite(&p, sizeof(Producto), 1, fp);
            encontrado = 1;
            printf("\nProducto '%s' actualizado con exito.\n", descripcionBusqueda);
            break;
        }
    }
    if(!encontrado){
        printf("\nEl producto '%s' no existe en el archivo.\n", descripcionBusqueda);
    }
    fclose(fp);
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

void MostrarArchivoTexto (const char *nombreArchivo){
    FILE *fp = fopen(nombreArchivo, "r");
    if (!fp){
        perror("Error al abrir el archivo de texto\n");
        return;
    }
    Producto p;
    printf("\n===INFORMACION DEL ARCHIVO===\n");
    // fscanf devuelve la cantidad de campos que pudo leer correctamente.
    // Usamos [^|] para indicarle que lea la descripción hasta encontrarse con un pipe.
    while (fscanf(fp, "%d|%f|%[^\n]\n", &p.codigo, &p.precio, p.descrip) == 3) {
        // Mostramos los datos de manera prolija en la pantalla
        printf("Codigo: %3d | Precio: $%7.2f | Descripcion: %-15s\n", p.codigo, p.precio, p.descrip);
    }

    fclose(fp);
}