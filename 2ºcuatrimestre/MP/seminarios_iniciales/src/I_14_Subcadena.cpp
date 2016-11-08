//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
// Fichero: I_14_Subcadena.cpp
// Cálculo de la longitud de una cadena clásica
/***************************************************************************/

#include "I_14_Subcadena.h"
using namespace std;

//recibe la direccion de la primera posición del vector cadena, entero p que será el índice de que partimos
//y l, que es la longitud de la cadena.
void Subcadena(char *cadena, int p, int l){
	//creo un puntero que empezará apuntando la primera casilla que nos interesa y se moverá hasta el ptr constante
	//tope, que estará en la última posición que queremos, según la longitud, o hasta que encuentre el '\0'
	char *ptr = &cadena[p];
	char const *tope = &cadena[(l+p)];

	//mientras ptr no se cruce con tope ó *ptr sea distinto de '\0' , recorremos la subcadena mostrando 
	//los valores a los que va apuntando ptr
	while(ptr != tope || *ptr != '\0'){
		cout << *ptr;
		ptr++;
	}
	cout << endl;
}