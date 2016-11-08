/*Calcular mediante un programa en C++ la función potencia xn, y la función factorial
n! con n un valor entero y x un valor real. No pueden usarse las funciones de la
biblioteca cmath.*/
//Potencia

#include <iostream>

using namespace std;

int main()
{
	int total = 1;			//Hace falta inicializarla a 1 para que en el for no meta valores aleatorios.
	int numero;
	int potencia;
	int i = 0;			//para la potencia
	int factorial = 1;
		
	cout << "\nIntroduzca un numero: ";
	cin >> numero;
	cout << "\nIntroduzca un potencia: ";
	cin >> potencia;
	
	for(i = 0; i < potencia ; i++)
	{
		total  = total * numero;		
	}
	
	cout << "\n\tEl numero " << numero << " elevado a " <<potencia << " tiene como total: " << total << "\n\t";
	
	for(i = 1; i <= potencia; i++)
	{
		factorial = factorial * i;
	}
	
	cout << "\n\tEl numero " << potencia << "! es: " << factorial << "\n\n"; 
}
