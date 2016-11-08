//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
//II_10_OrdenarLista.cpp
//
/***************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "ListasBasicos.h"

using namespace std;
//La funcion para ordenar la lista está en ListasBasicos.cpp
int main(){

	Lista l;
	int longitud;

	cout << "Introduzca la longitud: " << endl;
	cin >> longitud;
	
	RellenaListaAleatoriamente(l,longitud,0,20);

	PintaLista(l);
	
	cout << endl;
	cout << "Ordenando... " << endl;

	OrdenaLista(l);
	cout << endl;
	PintaLista(l);
	LiberaLista(l);
	cout << endl;
	
	return (0);
}

