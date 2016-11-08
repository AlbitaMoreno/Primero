//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
// Fichero: I_08_SaltaPrimeraPalabra.cpp
// Cálculo de la longitud de una cadena clásica
/***************************************************************************/

#include <iostream>
#include <string.h>  

using namespace std;

int main(){
	const int TAMANIO = 100;
	char cadena[TAMANIO];
	char *p = &cadena[0];
	
	//pido una frase
	cout << "Introduce una frase: " << endl;
	cin.getline(p,TAMANIO,'\n');
	
	//creo un bucle que recorre la cadena clasica.
	while(*p != '\0'){
		//si *p es un espacio en blanco 
		if(*p == ' '){		
			//aumento p para que al mostrar el valor de cadena lo haga obviando el primer espacio
			p++;
			cout << p;
			//apunta a la ultima posicion de cadena
			p = &cadena[strlen(cadena)];
			cout << endl;
		}

		//si *p no es un espacio en blanco, apunto a la siguiente casilla
		p++;
	}
}