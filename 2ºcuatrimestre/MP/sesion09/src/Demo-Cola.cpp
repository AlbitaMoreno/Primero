// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
// Demo-Cola.cpp
// 
//
/***************************************************************************/

#include <iostream>
#include "Cola.h"

using namespace std;

int main(){
	TipoBase valor;	
	CCola c;

	cout << "Insertar valor en la pila: ";
	cin >> valor;

	while(valor != -1){
		c.AniadeValor(valor);
				
		cout << "Insertar valor en la pila, para acabar -1: ";
		cin >> valor;
	}
	cout << endl;

	if(!c.ColaVacia()){
		c.LeerCabecera();
		cout << "Extrayendo -> " << c.Extraer() << endl;
	}

	return 0;	
}