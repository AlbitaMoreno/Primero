//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
//II_07_ListasBasicos.cpp
//
/***************************************************************************/

#include <iostream>
#include <stdlib.h>
#include "ListasBasicos.h"

using namespace std;

int main(){

	Lista l;

	LeeLista(l);
	PintaLista(l);

	cout << endl;

	if(ListaVacia(l))
		cout << "La lista está vacía" << endl;
	else
		cout << "La lista no está vacía" << endl;
	
	LiberaLista(l);

	cout << endl;
	int longitud;

	cout << "Longitud de la lista aleatoria: ";
	cin >> longitud;

	RellenaListaAleatoriamente(l,longitud,0,20);	//creo una lista con 5 elemneto del 0 al 9
	
	PintaLista(l);

	LiberaLista(l);

	return(0);
}