//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
//Matriz2D_2.cpp
//
/***************************************************************************/

#include <iostream>
#include "Random.h"
#include "Matriz2D_2.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/

void CreaMatrizIndefinida(Matriz2D_2 &matriz){
	//Primero reservo el vector que apuntará a las filas

	matriz.datos = new int *[matriz.fils];

	matriz.datos[0] = new int [matriz.fils*matriz.cols];
	//reservo la memoria para cada fila

	for(int i = 1; i < matriz.fils;i++)
		matriz.datos[i] = matriz.datos[i-1]+matriz.cols;
}

/***************************************************************************/
/***************************************************************************/

void LiberaMem(Matriz2D_2 &matriz){
	//Libero la memoria que ocupan las filas, como estan consecutivas, no tengo que
	//hacer un ciclo for

	delete [] matriz.datos[0];
	//Libero la memoria ocupada por el vector datos;

	delete [] matriz.datos;
}

/***************************************************************************/
/***************************************************************************/

void CreaMatrizConValor(Matriz2D_2 &matriz){
	//Primero creo la matriz con valores indefinidos
	CreaMatrizIndefinida(matriz);
	int *ptr = matriz.datos[0];

	//Inicializo la matriz con los valores leyendo de teclado
	int datos;

	//Inicializo la matriz con un solo ciclo y un puntero que recorre todas las filas
	//Como si fuese un vector
	for(int i = 0; i < matriz.fils*matriz.cols; i++,ptr++){
		cout << "Introduzca los datos ";
		cin >> datos;
		*ptr = datos;
		cout << endl;
	}
}

/***************************************************************************/
/***************************************************************************/

void CreaMatrizAleatoria(Matriz2D_2 &matriz){
	//Primero creo la matriz indefinida
	CreaMatrizIndefinida(matriz);

	//Ahora voy a incializarla con valores aleatorios, para ello uso la clase Random
	//voy a usar el rango de valores del 0 al 9

	MyRandom generador(0,9);
	int *ptr = matriz.datos[0];

	for(int i = 0; i < matriz.fils*matriz.cols; i++,ptr++){
		*ptr = generador.Next();
	}
}

/***************************************************************************/
/***************************************************************************/

void Pinta(Matriz2D_2 matriz){
	cout << "La matriz tiene " << matriz.fils << " filas y " << matriz.cols << " columnas" << endl;

	for(int i = 0; i < matriz.fils; i++){
		for(int j = 0; j < matriz.cols; j++){
			cout << " " << matriz.datos[i][j];
		}
		cout << endl;
	}
}

/***************************************************************************/
/***************************************************************************/

Matriz2D_2 CopiaMatriz(Matriz2D_2 destino, Matriz2D_2 origen){
	//Creo, Inicializo y Copio la matriz
	destino.fils = origen.fils;
	destino.cols = origen.cols;
	
	CreaMatrizIndefinida(destino);

	for(int i = 0; i < origen.fils; i++){
		for(int j = 0; j < origen.cols; j++)
			destino.datos[i][j] = origen.datos[i][j];
	}
	return(destino);
}

/***************************************************************************/
/***************************************************************************/

Matriz2D_2 CreaSubmatriz(Matriz2D_2 original, Matriz2D_2 submatriz, int inicio_f, int inicio_c, int final_f, int final_c){
	//si han introducido mal las posiciones las intercambio
	if(inicio_f > final_f)
		Intercambia2(inicio_f,final_f);
	if(inicio_c > final_c)
		Intercambia2(inicio_c,final_c);

	int num_filas = final_f - inicio_f;
	int num_cols = final_c - inicio_c;

	//le doy valores a fils y cols del struct resultado
	submatriz.fils = num_filas;
	submatriz.cols = num_cols;
	//creo la submatriz dinamica
	
	CreaMatrizIndefinida(submatriz);

	int k = 0;
	for (int i = inicio_f; i < final_f;i++,k++){
		int z = 0;
		for(int j = inicio_c; j <= final_c;j++,z++){
			//k y z controlan la matriz nueva, mientras que i j controlan la submatriz que estoy copiando
			submatriz.datos[k][z] = original.datos[i][j];
		}
	}
	return(submatriz);
}

/***************************************************************************/
/***************************************************************************/

void Intercambia2(TipoBase &p1, TipoBase &p2){
	int tmp = p1;
	p1 = p2;
	p2 = p1;
}

/***************************************************************************/
/***************************************************************************/

Matriz2D_2 EliminaFila(Matriz2D_2 origen, Matriz2D_2 resultado, int fila){
	resultado.fils = (origen.fils - 1);
	resultado.cols = origen.cols;

	CreaMatrizIndefinida(resultado);

	int k,z;
	k = z = 0;
	for(int i = 0; i < resultado.fils; i++,k++){
		for(int j = 0; j < resultado.cols; j++,z++){
			// si k, que es el controlador de las filas, coincide con la fila que se desea eliminar
			// me la salto, y copio la fila siguient
			if(k == fila){
				k++;
			}

			resultado.datos[i][j] = origen.datos[k][z];
		}
		z = 0;
	}
	return(resultado);
}

/***************************************************************************/
/***************************************************************************/

Matriz2D_2 EliminaColumna(Matriz2D_2 origen, Matriz2D_2 resultado, int columna){
	
	resultado.fils = origen.fils;
	resultado.cols = origen.cols - 1;

	CreaMatrizIndefinida(resultado);

	int k = 0;

	for(int i = 0; i < resultado.fils; i++,k++){
		int z = 0;
		for(int j = 0; j < resultado.cols; j++,z++){
			// si k, que es el controlador de las filas, coincide con la fila que se desea eliminar
			// me la salto, y copio la fila siguient
			if(z == columna){
				z++;
			}

			resultado.datos[i][j] = origen.datos[k][z];
		}
	}
	return(resultado);
}

/***************************************************************************/
/***************************************************************************/

Matriz2D_2 MatrizTraspuesta(Matriz2D_2 matriz,Matriz2D_2 traspuesta){
	traspuesta.fils = matriz.fils;
	traspuesta.cols = matriz.cols;

	CreaMatrizIndefinida(traspuesta);

	//Matriz traspuesta, cambiar filas por culmnas
	for(int i = 0; i < traspuesta.fils; i++){	
		for(int j = 0; j < traspuesta.cols; j++)
			traspuesta.datos[j][i] = matriz.datos[i][j];		
	}
	return(traspuesta);
}

/***************************************************************************/
/***************************************************************************/

Matriz2D_2 InvertirFilas(Matriz2D_2 origen, Matriz2D_2 resultado){
	resultado.fils = origen.fils;
	resultado.cols = origen.cols;

	CreaMatrizIndefinida(resultado);

	int k = origen.fils-1;

	for(int i = 0; i < resultado.fils; i++, k--){
		int z = 0;
		for(int j = 0; j < resultado.cols; j++, z++){
			resultado.datos[i][j] = origen.datos[k][z];
		}
	}
	return(resultado);
}