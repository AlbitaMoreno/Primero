//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
//RedimensionarArrayDinamico.h
//
/***************************************************************************/

#ifndef Redimensionar_Array_Dinamico
#define REDIMENSIONAR_ARRAY_DINAMICO

/**************************************************************************/
/**************************************************************************/
//VARIABLES GLOBALES
const int TAM = 3;
const int TAM_BLOQUE = 4;
/**************************************************************************/
/**************************************************************************/
//Cabeceras

enum TipoRedimension {DeUnoEnUno, EnBloques, Duplicando};

void Copia(int *, int *, int);

int *Redimensiona(int *ptr, TipoRedimension tipo, int &cap);


#endif