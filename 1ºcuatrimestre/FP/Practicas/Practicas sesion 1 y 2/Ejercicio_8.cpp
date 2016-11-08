/* Se pide un programa para separar por cifras un n�mero de 3 cifras cualesquiera, para ello vamos a utilizar "%"
hallando el resto del n�mero y usandolo as� para separa el n�mero por espacios
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {
	int centenas, decenas, unidades, numero; 		//Los n�mero deben ser enteros para que podamos usar "%".
	
	cout << "\nIntroduzca el numero de 3 cifras: ";
	cin >> numero;
	
	centenas = numero  %1000/100;  	 	//Estos ser�an los digitos.
	decenas = numero %100/10;			
	unidades = numero %10;		 		
	
	cout << "\nEl numero seria: " << centenas <<" "<< decenas <<" "<< unidades; 

	return 0;
}
