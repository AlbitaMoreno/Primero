//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
// Fichero: I_08_SaltaPrimeraPalabra.cpp
// Me salto la primera palabra de una cadena y muestro el resto
/***************************************************************************/

#include <iostream> 

using namespace std;

int LongitudCadena(char *p){
	//creamos un puntero *p que apunta a la primera posición de v
	//char *p = &v;
	//incializamos longitud a 0
	int longitud = 0; 
	//bucle que irá desde la primera hasta que encuentre el '\0' de forma que incrementará
	//la longitud con cada vuelta
	while(*p != '\0'){
		longitud++;
		//apuntamos a l siguiente posición
		p++;
	}

	//devolvemos la longitud

	return(longitud);
}
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
			p = &cadena[LongitudCadena(cadena)];
			cout << endl;
		}

		//si *p no es un espacio en blanco, apunto a la siguiente casilla
		p++;
	}
}