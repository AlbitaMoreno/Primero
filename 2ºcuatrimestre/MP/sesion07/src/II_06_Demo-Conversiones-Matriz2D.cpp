//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
//II_06_Demo-Conversiones-Matriz2D.cpp
//
/***************************************************************************/


#include <iostream>
#include <cstdlib>
#include "Random.h"
#include "Matriz2D_1.h"
#include "Matriz2D_2.h"
#include "Convertir_Matriz.h"


using namespace std;

int main(){

	/***************************************************************************/
	/***************************************************************************/
	//Declaración de variables

	Matriz2D_1 matriz1;
	Matriz2D_2 matriz2;

	TipoBase datos;
	
	/***************************************************************************/
	/***************************************************************************/
	//Inicializo, fils, cols y creo la matriz
	cout << "Introduzca el numero de filas : ";
	cin >> datos;
	
	if(datos <= 0){
		cerr << "FILAS MAL INCIALIZADAS";
		exit(1);
	}

	matriz1.fils = datos;
	matriz2.fils = datos;

	cout << "Introduzca el numero de columnas: ";
	cin >> datos;

	if(datos <= 0){
		cerr << "COLUMNAS MAL INCIALIZADAS";
		exit(2);
	}
	matriz1.cols = datos;
	matriz2.cols = datos;

	if(matriz1.fils != matriz1.cols){
		cerr << "No se puede crear una matriz rectangular.";
		exit(3);
	}

	CreaMatrizAleatoria(matriz1);
	CreaMatrizAleatoria(matriz2);
	Pinta(matriz1);
	Pinta(matriz2);
	
	/***************************************************************************/
	/***************************************************************************/

	cerr << "Cambiando matrices..." << endl;

	Matriz2D_1 resultado1;
	Matriz2D_2 resultado2;

	resultado1 = Matriz2D_2_To_Matriz2D_1(matriz2,resultado1);
	resultado2 = Matriz2D_1_To_Matriz2D_2 (matriz1, resultado2);

	Pinta(resultado1);
	Pinta(resultado2);

	return(0);
}