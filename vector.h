#ifndef VECTOR
#define VECTOR
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include"header.h"
#define archivo "producto.dat"
typedef struct
{

    void **vec;
    size_t ce;
    size_t tamElem;
    size_t tamanio;

}tVector;

typedef  struct
{
    int id;
    char nombre[max_nombre];

}tVector_Idx;

bool crear_Vector(tVector *vec,size_t tamanio);
bool insertar_Elemento(tVector *vec, Producto *ingreso);
bool asignar_Memoria(tVector *vec);
bool destruir_Memoria(tVector *vec);
void mostrar_Elemento_Memoria(tVector *vec);
bool ordenar_archivo(const char *arc,tVector *vec);
#endif // VECTOR
