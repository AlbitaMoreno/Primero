/* Realizar un programa que lea desde teclado un entero tope e imprima en pantalla todos
sus divisores propios. Para obtener los divisores, basta recorrer todos los enteros
menores que el valor introducido y comprobar si lo dividen. A continuación, mejorar el
ejercicio obligando al usuario a introducir un entero positivo, usando un filtro con un
bucle post test (do while).*/

#include <iostream>

using namespace std;

int main()
{
	double capital;
	double interes;
	int i=1;				//Se declara la variable contador i, la cual usaremos en el for.
	int anio;
		
	cout << "\nIntroduzca el capital: ";
	cin >> capital;
	cout << "\nIntroduzca el interes: ";
	cin >> interes;
	cout << "\nIntroduzca anio: ";
	cin >> anio;
	 
	for(i = 1 ; i <= anio ; i++)			//El bucle for continúa hasta que i coincida con el año, donde i será el contador e irá 
	{												//aumentando de uno en uno.
		capital = (capital + capital*(interes/100));		
		cout << "\nTotal en el anio numero " << i << " = " << capital << "\n\n";
	}
}

