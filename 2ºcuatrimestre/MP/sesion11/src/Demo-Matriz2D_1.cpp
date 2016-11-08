//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
//Demo-Matriz2D_1.cpp 
// 
/***************************************************************************/

#include <iostream>
#include "Matriz2D_1.h"

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
	Matriz2D_1 m2(fils,cols);
	
	for(int i = 0; i < fils; i++){
		for (int j = 0;  j < cols; j++){
			cerr << "Introduce un valor m[" << i << "][" << j << "] -> ";
			cin >> valor;
			m1 (i,j) = valor;
			cout << endl;
		}

	}

	for(int i = 0; i < fils; i++){
		for (int j = 0;  j < cols; j++){
			cerr << " " << m1 (i,j);
		}
		cout << endl;
	}	
	
	cout << "Toda la matriz con 5" << endl;
	m2 = 5;
	
	for(int i = 0; i < fils; i++){
		for (int j = 0;  j < cols; j++){
			cerr << " " << m2 (i,j);
		}

		cout << endl;
	}	
	
	Matriz2D_1 res, res2, ;
	
	res = m1 + m2;
	
	cout << "res = m1 +m2-> ";
	for(int i = 0; i < fils; i++){
		for (int j = 0;  j < cols; j++){
			cerr << " " << resultado (i,j);
		}

		cout << endl;
	}
	
	cout << "res2 = m1 + 2"-> ";
	res2 = m1+2;
	
	for(int i = 0; i < fils; i++){
		for (int j = 0;  j < cols; j++){
			cerr << " " << resultado (i,j);
		}

		cout << endl;
	}
	return(0);
}
