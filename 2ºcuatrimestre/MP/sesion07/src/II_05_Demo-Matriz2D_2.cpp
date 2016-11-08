//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
//II_05_Demo-Matriz2D_2.cpp
//
/***************************************************************************/


#include <iostream>
#include <cstdlib>
#include "Random.h"
#include "Matriz2D_2.h"
using namespace std;

int main(){

	/***************************************************************************/
	/***************************************************************************/
	//Declaración de variables

	Matriz2D_2 matriz1;
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

	cout << "Introduzca el numero de columnas: ";
	cin >> datos;

	if(datos <= 0){
		cerr << "COLUMNAS MAL INCIALIZADAS";
		exit(2);
	}
	matriz1.cols = datos;

	if(matriz1.fils != matriz1.cols){
		cerr << "No se puede crear una matriz rectangular.";
		exit(3);
	}

	
	CreaMatrizAleatoria(matriz1);
	Pinta(matriz1);
	cout << endl;

	/***************************************************************************/
	/***************************************************************************/
	//creo la matriz 2 para hacer el apartado f
	Matriz2D_2 matriz2;
	cout << "Copiando..." << endl;

	matriz2 = CopiaMatriz(matriz2,matriz1);
	Pinta(matriz2);
	cout << endl;

	LiberaMem(matriz2);

	/***************************************************************************/
	/***************************************************************************/
	//Creo una submatriz, que inicializaré y rellenaré en la función CreaSubmatriz
	Matriz2D_2 submatriz;

	cout << "Vamos a hacer una submatriz, para ello introduce: " << endl;
	cout << "1- La fila desde donde quieres empezar --> ";
	cin >> datos;

	if(datos < 0){
		cout << "Tiene que ser un numero mayor que 0" << endl;
		exit(4);
	}
	int incfil = datos;

	cout << "2- La columna desde donde quieres empezar --> ";
	cin >> datos;

	if(datos < 0){
		cout << "Tiene que ser un numero mayor que 0" << endl;
		exit(4);
	}
	int inccol = datos;

	cout << "3- La fila donde quieres acabar--> ";
	cin >> datos;

	if(datos < 0 || datos > matriz1.fils-1){
		cout << "Tiene que ser un numero mayor que 0 y no mas grande que "<< matriz1.fils-1 << endl;
		exit(5);
	}

	int finfil = datos;

	cout << "4- La columna donde quieres acabar--> ";
	cin >> datos;

	if(datos < 0 || datos > matriz1.cols-1){
		cout << "Tiene que ser un numero mayor que 0 y no mas grande que "<< matriz1.cols-1 << endl;
		exit(5);
	}
	int fincol = datos;

	cout << "Creando submatriz..." << endl;
	submatriz = CreaSubmatriz(matriz1,submatriz,incfil,inccol,finfil,fincol);
	Pinta(submatriz);
	cout << endl;
	/***************************************************************************/
	/***************************************************************************/
	cout << "Fila que deseas eliminar -> ";
	cin >> datos;

	if(datos < 0 || datos > matriz2.fils){
		cout << "Tiene que ser un numero mayor que 0 y no mas grande que "<< matriz1.fils << endl;
		exit(5);
	}

	cout << "Eliminando..." << endl;
	matriz2 = EliminaFila(matriz1,matriz2,datos);
	Pinta(matriz2);
	cout << endl;
	LiberaMem(matriz2);

	/***************************************************************************/
	/***************************************************************************/
	cout << "Columna que deseas eliminar -> ";
	cin >> datos;

	if(datos < 0 || datos > matriz2.cols){
		cout << "Tiene que ser un numero mayor que 0 y no mas grande que "<< matriz1.cols << endl;
		exit(5);
	}
	
	cout << "Eliminando..." << endl;

	matriz2 = EliminaColumna(matriz1,matriz2,datos);
	Pinta(matriz2);
	cout << endl;
	LiberaMem(matriz2);

	/***************************************************************************/
	/***************************************************************************/
	Matriz2D_2 traspuesta;
	cout << "Creando traspuesta" << endl;
	cout << "Matriz1 traspuesta" << endl;
	traspuesta = MatrizTraspuesta(matriz1,traspuesta);
	Pinta(traspuesta);
	cout << endl;
	/***************************************************************************/
	/***************************************************************************/
	
	cout << "Invertir filas en la matriz1" << endl;
	matriz2 = InvertirFilas(matriz1,matriz2);
	Pinta(matriz2);
	cout << endl;

	/***************************************************************************/
	/***************************************************************************/
	//Libero la memoria que ocupan las matrices dinamicas

	LiberaMem(matriz1);
	LiberaMem(matriz2);
	LiberaMem(submatriz);
	LiberaMem(traspuesta);

	return(0);
}