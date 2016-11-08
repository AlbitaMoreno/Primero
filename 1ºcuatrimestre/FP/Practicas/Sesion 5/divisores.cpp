/* Realizar un programa que lea desde teclado un entero tope e imprima en pantalla todos
sus divisores propios. Para obtener los divisores, basta recorrer todos los enteros
menores que el valor introducido y comprobar si lo dividen. A continuación, mejorar el
ejercicio obligando al usuario a introducir un entero positivo, usando un filtro con un
bucle post test (do while).*/

#include <iostream>

using namespace std;

/*int main()
{
	int tope;
	int divisor = 1;
	
	cout << "\nIntroduzca un numero mayor que cero: ";
	cin >> tope;
	cout << "\n\nEl numero: " << tope << " tiene como divisores: ";
	
	while(divisor <= tope)
	{		
		if(tope % divisor == 0)
		{
			cout << "\n\t * " << divisor << "\n";
		}		
		divisor++;
	}
}

Este sería el programa sin usar un filtro, al introducir un numero menor que cero, imprimiria por pantalla un mensaje que queremos evitar (no queremos mostrar divisores de 
números negarivos)
*/

int main()
{
	int tope;
	int divisor = 1;
	
	do
	{
		cout << "\nIntroduzca un numero mayor que cero: ";
		cin >> tope;
		
	}while(tope <= 0);		//asegurar que el numero es mayor que 0.

	cout << "\n\nEl numero: " << tope << " tiene como divisores: \n";
	
	while(divisor < tope)
		{
		
			if(tope % divisor == 0)
			{
				cout << "\n\t * " << divisor << "\n\n";
			}
		
		divisor++;
		}	
}



