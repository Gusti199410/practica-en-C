#include"header.h"
#include"vector.h"

bool cargar_Producto(Producto *prod,tVector *vec)
{
    printf("INGRESE ID DEL PRODUCTO");
    scanf("%d",&prod->idProducto);
    while(prod->idProducto!= 0)
    {
        printf("INGRESE NOMBRE: ");
        scanf("%s",prod->nombre_Producto);
        printf("INGRESE EL COSTO: ");
        scanf("%f",&prod->costo);
        prod->valor_Minorista=prod->costo*1.45;
        prod->valor_Mayorista=prod->costo*1.2;
        if(vec->tamanio==vec->ce)
        {
            asignar_Memoria(vec);
        }
        ((Producto*)vec->vec)[vec->ce]=*prod;
        vec->ce++;
        printf("INGRESE ID DEL PRODUCTO");
        scanf("%d",&prod->idProducto);
    }
    return true;
}



bool cargar_Producto_Ejemplo(const char* arch )
{
    FILE *fp = fopen(arch,"wb");
    if(!fp)
    {
        printf("Error al crear archivo");
        return false;
    }
    Producto productos[] = {
    {1,  "Arroz"    ,       120.00, 174.00, 144.00, 50},
    {4,  "Fideos"   ,      90.00,  130.50, 108.00, 80},
    {3,  "Azucar"   ,      85.00,  123.25, 102.00, 60},
    {11, "Leche"    ,       150.00, 217.50, 180.00, 40},
    {5,  "Aceite"   ,      200.00, 290.00, 240.00, 30},
    {6,  "Pan"      ,         60.00,  87.00,  72.00, 100},
    {7,  "Galletas" ,    75.00,  108.75, 90.00, 75},
    {30, "Yerba"    ,       300.00, 435.00, 360.00, 25},
    {29, "Cafe"     ,        400.00, 580.00, 480.00, 15},
    {10, "Sal"      ,        50.00,  72.50,  60.00, 90},
    {21, "Manteca"  ,     250.00, 362.50, 300.00, 35},
    {12, "Queso"    ,       500.00, 725.00, 600.00, 20},
    {13, "Jamon"    ,       450.00, 652.50, 540.00, 18},
    {14, "Pollo"    ,       800.00, 1160.00,960.00, 12},
    {15, "Carne"    ,       1200.00,1740.00,1440.00,10},
    {17, "Huevos"   ,      220.00, 319.00, 264.00, 28},
    {25, "Tomate"   ,      180.00, 261.00, 216.00, 45},
    {18, "Papa"     ,        140.00, 203.00, 168.00, 50},
    {33, "Cebolla"  ,     130.00, 188.50, 156.00, 55},
    {20, "Zanahoria",   160.00, 232.00, 192.00, 48}
};
size_t ce=sizeof(productos)/sizeof(productos[0]);
fwrite(productos,sizeof(Producto),ce,fp);
fclose(fp);
return true;

}

void mostrar_Producto(const char *arch)
{
    FILE *fp = fopen(arch, "rb");
    if (!fp)
    {
        printf("No se puede leer el archivo\n");
        exit(1);
    }

    Producto prod;
    while (fread(&prod, sizeof(Producto), 1, fp) == 1)
    {
        printf("ID: \t%15d\n", prod.idProducto);
        printf("PRODUCTO: \t%7s\n", prod.nombre_Producto);
        printf("COSTO: %16.2f\n",prod.costo);
        printf("VALOR MINORISTA: %.2f\n",prod.valor_Minorista);
        printf("VALOR MAYORISTA: %.2f\n",prod.valor_Mayorista);
        printf("-------------------------------------------------\n");
    }

    fclose(fp);
}



void mostrar_Elemento_Memoria(tVector *vec)
{
    Producto *inicio = (Producto*)vec->vec;
    Producto *fin    = inicio + vec->ce;
    for(Producto *i = inicio ; i<fin ; i++)
    {
        printf("PRODUCTO: %s\tCOSTO: %.2f",i->nombre_Producto,i->costo);
    }
}
