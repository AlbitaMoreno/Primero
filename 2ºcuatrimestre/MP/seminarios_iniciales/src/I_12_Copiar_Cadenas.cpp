//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
// Fichero: I_12_Copiar_Cadenas.cpp
// Cálculo de la longitud de una cadena clásica
/***************************************************************************/

#include "I_12_Copiar_Cadenas.h"
using namespace std;

//copiar la cadena origen en la cadena resultado
void CopiarCadena(char *resultado,const char *origen){
	//mientars origen sea distinto del char nulo entonces copia el contenido de la direccion
	//apuntada por origen en la direccion apuntada por resultado
	while(*origen != '\0'){
		*resultado = *origen;
		//incremento origen y resultado para moverme en los vectores
		resultado++;
		origen++;
	}
}