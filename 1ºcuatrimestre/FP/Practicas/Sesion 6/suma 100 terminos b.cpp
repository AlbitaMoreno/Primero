/* Dise�ar un programa para calcular la suma de los 100 primeros t�rminos de la sucesi�n
siguiente:
	a = (((-1)^i)*((i^2) -1))/2*i
No puede usarse la funci�n pow. Hacedlo calculando expl�citamente, en cada iteraci�n,
el valor (-1)^i (usad un bucle for). Posteriormente, resolvedlo calculando dicho
valor a partir del calculado en la iteraci�n anterior, es decir, (-1)^i-1.*/

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
		
		for(j = 1; j <= i - 1; j++)		//cuando i sea par j ser� impar, de modo que el signo ir� justo al contrario.
		{
			pot_1 = pot_1 * (-1);
		}
		
		algoritmo = (pot_1 * ((i*i) - 1)) / (2 * i);
			
		cout << "\n\tLa suma de " << i << " es: " << algoritmo << "\n";
	}
}
