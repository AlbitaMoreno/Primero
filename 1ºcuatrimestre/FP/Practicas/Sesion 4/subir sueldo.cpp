/*Programa que lea el valor de la edad (dato de tipo entero) y salario (dato de
tipo real) de una persona. Subid el salario un 5% si éste es menor de 300 euros y la
persona es mayor de 65 años. Imprime el resultado por pantalla. En caso contrario
imprimie el mensaje "No es aplicable la subida". En ambos casos imprimie
el salario resultante.*/

#include <iostream>

using namespace std;

int main(){
	int edad;
	double salario;
	double total1;
	
	cout << "\nIntroduzca la edad: ";
	cin >> edad;
	cout << "\nIntroduzca el salario: ";
	cin >> salario;
	
	if(edad > 65 and salario < 300){
		total1 = 0.05*salario + salario;
		
		cout << "\n\tEl salario total es: " << total1 << "\n\n";
		
	}
	
	else{
		cout << "\n\tNo es aplicable la subida";
	}
	
}
