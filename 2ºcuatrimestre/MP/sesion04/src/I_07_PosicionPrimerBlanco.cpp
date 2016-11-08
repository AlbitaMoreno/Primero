//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
// Fichero: I_07_PosicionPrimerBlanco.cpp
// Muestro la posicion del primer espacio en blanco
/***************************************************************************/

#include <iostream>

using namespace std;

//intercambia dos caracteres de posicion de memoria
void Intercambia_Caracteres(char *p1, char *p2){
	char tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

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
	char cadena[100];
	//lo inicializo apuntando a la primera posicion.
	char *p = &cadena[0];	
	
	//pido la cadena
	cout << "Introduzca una cadena de caracteres :" << endl;
	cin.getline(p,TAMANIO,'\n');	

	//'\0' indica el final de la cadena clásica
	while(*p != '\0'){
		//si *p es un espacio en blanco 
		if(*p == ' '){
			//creo un puntero que apunte al final de la cadena
			char *fin = &cadena[((LongitudCadena(cadena))-1)];

			//al restar dos posiciones de memoria, obtengo las posiciones del vector que
			//hay entre el espacio y el final de la cadena
			int tmp = fin - p;

			//para obtener la posición del primer espacio lo qeu hago es restar a la longitud
			//de la cadena las posiciones que hay desde el espacio hasta el final,
			//para tener en cuenta la posicion 0 le resto 1	
			int posicion = (LongitudCadena(cadena)-1) - tmp;	
			cout << "El primer espacio en blanco está cadena[" << posicion << "],";
			cout << " en la direccion: " << static_cast<void *>(p);
			//apunta a la ultima posicion de cadena
			p = &cadena[LongitudCadena(cadena)];
			cout << endl;
		}

		//si *p no es un espacio en blanco, apunto a la siguiente casilla
		p++;
	}
}