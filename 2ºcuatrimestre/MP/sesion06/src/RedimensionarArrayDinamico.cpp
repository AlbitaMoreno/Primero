//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
//RedimensionarArrayDinamico.cpp
//
/***************************************************************************/

#include <cstdio>
#include <cstring>
#include "RedimensionarArrayDinamico.h"

#include <iostream>

using namespace std;

void Copia(int *destino, int *origen, int n){
	for(int i = 0; i < n; i++){
		destino[i] = origen[i];
	}
}

int *Redimensiona(int *ptr, TipoRedimension tipo, int &cap){
	int *p;
	int uso = cap;
	if(tipo == DeUnoEnUno){
		
		//la ampliacion del vector se hace de 1 en 1
		cap++;
		p = new int [cap];
		Copia(p,ptr,uso);
	}

	if(tipo == EnBloques){
		//el aumeno en bloques, lo haré con bloques de 4
		cap += TAM_BLOQUE;
		p = new int [cap];
		Copia(p,ptr,uso);
	}

	if(tipo == Duplicando){
		cap *= 2;
		p = new int [cap];
		Copia(p,ptr,uso); 
	}
	//devuelvo p , que tiene el nuevo vector con la nueva cap, y los elemntos copiados del vector pasado por ptr
	//hago delete del vector que hemos pasado a la función, porque devuelvo el vector actualizado
	delete [] ptr;
	ptr = p;
	return(ptr);
}