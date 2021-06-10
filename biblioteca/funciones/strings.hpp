#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int length(string s) // OK
{
   int i;
   for( i = 0; s[i]!='\0'; i++ )
   {
   }
   return i;
}
/*Descripción: Cuenta la cantidad de veces que aparece el carácter c dentro de s.
 Parámetros:
 */
int charCount(string s, char c) // OK

{
   int i = 0;
   int count = 0;

   while( s[i]!='\0' )
   {
      if( s[i]==c )
         count++;

      i++;
   }

   return count;
}
/* Descripción: Retorna la subcadena de s comprendida entre las posiciones d (inclu-
 sive) y h (no inclusive).

 Hola, como estas?\0
 */
string substring(string s, int d, int h) // OK
{
   // string i = "";
   string st = "";

   for( int i = d; i<h; i++ )
   {
      st = st+s[i];
   }

   return st;
}
/*Descripción: Retorna la subcadena de s comprendida entre la posición d y el final
 de la cadena.
 */
string substring(string s, int d) // OK
{
   string st = "";

   for( int i = d; i<length(s); i++ )
   {
      st = st+s[i];
   }

   return st;
}
//Descripción: Retorna la posición que ocupa la primera ocurrencia del carácter c
//dentro de la cadena s.
int indexOf(string s, char c) // OK
{

   for( int i = 0; i<length(s); i++ )
   {
      if( s[i]==c )
      {
         return i;
      }

   }

   return -1;
}
/*Retorna la posición que ocupa la primera ocurrencia de un carácter c
 dentro de la cadena s, descartando los primeros offeset caracteres (desplaza-
 miento inicial).
 */
int indexOf(string s, char c, int offSet) // OK
{

   for( int i = offSet; i<length(s); i++ )
   {
      if( s[i]==c )
      {
         return i;
      }

   }
   return -1;
}

/*Retorna la posición que ocupa la primera ocurrencia de toSearch
 dentro de la cadena s.
 */
int indexOf(string s, string toSearch) // OK
{
   int i;
   string r = "";
   for( i = 0; i<length(s); i++ )
   {
      if( s[i]==toSearch[0] )
      {
         r = substring(s,i,length(toSearch)+i);
        if( r==toSearch )
         {
            return i;
         }
      }

   }
   return -1;
}

/*Retorna la posición que ocupa la primera ocurrencia de toSearch
 dentro de la cadena s, descartando los primeros offeset caracteres (desplaza-
 miento inicial).
 */
int indexOf(string s, string toSearch, int offSet) // OK
{
   int i;
   string r = "";
   for( i = offSet; i<length(s); i++ )
   {
      if( s[i]==toSearch[0] )
      {
         r = substring(s,i,length(toSearch)+i);
         return i;
      }
   }
   return 0;
}
/*Retorna la posición de la última ocurrencia del carácter c dentro de s.*/

int lastIndexOf(string s, char c) // OK
{

   for( int i = length(s); i>=0; i-- )
   {
      if( s[i]==c )
      {
         return i;
      }

   }

   return -1;
}

/*Retorna la posición de la n-ésima ocurrencia de c dentro de s. Si n es
 0 (cero) retorna -1; si n es mayor que la cantidad de ocurrencias de c retorna la
 longitud de la cadena s.*/
int indexOfN(string s, char c, int n) // OK
{
   if( n!=0 )
   {
      int r;
      int o = 0;
      int pos = 0;

      for( int i = 0; i<length(s); i++ )
      {
         if( c==s[i]&&pos<n )
         {
            r = indexOf(s,c,o);
            o = i+1;
            pos++;
         }
      }
      return r;
   }

   return -1;
}
/*
 * Retorna el valor numérico del carácter c (que debe ser numérico).
 Parámetros: char c - Carácter cuyo valor será: '0', '1', ... o '9'.
 */

int charToInt(char c) // OK
{
   return c-'0';
}
/*Retorna el carácter que representa al valor de
 * i, que debe estar com-prendido entre 0 y 9. Es la función inversa de charToInt.
 */
char intToChar(int i) // OK
{
   return '0'+i;
}
//Retorna el i-ésimo dígito del valor de n.

int powm(int a, int b)
{
   int t = 1;
   for( int i = 0; i<b; i++ )
   {
      t *= a;
   }
   return t;
}
int getDigit(int n, int i) // OK
{
   int p = powm(10,i);
   int j = n/p;

   return j%10;
}

// Retorna la cantidad de dígitos que contiene el valor de n.
// 12345
int digitCount(int n) //OK
{
   if( n==0 )
   {
      return 1;
   }

   int i = 0;
   double j = n;
   while( j>=1 )
   {
      j = j/10;
      i++;
   }

   return i;
}

// Retorna una cadena de caracteres representando el valor i.
string intToString(int i) //OK
{
   string r = "";
   int j = 0;

   for( j = digitCount(i); j>0; j-- )
   { //

      r += intToChar(getDigit(i,j-1));

   }
   return r;
}
/*
 * Retorna el valoro numérico representado en la cadena s, considerando
 *  que dicho valor está expresado en la base numérica b.
 */

int stringToInt(string s, int b) // OK
{
   int i = 0;
   int m = 0;
   int valor = length(s);
   int p = 0;
   for( i = valor; i>0; i-- )
   {
      int x;
      char f = s[i-1];
      if( f>='0'&&f<='9' )
      {
         x = '0';
      }
      else
      {
         x = 'A'-10;
      }
      m += (f-x)*powm(b,p);
      p++;
   }

   return m;
}

/*Retorna el valor numérico de la cadena s, que sólo debe contener dígitos numéricos
 * en base 10. Esta función es la función inversa de intToString.
 */
int stringToInt(string s) // OK
{
   int c = stringToInt(s,10);
   return c;
}
/*Retorna una cadena cuyo único carácter es c.
 */
string charToString(char c) // OK
{
   string r = "";

   r += c;

   return r;
}
/* Retorna el único carácter que contiene la cadena s. Esta es la función
 inversa de charToString. */
char stringToChar(string s) // OK
{
   char q = 0;

   return s[q];
}
/*
 * Retorna la misma cadena que recibe. Se trata de una función trivial que
 usaremos más adelante, dentro de este mismo capítulo.
 */
string stringToString(string s) // OK
{
   return s;
}

//Retorna una cadena representando el valor contenido en d.
string doubleToString(double d) //
{
//123.4
   int entero = d/1; // = 123
   int i = 0;
   int j = 0;
   double t = d-entero; // = 0.4
   while( t!=0 )
   {
      t *= 10; //  = 4.0
      j = t/1; //  = 4
      t -= j;  //  =4-4 = 0

      if( i<4 )
      {
         i++;
      }
      else
      {
         t = 0;
      }
   }
   int mantisa = (d-entero)*powm(10,i); // 0.4x10e1 = 4

   string f = intToString(entero)+"."+intToString(mantisa); // 123.4
   return f;
}
/*
 * Retorna el valor numérico representado en la cadena s.
 Parámetro: string s - Cadena que contiene un valor compatible con double.
 */
double stringToDouble(string s)
{
   string entero = "";
   string mantisa = "";
   int cont = 0;

   for( int i = 0; s[i]!='.'; i++ )
   {
      entero += s[i];

   }
   for( int t = length(s)-1; s[t]!='.'; t-- )
   {
      mantisa = s[t]+mantisa;
      cont++;
   }
   int e = stringToInt(entero);
   double m = stringToInt(mantisa);
   double ret = e+(m/powm(10,cont));

   return ret;

}
/* Retorna true o false según s sea o no la cadena vacía. */

bool isEmpty(string s) // OK
{
   if( s=="" )
   {
      return true;
   }
   return false;
}

/*
 * Determina si x es prefijo de s.
 */
bool startsWith(string s, string x) //OK
{

   string m = substring(s,0,length(x));

   if( m==x )
   {
      return true;
   }

   return false;
}
/*
 * Determina si x es sufijo de s.
 */
bool endsWith(string s, string x) // OK
{

   string m = substring(s,(length(s)-length(x)));

   if( m==x )
   {
      return true;
   }
   return false;
}
//Determinar si la cadena s contiene al carácter c.
bool contains(string s, char c) // OK
{
   int i = 0;
   bool ret = false;
   while( s[i]!='\0' )
   {
      if( s[i]==c )
      {
         ret = true;
      }

      i++;
   }
   return ret;
}
/*
 * Reemplaza en s todas las ocurrencias de oldChar por newChar.
 */
string replace(string s, char oldChar, char newChar) // OK
{
   string ret = s;

   int i = 0;

   while( s[i]!='\0' )
   {
      if( s[i]==oldChar )
      {
         ret[i] = newChar;
      }

      i++;
   }
   return ret;
}

/*
 * Insertar el carácter c en la posición pos de la cadena s.
 */
string insertAt(string s, int pos, char c)
{
   string r = substring(s,0,pos)+c+substring(s,pos);
   return r;
}
//Remover de s el carácter ubicado en la posición pos.

string removeAt(string s, int pos) // OK
{
   string r = substring(s,0,pos)+substring(s,pos+1);
   return r;
}
//Recorta los espacios en blanco que se encuentren a la izquierda de s.
string ltrim(string s) // OK
{
   string ret = s;
   for( int i = 0; s[i]==' '; i++ )
   {
      ret = removeAt(ret,i);
   }

   return ret;
}
// Recortar los espacios en blanco a la derecha de s.
string rtrim(string s)
{
   string ret = s;
   for( int i = length(s)-1; s[i]==' '; i-- )
   {
      ret = removeAt(ret,i);
   }

   return ret;
}
// Recortar los espacios en blanco ubicados a izquierda y derecha de s.
string trim(string s) // OK
{
   string ret = ltrim(rtrim(s));
   return ret;
}
/*
 * Generar una cadena de caracteres compuesta por n caracteres c.
 */
string replicate(char c, int n) // OK
{
   string ret = "";
   int i;
   for( i = 0; i<n; i++ )
   {
      ret += c;
   }
   if( c==' ' )
   {
      ret = " ";
   }

   return ret;
}
/*
 * Genera una cadena de caracteres compuesta por n caracteres ' '.
 */
string spaces(int n) // OK
{
   string ret = "";
   int i;
   for( i = 0; i<n; i++ )
   {
      ret += ' ';
   }
   return ret;
}
/*
 * Retorna una cadena idéntica a s, con longitud n completando, si fuese
 necesario, con caracteres c a la izquierda hasta llegar a la longitud requerida.
 */
string lpad(string s, int n, char c)
{

   int p = n-length(s);
   string ret = replicate(c,p)+s;

   return ret;
}
// Descripción: Idem lpad pero, de ser necesario, agrega caracteres c a la derecha.
string rpad(string s, int n, char c) //OK
{
   int p = n-length(s);
   string ret = s+replicate(c,p);

   return ret;
}
// Idem rpad pero distribuye los caracteres c a izquierda y derecha.
string cpad(string s, int n, char c) //OK
{
   int i = n-length(s);
   string ret = "";

   if( (i%2)==0 )
   {
      ret = replicate(c,(i/2))+s+replicate(c,(i/2));
   }
   else
   {
      ret = replicate(c,(i/2))+s+replicate(c,((i/2)+1));
   }
   return ret;
}
// Determinar si el valor de c corresponde o no a un dígito numérico.
bool isDigit(char c) //OK
{
   if( c>='0'&&c<='9' )
   {
      return true;
   }

   return false;
}
// Determina si el valor de c corresponde o no a una letra.
bool isLetter(char c) // OK
{
   if( (c>='A'&&c<='Z') or (c>='a'&&c<='z') )
   {
      return true;
   }

   return false;
}
// Determinar si el valor de c corresponde a una letra mayúscula.
bool isUpperCase(char c) // OK
{
   if( c>='A'&&c<='Z' )
   {
      return true;
   }

   return false;

}
// Determina si el valor de c corresponde a una letra minúscula.
bool isLowerCase(char c) // OK
{
   if( c>='a'&&c<='z' )
   {
      return true;
   }

   return false;
}

// Convertir el valor de c a mayúscula.
char toUpperCase(char c) //OK
{
   return c-32;
}
// Descripción: Convierte el valor de c a minúscula.
char toLowerCase(char c) // OK
{
   return c+32;
}
#endif
