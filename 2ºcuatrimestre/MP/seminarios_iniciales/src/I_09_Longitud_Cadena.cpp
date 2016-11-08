//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
// Fichero: longitud_cadena.cpp
// Cálculo de la longitud de una cadena clásica
/***************************************************************************/

#include "I_09_Longitud_Cadena.h"

using namespace std;

//Función global que calcula la longitud de una cadena clásica
//recibe un puntero a v, la dir. de la primera posició de v

int LongitudCadena(char *p){
	//creamos un puntero *p que apunta a la primera posición de v
	char *p = &v;
	//incializamos longitud a 0
	int longitud = 0; 
	//bucle que irá desde la primera hasta que encuentre el '\0' de forma que incrementará
	//la longitud con cada vuelta
	while(*p != '\0'){
		longitud++;
		//apuntamos a l siguiente posición
		p++;
	}

	//devolvemos la longitud

	return(longitud);
}