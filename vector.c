#include"vector.h"

bool crear_Vector(tVector *vec,size_t tamanio)
{
    vec->vec=malloc(sizeof(Producto)*tamanio);
    if(!vec->vec)
    {
        printf("Error al asignar memoria");
        return false;
    }
    vec->ce=0;
    vec->tamanio=tamanio;
    vec->tamElem=sizeof(Producto);
    return true;

}

bool asignar_Memoria(tVector *vec)
{
    if(vec->tamanio==vec->ce)
    {
        size_t nuevo_Tamanio=vec->tamanio*2;
        void *aux=realloc(vec->vec,nuevo_Tamanio*sizeof(Producto));
        if(aux==NULL)
        {
            printf("Error al agregar memoria");
            return false;
        }
        vec->vec=aux;
        vec->tamanio=nuevo_Tamanio;
    }

    return true;
}

bool destruir_Memoria(tVector *vec)
{
    free(vec->vec);
    vec->tamanio=0;
    vec->tamElem=0;
    vec->ce=0;
    return true;
}

bool insertar_Elemento(tVector *vec,Producto *ingreso)
{
    if(vec->ce >= vec->tamanio)
    {
        asignar_Memoria(vec);
    }

    void *fin=vec->vec + vec->tamanio *vec->ce;

    ///copia el elemento en la nueva posicion

    memcpy(fin,&ingreso,vec->tamanio);
    vec->ce++;
    return true;
}
bool ordenar_archivo(const char *arc,tVector *vec)
{
   FILE *fp=fopen(arc,"rb");
   if(!fp)
   {
       printf("Error al abrir el archivo");
       return false;
   }

   Producto prod;

   fseek(fp,0,SEEK_END);

   size_t tam=ftell(fp);

   size_t ce=tam/sizeof(Producto);

   crear_Vector(vec,ce);

   rewind(fp);

   while(fread(&prod,sizeof(Producto),1,fp)==1)
   {
       insertar_Elemento(vec,&prod);
   }
   mostrar_Elemento_Memoria(vec);

    fclose(fp);
      destruir_Memoria(vec);

    return true;
}
