//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
// Demo-MiPila.cpp
// 
//
/***************************************************************************/

#include <iostream>
#include "MiPila.h"

using namespace std;

int main(){
	TipoBase valor;	
	MiPila p;

	cout << "Insertar valor en la pila: ";
	cin >> valor;

	while(valor != -1){

		p.AniadeValor(valor);
		cout << "Insertar valor en la pila, para acabar -1: ";
		cin >> valor;
	}
	cout << endl;

	if(!p.PilaVacia()){
		p.LeerTope();
		cout << "Extrayendo -> " << p.Extraer() << endl;
	}

	return 0;	
}