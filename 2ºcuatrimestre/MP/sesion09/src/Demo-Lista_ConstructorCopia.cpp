//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
// Demo-Lista_ConstructorCopia.cpp
// 
//
/***************************************************************************/

#include <iostream>
#include "Lista_ConstructorCopia.h"

using namespace std;

int main(){
	int nodos;
	TipoBase valor;	
	
	do{
		cout << "Crear Lista con un numero de nodos determinados: ";
		cin >> nodos;
		cout << "valor que tendrán todos los nodos: ";
		cin >> valor;
	}while(nodos <= 0);

	MiLista l2(nodos,valor);
	l2.PintaLista();

	do{
		cout << "Insertar un valor en: ";
		cin >> nodos;
		cout << "Valor: ";
		cin >> valor;
	}while(nodos <= 0 &&  nodos < l2.GetNodos());

	l2.InsertarValor(valor, nodos);	//repasar insertar un elemento al final de la lista
	l2.PintaLista();

	do{
		cout << "posicion que quiera borrar: ";
		cin >> nodos;
	}while(nodos <= 0 && nodos > l2.GetNodos());

	l2.Borrar(nodos);
	l2.PintaLista();

	return 0;	
}