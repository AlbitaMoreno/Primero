//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
//II_01_RedimensionarArrayDinamico.cpp
//
/***************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include "RedimensionarArrayDinamico.h"

using namespace std;


int main(int argc, char const *argv[])
{
	/**************************************************************************/
	/**************************************************************************/

	char barrera[50];
	
	/**************************************************************************/
	/**************************************************************************/
	
	memset(barrera, '*',49);
	memset (&(barrera[49]),'\0',1);
	
	if(argc > 2){
		cout << barrera << endl;
		cout << "ERROR EN EL NUMERO DE ARGUMENTOS" << endl;
		cout << barrera << endl;
		exit(1);
	}

	/**************************************************************************/
	/**************************************************************************/

	int capacidad = TAM;
	int usados = 0;
	//dato es tipo char para poder compararlo con el terminador
	int dato;
	
	int *v = new int [TAM];
	TipoRedimension tipo;
	/**************************************************************************/
	/**************************************************************************/

	//Compuebo el tipo de redimension que voy a usar
	//en el caso de no introducir argumentos, la redimensión se hace de uno en uno
	if(argc == 1){
		tipo = DeUnoEnUno;
	}
	
	/**************************************************************************/
	/**************************************************************************/

	//en el caso de meter un argumento la redimension se hará:
	//de uno en uno , en bloques, duplicando
	if(argc == 2){
		
		if(atoi(argv[1]) > 3){
		
			cout << barrera << endl;
			cout << "ERROR ARGUMENTO INVALIDO" << endl;
			cout << barrera << endl;
			exit(2);
		}
	
		if(atoi(argv[1]) < 1){

			cout << barrera << endl;
			cout << "ERROR ARGUMENTO INVALIDO" << endl;
			cout << barrera << endl;
			exit(3);
		}

		if(atoi(argv[1]) == 1)
			tipo = DeUnoEnUno;
		
		if(atoi(argv[1]) == 2)
			tipo = EnBloques;

		if(atoi(argv[1]) == 3)
			tipo = Duplicando;
	}

	/**************************************************************************/
	/**************************************************************************/
	
	while(dato != -1){
		
		cout << "Introduzca un dato: ";
		cin >> dato;

		if(usados == capacidad){
			v = Redimensiona(v,tipo,capacidad);
		}

		if(dato != -1){
			v[usados] = dato;
			usados++;
		}
	}

	/**************************************************************************/
	/**************************************************************************/
	
	cout << barrera << endl;

	for(int i = 0; i < usados; i++){
		cout << " " << v[i];
	}
	cout << endl;
	cout << barrera << endl;
	cout << "La capacidad del vector redimensionado es: " << capacidad << endl;
	
	cout << endl;
	delete [] v;
	return 0;
}
