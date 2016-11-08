#include <stdlib.h>
#include <stdio.h>
/*
 Este programa trata de sumar una lista de números.
 La lista de números aparece en la variable "vector" y el resultado
 se almacena en la variable "final".
*/

/* Suma dos números entre sí */
int suma (float x, float y)
{
   float tmp;

   tmp = x + y; 

   return tmp;
}

/* Realiza la sumatoria de un vector */
int sumatoria (float vector[], int n)
{
   int i;
   float tmp;

   tmp = 0;
   for (i = 0; i < n; i ++)
      tmp = suma(tmp, vector[i]);

   printf ("Suma = %f\n", tmp);

   return tmp;
}

int main (void)
{
   float final;
   float vector[] = {0, 1, 2.3, 3.7, 4.10, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4};

   final = sumatoria(vector, 15);

   return 0;
}

