#ifndef _TCOLL_T_
#define _TCOLL_T_

#include <iostream>
#include "../funciones/strings.hpp"

using namespace std;

int cmpInt(int a, int b)
{
   return a<b?-1:a>b?1:0;
}

template <typename T>
struct Coll // OK
{
   // como es una cadena tokenizada el struct va a ser la forma del token
   string cadena;
   char sep;
   int cont;
};
/*
 * Crea una colección vacía, preparada para contener elementos de tipo T;
 utilizando el carácter sep como separador de la cadena tokenizada sobre la que se
 implementa la colección.
 */

template <typename T> // OK
Coll<T> coll(char sep)
{
   Coll<T> c;
   c.sep = sep;
   c.cadena = "";
   c.cont = -1;

   return c;
}
/*Crea una colección vacía, preparada para contener elementos tipo T;
 definiendo un separador por defecto para usar en la cadena tokenizada sobre la
 cual se implementa la colección. */

template <typename T> // OK
Coll<T> coll()
{
   Coll<T> c;
   c.sep = '|';
   c.cadena = "";
   c.cont = -1;
   return c;
}

// Retorna la cantidad de elementos que contiene la colección c.
template <typename T>
int collSize(Coll<T> c) // OK
{
   return tokenCount(c.cadena,c.sep);
}

// Remueve de la colección c todos sus elementos, dejándola vacía.
template <typename T>
void collRemoveAll(Coll<T>& c)
{
   c.cadena = "";
}
//Remueve de la colección c el elemento ubicado en la posición p.
template <typename T>
void collRemoveAt(Coll<T>& c, int p)
{
   removeTokenAt(c.cadena,c.sep,p);
}
//Agrega el elemento t al final de la colección c.
template <typename T>
int collAdd(Coll<T>& c, T t, string tToString(T))
{
   string cadenaModificada = tToString(t);
   addToken(c.cadena,c.sep,cadenaModificada);
   return collSize(c)-1;
}
template <typename T>
void collAdd1(Coll<T>& c, T t, string tToString(T))
{
   string cadenaModificada = tToString(t);
   addToken(c.cadena,c.sep,cadenaModificada);

}
// Reemplaza por t al elemento que se ubica en la posición p.
template <typename T>
void collSetAt(Coll<T>& c, T t, int p, string tToString(T))
{
   setTokenAt(c.cadena,c.sep,tToString(t),p);
}
// Retorna el elemento que se ubica en la posición p de la colección c.
template <typename T>
T collGetAt(Coll<T> c, int p, T tFromString(string))
{
   T t = tFromString(getTokenAt(c.cadena,c.sep,p));

   return t;
}

//Determina si la colección c contiene al elemento k.
/* Ejemplo de uso:
 * Coll<int> c = coll<int>();
 collAdd<int>(c,1,intToString);
 collAdd<int>(c,3,intToString);
 collAdd<int>(c,2,intToString);
 cout<<c.cadena<<endl;

 int n = -2;
 n = collFind<int,int>( c, 3,cmpInt, stringToInt);

 cout<<n<<endl;
 */
template <typename T, typename K>
int collFind(Coll<T> c, K k, int cmpTK(T, K), T tFromString(string))
{
   T t;
   int cant = collSize<T>(c);
   for( int i = 0; i<cant; i++ )
   {
      t = tFromString(getTokenAt(c.cadena,c.sep,i));
      if( cmpTK(t,k)==0 )
      {
         return i;
      }
   }

   return -1;
}
//Ordena los elementos de la colección c según el criterio de
// precedencia que establece cmpTT.
/*Ejemplo de Uso:
 Coll<int> c = coll<int>();
 collAdd<int>(c,5,intToString);
 collAdd<int>(c,35894,intToString);
 collAdd<int>(c,2,intToString);
 collAdd<int>(c,1,intToString);
 collAdd<int>(c,8,intToString);

 cout<<c.cadena<<endl;

 collSort<int>(c, cmpInt, stringToInt, intToString);
 cout<<c.cadena<<endl;

 */
template <typename T>
void collSort(Coll<T>& c, int cmpTT(T, T), T tFromString(string), string tToString(T))
{
   // funcion pablo
//
//   Coll<T> aux = coll<T>();
//   while( collSize<T>(c)>0 )
//   {
//      int pMin = 0;
//      T min = collGetAt<T>(c,0,tFromString);
//
//      for( int i = 1; i<collSize<T>(c); i++ )
//      {
//         T t = collGetAt<T>(c,i,tFromString);
//         if( cmpTT(t,min)<0 )
//         {
//            min = t;
//            pMin = i;
//
//         }
//         collAdd<T>(aux,min,tToString);
//         collRemoveAt<T>(c,pMin);
//      }
//      c= aux;
//   }


   for( int i = 0; i<(collSize(c)-1); i++ )
   {
      for( int j = 0; j<(collSize(c)-1); j++ )
      {
         T t = tFromString(getTokenAt(c.cadena,c.sep,j));
         T k = tFromString(getTokenAt(c.cadena,c.sep,j+1));
         if( cmpTT(t,k)>0 )
         {
            collSetAt (c, t, j+1,tToString);
            collSetAt (c, k, j,tToString);
         }
      }
   }
}
// Retorna true o false según queden, en la colección c, más elementos
//para continuar iterando.
template <typename T>
bool collHasNext(Coll<T> c)
{
   return (c.cont<(collSize(c)-1))?true:false;
}
// Retorna el próximo elemento de la colección c.
template <typename T>
T collNext(Coll<T>& c, T tFromString(string))
{
   T t = tFromString(getTokenAt(c.cadena,c.sep,(c.cont+1)));
   c.cont++;
   return t;
}
// Reinicia la colección c para que la podamos volver a iterar.
template <typename T>
void collReset(Coll<T>& c)
{
   c.cont = -1;
}
// para usar la app
//template <typename T>
//Coll<T> coll
//{
//   Coll<T> x;
//   x.sep= s[0];
//
//}

#endif
