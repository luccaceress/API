#ifndef _TFILES_T_
#define _TFILES_T_

#include <iostream>
#include <stdio.h>
//Escribe el valor t en la posición actual del archivo f.
template<typename T> void write(FILE* f, T t)
{
   fwrite(&t,sizeof(T),1,f);
}

template<typename T> T read(FILE* f)
{
   T t;
   fread(&t,sizeof(T),1,f);
   return t;
}
//Mueve el indicador de posición del archivo f al inicio del registro n.
template<typename T> void seek(FILE* f, int n)
{
   fseek(f,sizeof(T)*n,SEEK_SET);
}
//Retorna la cantidad de registros tipo T que contiene el archivo.

template<typename T> int fileSize(FILE* f)
{

   fseek(f,0,SEEK_END);
   int ret = ftell(f)/sizeof(T);

   return ret;
}
// Retorna el número de registro que está siendo apuntado por el
//indicador de posición del archivo f.
template<typename T> int filePos(FILE* f)
{
   return ftell(f)/sizeof(T);
}

#endif
