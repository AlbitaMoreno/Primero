//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
// Demo-Lista_Asignaccion_Acceso.cpp
// 
//
/***************************************************************************/

#include <iostream>
#include "Lista_Asignacion_Acceso.h"

using namespace std;

int main(){
	int nodos;
	TipoBase valor;	
	
	do{
		cout << "Crear Lista con un numero de nodos determinados: ";
		cin >> nodos;
	}while(nodos <= 0);

	MiLista l2(nodos);


	for(int i = 1; i <= l2.GetNumNodos(); i++)
		cout << " " << l2[i];

	cout << endl;
	cout << "Insertar un 3 en la pos 1-> ";
	l2[1] = 3;

	for(int i = 1; i <= l2.GetNumNodos(); i++)
		cout << " " << l2[i];

	cout << endl;
	cout << "Poner todos los valores a 5.> ";
	l2 = 5;

	for(int i = 1; i <= l2.GetNumNodos(); i++)
		cout << " " << l2[i];

	cout << endl;
	return 0;	
}