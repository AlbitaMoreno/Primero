// 
// Fichero: PosMayor.cpp
// 
//Contiene la implementacion de la funcion Ordena
/***************************************************************************/

#include "Ordena.h"

using namespace std;

void Ordena(int *vec, int *p_ptr[], int izq, int dcha){
	int util = dcha - izq + 1;
	//paso a comparar el valor apuntado por cada puntero y si no estan ordendos los intercambio
	for(int i = 0; i < util; i++){
		for(int j = izq; j < dcha; j++){
			//si el contenido de p_ptr[j] es mayor que el de j+1 entonces intercambio posiciones
			if(*p_ptr[j] > *p_ptr[(j+1)]){
				int *p = p_ptr[j];
				p_ptr[j] = p_ptr[j+1];
				p_ptr[j+1] = p;
			}
		}
	}
}
