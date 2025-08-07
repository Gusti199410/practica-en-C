#include "ventas_minorista.h"
bool crear_Venta_Minorista(const char *arc, const char *buscar)
{
    tVentas venta;
    FILE *fp=fopen(arc,"rb");
    if(!fp)
    {
        printf("No se puede leer el archivo");
        return false;
    }
    Producto prod;
    fread(&prod,sizeof(Producto),1,fp);
    while(!feof(fp))
    {
        if(strcmp(prod.nombre_Producto,buscar)==0)
        {
            venta.suma+=prod.valor_Minorista;
            venta.total_Productos++;
        }else
        {
            fread(&prod,sizeof(Producto),1,fp);
        }

    }
    return true;

}
