#ifndef HEADER
#define HEADER
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max_nombre 50

typedef struct
{
    int idProducto;
    char nombre_Producto[max_nombre];
    float costo;
    float valor_Minorista;
    float valor_Mayorista;
    int stock;

}Producto;

//bool cargar_Producto(Producto *prod,tVector *vec);
bool cargar_Producto_Ejemplo(const char *arch);
void mostrar_Producto(const char *arch);
bool eliminar_Producto(Producto *Producto);
void imprimir_Lista_Producto(Producto *producto);

#endif // HEADER
