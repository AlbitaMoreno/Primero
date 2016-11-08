//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
// Fichero: I_10_Palindromo.cpp
// Cálculo de la longitud de una cadena clásica
/***************************************************************************/

#include "I_10_Palindromo.h"
#include <string.h>

using namespace std;

bool palindromo(char *p){
	bool palindromo;

	char *izq = &v[0];
	char *der = &v[(strlen(v)-1)];
	//mientras no se crucen los punteros el bucle compaara el contenido de ambos en 
	//ese instante, si son iguales entonces es un palindromo, pero si una letra falla, 
	//entramos en el if, lo que hace es apuntar ambos punteros a la posicion incial para 
	//que salgan del bucle while, devolviendo así palindromo = false si una letra no coincide
	while(izq <= der){
		palindromo = (*izq == *der);
		izq++;
		der--;
		if(!=palindromo){
			izq = der = &v[0];
		}
	}

	//devuelvo palindromo
	return(palindromo);
}