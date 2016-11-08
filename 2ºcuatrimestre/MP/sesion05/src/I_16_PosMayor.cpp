//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
// Fichero: I_16_PosMayor.cpp
// 
//devulve el maximo entre las dos
//posiciones indicadas como argumentos, si no se introduce argumentos 
//entonces calcula el maximo de todo el vector
/***************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Random.h"
#include "PosMayor.h"

using namespace std;


int main(int argc, char *argv[]){
	
	const int TOPE = 100;
	//para generar un vector aleatorio
	MyRandom generador(0,50);

	//barrera será una cadena clásica que usaré para separar los distintos casos
	//y que los cout se vean mejor ordenados
	char barrera[50];
	memset(barrera, '*',49);
	memset (&(barrera[49]),'\0',1);


	if(argc <= 4){
		//se ejecuta el programa sin pasarle ningun argumento
		if(argc == 1){
			cout << barrera << endl;
			cout << "No ha introducido ningún elemento" << endl;
			cout << barrera << endl;
			//como no he introducido ningun parametro al ejecutar el programa
			//tengo que hacer el vector[TOPE] y calcular su maximo

			int vector[TOPE];
			// Iniciar el vector aleatoriamente
			
			for (int i = 0; i < TOPE; i++){
				vector[i] = generador.Next();
				cout << " " << vector[i];
			} 
      		
      		cout << endl;
      		int *ptr = &vector[0];

      		ptr = PosMayor(ptr, 0, (TOPE-1));
      		cout << "El maximo es: " << *ptr << endl;
		}

		//se ejecuta el programa con un argumento
		if(argc == 2){
			cout << barrera << endl;
			cout << "Ha introducido 1 argumento, el tamaño del vector" << endl;
			cout << barrera << endl;
			//como he pasado un argumento -> el vector de enteros aleatorios
			//tendrá argv[1] posiciones, y calcularemos el maximo entre 0 y n-1

			//creo e incializo el vector, para ello tengo que transformar argv[1] de char a int, usando la equivalencia ASCII
			int tam = atoi(argv[1]);
			int vector[tam];

			for (int i = 0; i < tam; i++){
				vector[i] = generador.Next();
				cout << " " << vector[i];
			} 
      		
      		cout << endl;
      		int *ptr = &vector[0];

      		ptr = PosMayor(ptr, 0, (tam-1));
      		cout << "El maximo es: " << *ptr << endl;
		}

		if(argc == 3){
			cout << barrera << endl;
			cout << "ha introducido 2 argumentos, el tamaño del vector y las posiciones a evaluar" << endl;
			cout << barrera << endl;

			//he pasado dos argc por tanto el vector tendras argv[1] elementos, y se alculara el maximo hasta la posicion del vector
			//argv[2]

			int tam = atoi(argv[1]);
			int vector[tam];
			int tope_der = atoi(argv[2]);

			for (int i = 0; i < tam; i++){
				vector[i] = generador.Next();
				cout << " " << vector[i];
			} 
      		
      		cout << endl;
      		int *ptr = &vector[0];

      		ptr = PosMayor(ptr, 0, tope_der);
      		cout << "El maximo es: " << *ptr << endl;
		}

		if(argc == 4){
			cout << barrera << endl;
			cout << "Ha introducido 3 argumentos, el tamaño del vector, la pos. incial, la posicion final" << endl;
			cout << barrera << endl;

			//argv[0]-> programa
			//argv[1]->tamaño
			//argv[2]->izquierda
			//argv[3]->derecha

			int tam = atoi(argv[1]);
			int vector[tam];
			int incio = atoi(argv[2]);
			int final = atoi(argv[3]);

			for (int i = 0; i < tam; i++){
				vector[i] = generador.Next();
				cout << " " << vector[i];
			} 
      		
      		cout << endl;
      		int *ptr = &vector[0];

      		ptr = PosMayor(ptr, incio, final);
      		cout << "El maximo es: " << *ptr << endl;
		}

	}
	else{
		cout << "ERROR" << endl;
		exit(EXIT_FAILURE);
	}
	return 0;
}

