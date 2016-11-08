//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
// Fichero: I_13_Encadenar_Cadena.cpp
// Cálculo de la longitud de una cadena clásica
/***************************************************************************/


#include "I_13_Encadenar_Cadena.h"
using namespace std;

void EncadenarCadena(char *resulado, const char *origen){
	//este bucle llega al final de la cadena resultado
	while(*resulado != '\0'){
		resulado++;
	}
	//resultado está apuntando a la última posicion de memoria
	//una vez tengo el final de la cadena lo que hago es sobreescribir los valores desde
	//el '\0' hasta el final de origen

	while(*origen != '\0'){
		*resulado = *origen;
		resulado++;
		origen++;
	}
}