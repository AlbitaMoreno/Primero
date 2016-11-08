//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
//Demo-Matriz2D_1_ConstructorCopia.cpp 
// 
/***************************************************************************/

#include <iostream>
#include "Matriz2D_1_ConstructorCopia.h"

using namespace std;

int main(){
	
	int fils, cols;
	TipoBase valor;

	/********************************************************************************************/
	/*******************************************************************************************/
	//Constructor con 3 argumentos

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

	cout << "Con que valor quieres rellenar toda la matriz, con un valor: ";
	cin >> valor;

	Matriz2D_1 m1(fils,cols,valor);
	m1.Pinta();

	cout << "Reescribir valores de la matriz con distintos valores: " << endl;

	for(int i = 0; i < fils; i++){
		for (int j = 0;  j < cols; j++){
			cout << "Introduce un valor m[" << i << "][" << j << "] -> ";
			cin >> valor;
			m1.ModificarValor(i, j, valor);
		}
	}

	m1.Pinta();
	cout << "Poner a 0, con una función que si no recive argumentos tiene un valor por defecto." << endl;

	m1.Inicializa();
	m1.Pinta();

	return(0);
}