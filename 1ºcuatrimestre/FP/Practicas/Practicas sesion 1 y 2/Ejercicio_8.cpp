/* Se pide un programa para separar por cifras un número de 3 cifras cualesquiera, para ello vamos a utilizar "%"
hallando el resto del número y usandolo así para separa el número por espacios
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {
	int centenas, decenas, unidades, numero; 		//Los número deben ser enteros para que podamos usar "%".
	
	cout << "\nIntroduzca el numero de 3 cifras: ";
	cin >> numero;
	
	centenas = numero  %1000/100;  	 	//Estos serían los digitos.
	decenas = numero %100/10;			
	unidades = numero %10;		 		
	
	cout << "\nEl numero seria: " << centenas <<" "<< decenas <<" "<< unidades; 

	return 0;
}
