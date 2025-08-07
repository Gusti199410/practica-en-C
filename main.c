#include"header.h"
#include"vector.h"
int main()
{

   int opcion;
   tVector *vec;
   char buscar[max_nombre];
   cargar_Producto_Ejemplo(archivo);
   ordenar_archivo(archivo,vec);
   printf("\t\t*********************************\n");
   printf("\t\t*    CAJA DE NEGOCIO            *\n");
   printf("\t\t*********************************\n");
   printf("\n\n");

   printf("1-VENTA MINORISTA\n");
   printf("2-VENTA MAYORISTA\n");
   printf("3-CONSULTAR PRECIO\n");
   printf("4-CONSULTAR STOCK\n");
   printf("INGRESE OPCION: ");
   scanf("%d",&opcion);
   switch(opcion){
       case 1:
           return 0;
           break;
       case 2:
           return 0;
           break;
       case 3:
           printf("INGRESE EL NOMBRE PRODUCTO: ");
           scanf("%s",buscar);
           break;
       case 4:
           mostrar_Producto(archivo);
           break;
   }
   return 0;

}
