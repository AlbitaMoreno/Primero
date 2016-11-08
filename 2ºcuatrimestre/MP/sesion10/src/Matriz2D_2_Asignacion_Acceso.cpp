//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
//Matriz2D_2_Asignacion-Acceso.cpp 
// 
/***************************************************************************/

#include <iostream>
#include "Matriz2D_2_Asignacion_Acceso.h"

using namespace std;

/********************************************************************************************/
/*******************************************************************************************/
//
//	Constructores y destructor
//	
/********************************************************************************************/
/*******************************************************************************************/

Matriz2D_2 :: Matriz2D_2(){	//constructor ain argumentos
	
	filas = 0;
	columnas= 0;
}

/********************************************************************************************/
/*******************************************************************************************/

Matriz2D_2 :: Matriz2D_2(int cuadrada){		//constructor que crea una matriz rectangular
	filas = columnas = cuadrada;
	ReservaMem(filas,columnas);
}

/********************************************************************************************/
/*******************************************************************************************/

Matriz2D_2 :: Matriz2D_2(int fils, int cols){	//constructor con  dos argumentos
	filas = filas;
	columnas = cols;

	ReservaMem(filas, columnas);
}

/********************************************************************************************/
/*******************************************************************************************/

Matriz2D_2 :: Matriz2D_2(const Matriz2D_2 & otro){
	ReservaMem(otro.filas, otro.columnas);
	CopiaDatos(otro);
}

/********************************************************************************************/
/*******************************************************************************************/

Matriz2D_2 :: ~Matriz2D_2(){	//destructor
	LiberaMem();
}

/********************************************************************************************/
/*******************************************************************************************/
//
//	MÉTODOS PÚBLICOS
//	
/********************************************************************************************/
/*******************************************************************************************/

bool Matriz2D_2 :: MatrizVacia()const{

	return(!datos);
}

/********************************************************************************************/
/*******************************************************************************************/

void Matriz2D_2 :: MismoValor(TipoBase valor){	//si no se le pasa un parámetro tiene un valor por defecto, el 0
	for(int i = 0; i < filas;i++){
		for(int j = 0; j < columnas; j++){
			datos[i][j] = valor;
		}
	}
}

/********************************************************************************************/
/*******************************************************************************************/
//
//	MÉTODOS PRIVADOS
//	
/********************************************************************************************/
/*******************************************************************************************/

void Matriz2D_2 :: ReservaMem(int filas, int columnas){
	//Primero reservo el vector que apuntará a las filas

	datos = new int *[filas];

	datos[0] = new int [filas*columnas];
	//reservo la memoria para cada fila

	for(int i = 1; i < filas;i++)
		datos[i] = datos[i-1] + columnas;
}

/********************************************************************************************/
/*******************************************************************************************/

void Matriz2D_2 :: LiberaMem(){
	//Libero la memoria que ocupan las filas
	if(datos){
		//Libero la memoria que ocupan las filas, como estan consecutivas, no tengo que
		//hacer un ciclo for

		delete [] datos[0];
		//Libero la memoria ocupada por el vector datos;

		delete [] datos;
	}
}

/********************************************************************************************/
/*******************************************************************************************/

void Matriz2D_2 :: CopiaDatos(const Matriz2D_2 &otro){
	filas = otro.filas;
	columnas = otro.columnas;

	for(int i = 0; i < filas; i++){
		for(int j = 0; j < columnas; j++)
			datos[i][j] = otro.datos[i][j];
	}
}


/********************************************************************************************/
/*******************************************************************************************/
//
//	SOBRECARGA DE OPERADORES
//	
/********************************************************************************************/
/*******************************************************************************************/

Matriz2D_2 & Matriz2D_2 :: operator = (const Matriz2D_2 & otro){
	if(this != &otro){

		LiberaMem();

		ReservaMem(otro.filas, otro.columnas);

		CopiaDatos(otro);
	}

	return(*this);
}

Matriz2D_2 & Matriz2D_2 :: operator = (const TipoBase valor){
	
	LiberaMem();
	ReservaMem(filas,columnas);
	MismoValor(valor);
		
	return(*this);
}

TipoBase & Matriz2D_2 :: operator () (const int f , const int c){
	return(datos[f][c]);
}