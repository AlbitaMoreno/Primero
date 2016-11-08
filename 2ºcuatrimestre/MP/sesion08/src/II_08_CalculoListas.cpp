//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
//II_08_CalculosListas.cpp
//
/***************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include "ListasBasicos.h"
#include "Random.h"

using namespace std;
/***************************************************************************/
/***************************************************************************/

double Media (const Lista );
double Varianza (const Lista );

/***************************************************************************/
/***************************************************************************/

int main(){
	Lista l;
	int longitud;

	cout << "Longitud de la lista aleatoria: ";
	cin >> longitud;

	RellenaListaAleatoriamente(l,longitud,0,20);	//creo una lista con 5 elemneto del 0 al 9
	
	PintaLista(l);

	cout << "La media es -> " << Media(l) << endl;
	cout << "La varianza es -> " << Varianza(l) << endl;
	
	LiberaLista(l);

	return(0);
}