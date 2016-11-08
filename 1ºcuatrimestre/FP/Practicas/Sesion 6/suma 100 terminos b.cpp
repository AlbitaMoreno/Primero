/* Diseñar un programa para calcular la suma de los 100 primeros términos de la sucesión
siguiente:
	a = (((-1)^i)*((i^2) -1))/2*i
No puede usarse la función pow. Hacedlo calculando explícitamente, en cada iteración,
el valor (-1)^i (usad un bucle for). Posteriormente, resolvedlo calculando dicho
valor a partir del calculado en la iteración anterior, es decir, (-1)^i-1.*/

#include <iostream>

using namespace std;

int main()
{
	int i;
	int j;
	double algoritmo;
	double pot_1;			// se corresponde con (-1)^i-1
	
	for(i = 1; i <= 100; i++)
	{
		pot_1 = 1;
		
		for(j = 1; j <= i - 1; j++)		//cuando i sea par j será impar, de modo que el signo irá justo al contrario.
		{
			pot_1 = pot_1 * (-1);
		}
		
		algoritmo = (pot_1 * ((i*i) - 1)) / (2 * i);
			
		cout << "\n\tLa suma de " << i << " es: " << algoritmo << "\n";
	}
}
