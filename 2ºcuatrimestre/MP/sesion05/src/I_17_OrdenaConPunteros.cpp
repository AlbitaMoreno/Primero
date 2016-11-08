//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
// Fichero: I_17_Ordena_Con_Punteros.cpp
//
//si no lse le pasan argumentos al main, ordena el indice entero
//si se le pasan derecha e izquierda ordena el subvector que queda comprendido
//entre ambos indices
/***************************************************************************/

#include <iostream>
//la uso para crear barrera, cadena de char que separa las soluciones
#include <cstring>
//para poder usar exit
#include <cstdlib>

#include "Random.h"
#include "Ordena.h"

using namespace std;

int main(int argc, char const *argv[])
{
	MyRandom generador(0,50);
	const int TOPE = 50;
	//vector de datos
	int vector[TOPE];
	//indice de "vector"
	int *ptr[TOPE];
	
	//inicializo p apuntando a la primera posicion del vector
	int *p = &vector[0];

	char barrera[50];
	memset(barrera, '*',49);
	memset (&(barrera[49]),'\0',1);
	
	cout <<"El vector es: " <<  endl;
	//incializo el vector
	for (int i = 0; i < TOPE; i++){
		vector[i] = generador.Next();
		cout << " " << vector[i];
	}
	cout << endl;
	//le asigno a cada puntero de *ptr[] una casilla de vector independientemente de si esta ordenada.
	for(int i = 0; i < TOPE; i++, p++){
		ptr[i] = &vector[i];
	}
    
    cout << barrera << endl;  		
    
	if(argc <= 3){
		if(argc == 1){
			cout << barrera << endl;
			cout << "No ha introducido argumentos" << endl;
			//tengo que ordenar todo el vector
			cout << "Ordenando indices..." << endl;

			Ordena(p,ptr,0,(TOPE-1));
			cout << endl;
			//muestro el indice ordenado
			for(int i = 0; i < TOPE; i++){
				cout << " " << *ptr[i];
			}
			cout << endl;
		}

		if(argc == 2){
			cout << barrera << endl;
			cout << "ERROR: argumentos invalidos" << endl;
			cout << barrera << endl;
			exit(EXIT_FAILURE);
		}
		if(argc == 3){
			cout << barrera << endl;
			cout << "Numero de argumentos adecuado: " << endl;
			//transformo los parametros argv[1] y argv[2] que son tipo char a tipo int
			int der = atoi(argv[2]);
			int izq = atoi(argv[1]);
			int utils = der - izq + 1;
			cout << "Ordenando indices..." << endl;

			Ordena(p,ptr,izq,der);
			for(int i = 0; i < utils; i++,izq++){
				cout << " " << *ptr[izq];
			}
			cout << endl;
		}
	}
	else{
		cout << barrera << endl;
		cout << "ERROR: argumentos invalidos" << endl;
		cout << barrera << endl;
		exit(EXIT_FAILURE);
	}

	cout << barrera << endl;
	cout << "El vector sigue desordenado..." << endl;
	cout << barrera <<  endl;
	//incializo el vector
	for (int i = 0; i < TOPE; i++)
		cout << " " << vector[i];
	
	cout << endl;
	return 0;
}