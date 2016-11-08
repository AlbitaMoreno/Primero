//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
//II_11_InsertarEliminarEnListaOrdenada.cpp
//
/***************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "ListasBasicos.h"

using namespace std;

int main(){
	Lista l;

	int longitud;

	do{
		cout << "Introduzca la longitud: " << endl;
		cin >> longitud;
	}while(longitud < 0);
	
	cout << endl;
	
	RellenaListaAleatoriamente(l,longitud,0,20);

	PintaLista(l);
	
	cout << endl;
	cout << "Ordenando... " << endl;
	OrdenaLista(l);
	PintaLista(l);
	cout << endl;

	TipoBase valor;

	do{
		cout << "Valor que desea introducir en la lista: ";
		cin >> valor;
		cout << endl;
	}while(valor < 0);
	
	InsertaOrdenadamente(l,valor);

	PintaLista(l);

	do{
		cout << "Valor que desea borrar de la lista: ";
		cin >> valor;
		cout << endl;
	}while(valor < 0);

	//si sólo hay un nodo, borro la lista "entera"

	EliminaValor(l,valor);
	
	PintaLista(l);
	LiberaLista(l);
	
	return(0);
}