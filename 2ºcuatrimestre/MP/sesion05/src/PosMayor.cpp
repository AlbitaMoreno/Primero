// 
// Fichero: PosMayor.cpp
// Version 1
//Contiene la implementacion de la funcion PosMayor
/***************************************************************************/

#include "PosMayor.h"
using namespace std;

int *PosMayor(int *pv, int izq, int der){
	int iteraciones = der - izq;
	//el primer elemento será el máximo, es la base con la que empiezo a hacer las comparaciones
	
	int *aux = pv + izq;
	int max = *aux;

	for (int i = 0; i <= iteraciones; i++, aux++){
		//si *pv es mayor que el maximo, entonces reasigno el valor de maximo
		if(*aux > max){
			max = *aux;
		}
	}
	//una vez acabadas las comprobaciones le asigno a *pv el valor del maximo
	*pv = max;
	return(pv);
}