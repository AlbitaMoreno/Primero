//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
//Matriz2D_1.cpp
//
/***************************************************************************/

#include <iostream>
#include "Random.h"
#include "Matriz2D_1.h"
#include "Matriz2D_2.h"

using namespace std;



/***************************************************************************/
/***************************************************************************/
//Lo unico que es identico en ambos tipos de matrices es el vector de punteros de cada fila, por tanto lo nuevo sera:
//en el caso de convertir del tipo 1 a tipo 2, crear un array cons las filas consecuitivas, luego apuntar los punteros
//del array de las filas.
//de tipo 2 a 1, habria que crear arrays dinamicos por cada fila que haya y copiar el contenido

Matriz2D_2 Matriz2D_1_To_Matriz2D_2 (Matriz2D_1 matriz1, Matriz2D_2 resultado){

	resultado.fils = matriz1.fils;
	resultado.cols = matriz1.cols;
	
	//creo una matriz indefinida del tipo Matriz2D_2
	CreaMatrizIndefinida(resultado);

	//voy a copiar los datos de matriz1 que estan en filas independientes, en resultado, filas consecutivas
	for(int i = 0; i < resultado.fils; i++){
		for(int j = 0; j < resultado.cols; j++){
			resultado.datos[i][j] = matriz1.datos[i][j];
		}
	}
	return(resultado);
}

Matriz2D_1 Matriz2D_2_To_Matriz2D_1 (Matriz2D_2 matriz2, Matriz2D_1 resultado){

	resultado.fils = matriz2.fils;
	resultado.cols = matriz2.cols;

	//creo una matriz indefinida del tipo Matriz2D_2
	CreaMatrizIndefinida(resultado);

	//voy a copiar los datos de matriz1 que estan en filas consecutivas, en resultado, filas independientes
	for(int i = 0; i < resultado.fils; i++){
		for(int j = 0; j < resultado.cols; j++){
			resultado.datos[i][j] = matriz2.datos[i][j];
		}
	}
	return(resultado);
}
