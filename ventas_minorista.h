#ifndef VENTAS_MINORISTA_H_INCLUDED
#define VENTAS_MINORISTA_H_INCLUDED
#include"header.h"
#include"vector.h"
typedef struct
{
    int nroVentas;
    int total_Productos;
    float suma;
    float resta_producto;

}tVentas;

bool crear_Venta_Minorista(const char *arc,const char *buscar);



#endif // VENTAS_MINORISTA_H_INCLUDED
