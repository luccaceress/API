#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

int tokenCount(string s, char sep) //OK
{
   int i = 0;

   if( !isEmpty(s) )
   {
      i = charCount(s,sep)+1;
   }
   return i;
}
/*
 * Agrega el token t al final de la cadena s.
 */

void addToken(string& s, char sep, string t) // OK
{

   if( length(s)==0 )
   {
      s = t;
   }
   else
   {
      s += sep+t;
   }

}

// Retorna el i-ésimo token de la cadena tokenizada s.
string getTokenAt(string s, char sep, int i) // OK
{
   string ret = "";
   int p = indexOfN(s,sep,i);

   if( p==length(s) )
   {
      ret = s;
   }
   if( p==lastIndexOf(s,sep) )
   {
      ret = substring(s,p+1);
   }
   else
   {
      ret = substring(s,p+1,indexOfN(s,sep,i+1));
   }

   return ret;
}
// Remueve de s el token ubicado en la posición i.
void removeTokenAt(string& s, char sep, int i) // OK
{
   int p = tokenCount(s,sep);
   int j = length(getTokenAt(s,sep,i));

   if( p!=1&&i!=0 )
   {
      s = substring(s,0,indexOfN(s,sep,i))+substring(s,indexOfN(s,sep,i)+j+1);
   }

   if( p!=1&&i==0 )
   {
      s = substring(s,j+1);
   }
   if( p==1 )
   {
      s = ""; // si hay solo un token
   }

}

// Reemplaza por t el token de s ubicado en la posición i.
void setTokenAt(string& s, char sep, string t, int i) //OK
{
   int p = tokenCount(s,sep);
   int j = length(getTokenAt(s,sep,i));

   if( p!=1&&i!=0 )
   {
      s = substring(s,0,indexOfN(s,sep,i))+sep+t+substring(s,indexOfN(s,sep,i)+j+1);
   }

   if( p!=1&&i==0 )
   {
      s = t+sep+substring(s,j+1);
   }
   if( p==1 )
   {
      s = ""+t; // si hay solo un token
   }

}
//Determinar la posición que el token t ocupa dentro de la cadena s.
int findToken(string s, char sep, string t) // OK
{
   int i;
   string r = "";
   for( i = 0; i<tokenCount(s,sep); i++ )
   {
      r = getTokenAt(s,sep,i);
      if( r==t )
      {
         return i;
      }
   }

   return -1;
}

#endif
