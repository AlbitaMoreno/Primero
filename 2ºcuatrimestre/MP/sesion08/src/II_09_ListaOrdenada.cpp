//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
//II_09_ListaOrdenada.cpp.cpp
//
/***************************************************************************/

#include <iostream>
#include <stdlib.h>
#include "ListasBasicos.h"

using namespace std;

bool EstaOrdenada(const Lista );

int main(){

	Lista l;

	LeeLista(l);

	PintaLista(l);

	cout << "Comprobando si la lista está ordenada...";
	if(EstaOrdenada(l))
		cout << "La lista esta ordenada" << endl;
	else
		cout << "La lista NO esta ordenada" << endl;

	LiberaLista(l);
	
	return(0);
}

bool EstaOrdenada(const Lista l){
	bool ordenada = true;
	Lista aux = l;			//apunta inicialmente al primer nodo
	Lista aux2 = l->sig;	//apuntará al nodo que siguiente a aux

	if(ListaVacia(l))
		
		cout << "La lista está vacía";

	else{
		while(ordenada && aux2 != 0){
		
			if(aux->info > aux2->info)
				ordenada = false;
			else{
				aux = aux->sig;
				aux2 = aux2->sig;
			}
		}
	}
	return(ordenada);
}