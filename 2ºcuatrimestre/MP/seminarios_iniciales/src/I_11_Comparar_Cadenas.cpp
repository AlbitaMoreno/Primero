//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
// Fichero: I_11_Comparar_Cadenas.cpp
// Cálculo de la longitud de una cadena clásica
/***************************************************************************/

#include "I_11_Comparar_Cadenas.h"
using namespace std;

int CompararCadenas(char *a,char *b){
	//incialmente las cadenas son iguales,de forma que al ir comparandolas 
	//se resten o se sumen unos según sea el caso
	int contador = 0;

	//mientras no sean *a y *b simultaneamente 0 el bucle continuará, de forma que
	//no necesito el tamaño ya que el while seguirá hasta que el más grande termine
	while(*a != '\0' && *b != '\0'){
		//es valor de la primera es más pequeño que el de la segunda
		if(*a < *b){
			contador--;
			a++;
			b++;
		}
		//la segunda es más pequeña que la primera
		else{
			contador++;
			a++;
			b++;
		}
		//se ha terminado de recorrer la cadena a pero la cadena b es de mayor longitud
		if(*a == '\0'){
			contador--;
			b++;
		}
		//se ha terminado de recorrer b pero a es de mayor longitud
		if(*b == '\0'){
			contador++;
			a++;
		}
	}

	return(contador);
}