/*
Crear una función que ordene el archivo “productos.dat” por precio de menor 
a mayor y los guarde en “porPrecio.dat” y los muestre en pantalla.
*/

#include<stdio.h>
#include<string.h>

#define ARCHIVO_BIN "productos.dat"
#define ARCHIVO_TXT "productos.txt"
#define ARCHIVO_ORDENADO "porPrecio.dat"

typedef struct punto2
{
    int codigo;
    float precio;  
    char descrip [50]; /* data */
} Producto;

void OrdenarPorPrecio(const char *archivoOrigen, const char *archivoDestino);
void MostrarArchivo(const char *nombreArchivo);
void modificarPrecioDeTodo (const char *nombreArchivo, float porc);
void modificarPrecio(const char *nombreArchivo, char*descripcionBusqueda, float nuevoPrecio);
void MigrarATexto (const char *nombreBin, const char *nombreTxt);


int main(){
    char buscar[50];
    float precioNuevo;
    printf("Mostrando Estado inicial del Archivo Binario\n");
    //MostrarArchivo(ARCHIVO_BIN);
    printf("\nExportando datos a productos.txt\n");
    MigrarATexto(ARCHIVO_BIN, ARCHIVO_TXT);
    printf("\nOrdenando archivo por precio...\n");
    OrdenarPorPrecio(ARCHIVO_BIN, ARCHIVO_ORDENADO);
    
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
        fprintf(txt, "Codigo: %d\t| Precio: %.2f\t| Descripcio: %s\t\n", p.codigo, p.precio, p.descrip);
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
    FILE *fp = fopen(nombreArchivo, "rb");
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
 void OrdenarPorPrecio(const char *archivoOrigen, const char *archivoDestino){
    FILE *entrada = fopen(archivoOrigen, "rb");
    if(!entrada){
        perror("Error al abrir el archivo de origen");
        return;
    }
    
    Producto productos[10];
    int i = 0;
    
    // Leemos de a 1 registro por vez de forma limpia
    while (i < 10 && fread(&productos[i], sizeof(Producto), 1, entrada) == 1){
        i++; // Avanzamos el índice SOLO si la lectura fue exitosa
    }
    int cant = i; // cant va a valer exactamente 10 si el archivo tiene 10 elementos
    fclose(entrada);
    
    // Si no leyó nada, salimos para evitar romper la burbuja
    if (cant == 0) {
        printf("El archivo de origen estaba vacío.\n");
        return;
    }

    Producto aux;
    // Algoritmo de Burbuja corregido
    for(int j = 0; j < cant - 1; j++){
        for (int k = 0; k < cant - 1 - j; k++){
            if(productos[k].precio > productos[k+1].precio){
                // Intercambio completo de la estructura
                aux = productos[k];
                productos[k] = productos[k+1];
                productos[k+1] = aux;
            }
        }
    }

    // Creamos el nuevo archivo binario desde cero ("wb")
    FILE *salida = fopen(archivoDestino, "wb");
    if (!salida) {
        perror("Error al crear el archivo de destino");
        return;
    }
    
    // Escribimos exactamente la cantidad de elementos reales que leímos
    fwrite(productos, sizeof(Producto), cant, salida);
    fclose(salida);

    // Mostramos en pantalla el resultado leyendo el archivo recién creado
    printf("\n=== ARCHIVO ORDENADO POR PRECIO MENOR A MAYOR (%s) ===\n", archivoDestino);
    MostrarArchivo(archivoDestino);
}