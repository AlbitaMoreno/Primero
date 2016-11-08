//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
// Demo-VectorDinamico_Asignacion-Acceso.cpp
//
/***************************************************************************/


#include <iostream>
#include "VectorDinamico_Asignacion_Acceso.h"

using namespace std;

int main(){
	
	TipoBase v;				//para introducir valores
	int casillas;
	
	do{
		cout << "Introduce el numero de casillas que va a tener v1: ";
		cin >> casillas;
	}while(casillas < 0);

	MiVectorDinamico v1(casillas);	//constructor con un argumento

	cout << endl;
	cout << "Vamos a rellenar v1 " << endl;

	
	for(int i = 0; i < v1.GetTamanio(); i++){
		cout << "Introduce un valor para la posicion " << i << endl;
		cin >> v;

		v1[i] = v;
	}
	
	cout << "Casillas usadas -> " << v1.GetUsados() << " .Ver los elementos del vector" << endl;

	for(int i = 0; i < v1.GetTamanio(); i++)
		cout << " " << v1[i];

	cout << endl;

	cout << "Todo el vector al mismo valor : ";
	cin >> v;

	v1 = v;

	for(int i = 0; i < v1.GetTamanio(); i++)
		cout << " " << v1[i];

	cout << endl;
	return(0);
}