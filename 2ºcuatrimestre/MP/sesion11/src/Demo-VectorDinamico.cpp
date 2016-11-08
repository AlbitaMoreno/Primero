//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
// Demo-VectorDinamico.cpp
//
/***************************************************************************/


#include <iostream>
#include "VectorDinamico.h"

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

	MiVectorDinamico v2;	//constructor sin argumentos

	cout << endl;

	cout << "Vamos a rellenar v2 " << endl;
	cout << "Para terminar -1" << endl;
	
	cout << "Introduce un valor para acabar -1 " << endl;
	cin >> v;

	int i = 0;

	while(i < v2.GetTamanio() && v != -1){
		v2[i] = v;
		i++;

		cout << "Introduce un valor para acabar -1 " << endl;
		cin >> v;

		if (i <= v2.GetTamanio()){
			v2 = v2.Redimensiona();
		}
	}
	
	if(v1 == v2)
		cout << "Los vectores son iguales" << endl;
	if(v1 != v2)
		cout << "Los vectores NO son iguales" << endl;

	if(v1 > v2)
		cout << "v1 > v2" << endl;
	else
		if(v1 < v2)
			cout << "v1 < v2" << endl;
		
	if(v1 >= v2)
		cout << "v1 >= v2" << endl;
	if(v1 <= v2)
		cout << "v1 <= v2" << endl;
		
	cout << endl;
	return(0);
}