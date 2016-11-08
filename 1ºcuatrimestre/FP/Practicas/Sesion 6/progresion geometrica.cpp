/*Se pide crear un programa que lea desde teclado r, el primer elemento a1 y el tope k
y calcule la suma de los primeros k valores de la serie. 
a) Realizad la suma de la serie usando la función pow para el cómputo de cada
término ai. Los argumentos de pow no pueden ser ambos enteros, por lo que
forzaremos a que la base*/

#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
	double num_a;
	double razon_r;
	double tope_k;
	double exponente = 0;
	double total = 0;
	int i;
	
	cout << "\nIntroduzca la base: ";
	cin >> num_a;
	cout << "\nIntroduzca el factor (r): ";
	cin >> razon_r;
	cout << "\nIntroduzca el tope exponecial: ";
	cin >> tope_k;
	
	for(i = 1; i <= tope_k; i++)
	{
		exponente = num_a * pow(razon_r,i);		// se corresponde con r^(k-1), la base es razon_r y el exponente (k-1)
		total = total + exponente;
	}
	
	cout << "\n\tLa progresion como valor final: " << total;	
}
