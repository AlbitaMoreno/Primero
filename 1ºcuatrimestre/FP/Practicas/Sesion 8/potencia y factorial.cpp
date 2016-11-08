/*Reescribid la solución del ejercicio 20 (factorial y potencia) de la Relación de Problemas
II, modularizándola con funciones.*/

#include <iostream>
using namespace std;

long long Factorial(int exponente)
{
	int i;
	int factorial = 1;
	for(i = 1; i <= exponente; i++)
	{
		factorial = factorial * i;
	}
	return factorial;
}

double Potencia(int base, int exponente)
{
	int i;
	int potencia = 1;
	for(i = 1; i <= exponente; i++)
	{
		potencia =  potencia * base;
	}
	return potencia;
}

int main()
{
	int exponente;
	int base;
	int resultado_fact;
	int resultado_pot;
	
	cout << "\nIntroduzca una base para la potencia: ";
	cin >> base;
	cout << "\nIntroduzca el exponente: ";
	cin >> exponente;
	
	resultado_fact = Factorial(exponente);
	resultado_pot = Potencia(base, exponente);
	
	cout << "\n\tEl numero " << base << " elevado a " << exponente << " tiene como total: " << resultado_pot << "\n";
	cout << "\n\tEl numero " << exponente << "! es: " << resultado_fact << "\n\n"; 
	
}
