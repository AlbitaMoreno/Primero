/*Se quiere leer un carácter letra_original desde teclado, y comprobar con una
estructura condicional si es una letra mayúscula. En dicho caso, hay que calcular
la minúscula correspondiente en una variable llamada letra_convertida.En cualquier otro caso, le asignaremos a letra_convertida el valor que
tenga letra_original. Finalmente, imprimiremos en pantalla el valor de
letra_convertida*/

#include <iostream>

using namespace std;

int main(){
	char letra_convertida, letra_original;
	bool es_mayus;									//Variable lógica para mayúsculas y minusculas para el condicional IF
	const int distancia_may_min = 32;
	
	cout << "\nIntroduzca letra: ";
	cin >> letra_original;
		
	if((letra_original >= 'A') && (letra_original <= 'Z')){
		es_mayus = true;
	}
	
	if(es_mayus){
		letra_convertida = letra_original + distancia_may_min;
		
		cout << "\nLa letra es: " << letra_convertida;
	}
	else{
		cout << "\n\tLa letra no es mayuscula";
	}
}

//Dado que cada letra tiene su equivalente en codigo ASCII, miro la "distancia" entre las mayusculas y 
//las minusculas, asi, una "A" tiene su equivalente en ASCII 65 y una "a" tiene su equivalente 97 es decir, 32 unidades.
//De este modo cuando guardo la "A" en un entero, realmente estoy guardando el valor 65.
