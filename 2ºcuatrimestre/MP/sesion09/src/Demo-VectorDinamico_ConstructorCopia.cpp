//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
// Fichero: Demo-VectorDinamico_ConstructorCopia.cpp
// 
//
/***************************************************************************/

#include <iostream>
#include "VectorDinamico_ConstructorCopia.h"

using namespace std;

int main(){
	
	TipoBase v;				//para introducir valores
	TipoRedimension tipo;
	int opcion; 	//para el tipo de redimension
	int casillas;
	
	do{
		cout << "Tipo de redimension que quiere, en caso de necesitarla: " << endl;
		cout << "1.-DeUnoEnUno " << endl;
		cout << "2.-EnBloques, de 5 " << endl;
		cout << "3.-Duplicando " << endl;
		cin >> opcion;	
		
		if(opcion < 1 || opcion > 3)
			cout << "La redimension se indica con valores del 1 al 3" << endl;
	}while(opcion < 1 || opcion > 3);
	
	switch (opcion) { 
			case (1):	tipo = DeUnoEnUno;
						break;
			case (2):	tipo = EnBloques;
						break;
			case (3):	tipo = Duplicando;
						break; 
	}

	
	do{
		cout << "Introduce el numero de casillas que va a tener v1: ";
		cin >> casillas;
	}while(casillas < 0);

	MiVectorDinamico v1(casillas);	//constructor con un argumento
	v1.SetRedimension(tipo);

	cout << endl;
	cout << "Vamos a rellenar v1 " << endl;

	cout << "Introduce un valor,para terminar -1: ";
	cin >> v;

	//ver la redimension en el .cpp de la clase
	while(v != -1){	

		v1.SetValor(v);	
		cout << "Introduce un valor,para terminar -1: ";
		cin >> v;
	}
	
	cout << "Casillas usadas -> " << v1.GetUsados() << " .Ver los elementos del vector" << endl;

	v1.PintaVector();
	return(0);
}