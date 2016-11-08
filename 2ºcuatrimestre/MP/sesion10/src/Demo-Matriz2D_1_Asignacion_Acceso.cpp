//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
//Demo-Matriz2D_1_Asignacion_Acceso.cpp 
// 
/***************************************************************************/

#include <iostream>
#include "Matriz2D_1_Asignacion_Acceso.h"

using namespace std;

int main(){
	
	int fils, cols;
	TipoBase valor;

	do{
		cout << "Introduce el numero de filas: ";
		cin >> fils;
		cout << endl;

		cout << "Introduce el numero de columnas: ";
		cin >> cols;
		cout << endl;

		if(fils < 0 || cols < 0){
			cout << "Datos invalidos, porfavor vuelva a introducirlos.";
			cout << endl;
		}

	}while(fils < 0 || cols < 0);

	Matriz2D_1 m1(fils, cols);

	for(int i = 0; i < fils; i++){
		for (int j = 0;  j < cols; j++){
			cout << "Introduce un valor m[" << i << "][" << j << "] -> ";
			cin >> valor;
			m1 (i,j) = valor;
			cout << endl;
		}

	}

	for(int i = 0; i < fils; i++){
		for (int j = 0;  j < cols; j++){
			cout << " " << m1 (i,j);
		}
		cout << endl;
	}	
	
	cout << "Toda la matriz con 5" << endl;
	m1 = 5;

	for(int i = 0; i < fils; i++){
		for (int j = 0;  j < cols; j++){
			cout << " " << m1 (i,j);
		}

		cout << endl;
	}	

	return(0);
}