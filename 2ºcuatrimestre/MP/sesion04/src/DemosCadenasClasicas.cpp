//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
// Fichero: DemosCadenasClasicas.cpp
// Contiene el main para probar las funciones implementadas en MiCadenaClasica.cpp
//Sesion 4 Modularizacion de Software
/***************************************************************************/


#include <iostream>
#include "MiCadenaClasica.h"

using namespace std;

int main(){
	const int TAMANIO = 100;
	//creo las cadenas clasicas para probar las funciones
	char cadena1[TAMANIO];
	char cadena2[TAMANIO];

	//creo dos punteros, uno para cada cadena
	char *ptr1 = &cadena1[0];
	char *ptr2 = &cadena2[0];

	//pido que el usuario las rellene
	cout << "Rellene la cadena 1: " << endl;
	cin.getline(ptr1,TAMANIO,'\n');
	cout << "Rellene la cadena 2: " << endl;
	cin.getline(ptr2, TAMANIO,'\n');

	//Vamos a obtener la longitud de cada cadena
	cout << endl;
	cout << "............................................." << endl;
	cout << "La longitud de la 1º cadena: " << LongitudCadena(ptr1) << endl;
	cout << "La longitud de la 2º cadena: " << LongitudCadena(ptr2) << endl;

	//Vamos a comprobar si la caadena 1 es un palindromo
	ptr1 = &cadena1[0];
	bool palindromo = Palindromo(ptr1);
	if(palindromo){
		cout << endl;
		cout << "........................................." << endl;
		cout << "Cadena 1 es un palindromo" << endl;
	}
	else{
		cout << endl;
		cout << "........................................." << endl;
		cout << "Cadena 1 NO es un palindromo" << endl;
	}

	//Vamos a comparar ambas cadenas para ver cual es mayor, independientemente del
	//tamaño, según los valores que tengan.
	cout << endl;
	ptr1 = &cadena1[0];
	int comparador = CompararCadenas(ptr1,ptr2);

	if(comparador < 0){
		cout << endl;
		cout << ".........................................." << endl;
		cout << "La primera cadena es más pequeña que la segunda" << endl;
	}
	if(comparador > 0){
		cout << endl;
		cout << ".........................................." << endl;
		cout << "La primera cadena es más grande que la segunda" << endl;
	}
	if(comparador == 0){
		cout << endl;
		cout << ".........................................." << endl;
		cout << "La primera cadena es igual que la segunda" << endl;
	}
	//..........................................................................//
	//copiar en la cadena aux el contenido de la cadena 1
	char aux[TAMANIO];
	char *copia = &aux[0];
	CopiarCadena(copia,ptr1);
	cout << endl;
	cout << ".................................................." << endl;
	cout << "Copia de la cadena 1: " << copia << endl;

	//..........................................................................//
	//añadir al final de la cadena 2 el contenido de la cadena 1
	EncadenarCadena(ptr2,ptr1);
	cout << endl;
	cout << ".................................................." << endl;
	cout << "Cadena 2 encadenada a cadena 1: " << endl;
	cout << ptr2 << endl;

	//..........................................................................//
	//vamos a crea una subcadena de cadena 1
	cout << endl;
	cout << ".................................................." << endl;
	cout << "Vamos a crear una subcadena de cadena 1" << endl;
	//p es el indice de la primera casilla y l la longitud de la subcadena
	int p,l;
	cout << "Primera posicion de la subcadena: " << endl;
	cin >> p;
	cout << "Longitud de la subcadena: " << endl;
	cin >> l;

	cout << "Subcadena: " << endl;
	Subcadena(ptr1,p,l);
	
	//..........................................................................//
	//invertir cadena 1
	cout << endl;
	cout << ".................................................." << endl;
	cout << "Vamos a crear una cadena invertida de cadena 1" << endl;

	InvierteCadena(ptr1);
	
}