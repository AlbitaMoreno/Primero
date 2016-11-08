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
	Lista resultado;
	Lista l,l1,l2;
	int longitud;


	LeeLista(l1);
	
	do{
		cout << "Introduzca la longitud: " << endl;
		cin >> longitud;
	}while(longitud < 0);

	RellenaListaAleatoriamente(l2,longitud,0,20);

	cout << endl;
	cout << "Ordenando... " << endl;
	
	OrdenaLista(l1);
	OrdenaLista(l2);
	
	cout << endl;
	PintaLista(l1);
	PintaLista(l2);
	
	cout << "Mezclando de forma ordenada..." << endl;

	MezclaListas(l,l1,l2);

	PintaLista(l);
	
	//solo libero l ya que l1 y l2 están vacías
	LiberaLista(l);
	return(0);
}