//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
//Matriz2D_1_Asignacion-Acceso.cpp 
// 
/***************************************************************************/

#include <iostream>
#include "Matriz2D_1.h"

using namespace std;

/********************************************************************************************/
/*******************************************************************************************/
//
//	Constructores y destructor
//	
/********************************************************************************************/
/*******************************************************************************************/

Matriz2D_1 :: Matriz2D_1(){	//constructor ain argumentos
	
	filas = 0;
	columnas= 0;
}

/********************************************************************************************/
/*******************************************************************************************/

Matriz2D_1 :: Matriz2D_1(int fils, int cols){	//constructor con  dos argumentos
	filas = filas;
	columnas = cols;

	ReservaMem(filas, columnas);
}

/********************************************************************************************/
/*******************************************************************************************/

Matriz2D_1 :: Matriz2D_1(const Matriz2D_1 & otro){
	ReservaMem(otro.filas, otro.columnas);
	CopiaDatos(otro);
}

/********************************************************************************************/
/*******************************************************************************************/

Matriz2D_1 :: ~Matriz2D_1(){	//destructor
	LiberaMem();
}

/********************************************************************************************/
/*******************************************************************************************/
//
//	MÉTODOS PÚBLICOS
//	
/********************************************************************************************/
/*******************************************************************************************/

bool Matriz2D_1 :: MatrizVacia()const{

	return(!datos);
}

/********************************************************************************************/
/*******************************************************************************************/

void Matriz2D_1 :: MismoValor(TipoBase valor){	//si no se le pasa un parámetro tiene un valor por defecto, el 0
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

void Matriz2D_1 :: ReservaMem(int filas, int columnas){
	//Primero reservo el vector que apuntará a las filas

	datos = new TipoBase *[filas];

	//reservo la memoria para cada fila

	for(int i = 0; i < filas;i++)
		datos[i] = new TipoBase [columnas];
}

/********************************************************************************************/
/*******************************************************************************************/

void Matriz2D_1 :: LiberaMem(){
	
	//Libero la memoria que ocupan las filas
	if(datos){
		for (int i = 0; i < filas; i++)
			delete [] datos[i];

		//Libero la memoria ocupada por el vector datos;

		delete [] datos;
	}
}

/********************************************************************************************/
/*******************************************************************************************/

void Matriz2D_1 :: CopiaDatos(const Matriz2D_1 &otro){
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

Matriz2D_1 & Matriz2D_1 :: operator = (const Matriz2D_1 & otro){
	if(this != &otro){

		LiberaMem();

		ReservaMem(otro.filas, otro.columnas);

		CopiaDatos(otro);
	}

	return(*this);
}

Matriz2D_1 & Matriz2D_1 :: operator = (const TipoBase valor){
	
	LiberaMem();
	ReservaMem(filas,columnas);
	MismoValor(valor);
		
	return(*this);
}

TipoBase & Matriz2D_1 :: operator () (const int f , const int c){
	return(datos[f][c]);
}



/********************************************************************************************/
/*******************************************************************************************/
//sobrecarga de operadores unarios, + y -
Matriz2D_1 Matriz2D_1 :: operator +(){
	return(*this);
}

/********************************************************************************************/
/*******************************************************************************************/

Matriz2D_1 Matriz2D_1 :: operator -(){
	Matriz2D_1 tmp(filas,columnas);		//uso el constructor de copia con dos argumentos, para crear la matriz que voy a devolver

	for(int i = 0; i < filas; i++){
		for(int j = 0; j < columnas; j++){
			tmp.datos[i][j] = -(this->datos[i][j]);
		}
	}
	return(tmp);
}

/********************************************************************************************/
/*******************************************************************************************/
//SOBRECARGA CON FUNCIONES AMIGAS OPERADOR +

Matriz2D_1 operator +(const Matriz2D_1 &m1, const Matriz2D_1 &m2){
	bool filas_iguales = (m1.filas == m2.filas ? true : false);
	bool columnas_iguales = (m1.columnas == m2.columnas ? true : false);

	Matriz2D_1 tmp(m1.filas,m1.columnas);

	if(filas_iguales && columnas_iguales){		
		for(int i = 0; i < m1.filas; i++){
			for(int j = 0; j < m1.columnas; j++){
				tmp.datos[i][j] = m1.datos[i][j] + m2.datos[i][j];
			}
		}		
	}
	else
		tmp.MismoValor();
		
	return(tmp);
}

/********************************************************************************************/
/*******************************************************************************************/

Matriz2D_1 operator +(TipoBase valor, const Matriz2D_1 m){
	Matriz2D_1 m2(m.filas, m.columnas);	//creo una matriz con las misma fils y cols que m

	m2 = valor;		//hago la matriz de valor

	return(m + m2);
}

/********************************************************************************************/
/*******************************************************************************************/

Matriz2D_1 operator +(const Matriz2D_1 m, TipoBase valor){
	return(valor + m);
}

/********************************************************************************************/
/*******************************************************************************************/

Matriz2D_1 & Matriz2D_1 :: operator += (TipoBase valor){
	*this = *this + valor;
	return(*this);		//uso la funcion amiga que recive como argumento un entero y una matriz
}

/********************************************************************************************/
/*******************************************************************************************/

Matriz2D_1 & Matriz2D_1 :: operator -= (TipoBase valor){
	*this = *this + (-valor);
	return(*this);		//sigo usando la funcion amiga que suma junto con el operador unario -
}

/********************************************************************************************/
/*******************************************************************************************/

Matriz2D_1 & Matriz2D_1 :: operator *= (TipoBase valor){
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < columnas; j++){
			datos[i][j] = datos[i][j] * valor;
		}
	}

	return(*this);
}

/********************************************************************************************/
/*******************************************************************************************/

Matriz2D_1 & Matriz2D_1 :: operator /= (TipoBase valor){
	*this *= (1/valor);
	return(*this);		//dividir entre 3 es el mismo que multiplicar por 1/3
}

/********************************************************************************************/
/*******************************************************************************************/

bool Matriz2D_1 :: operator == (const Matriz2D_1 &matriz){
	bool iguales = ((filas == matriz.filas && columnas == matriz.columnas) ? true : false);

	if(iguales){
		for(int i = 0; i < filas && iguales; i++){
			for(int j = 0; j < columnas && iguales; j++){
				if(datos[i][j] != matriz.datos[i][j])
					iguales = false;
			}
		}		
	}

	return(iguales);
}

bool Matriz2D_1 :: operator != (const Matriz2D_1 &matriz){
	return(!(*this == matriz));			//uso el operador ==
}
