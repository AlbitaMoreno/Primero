/*Un número narcisista es aquel que es igual a la suma de cada uno de sus dígitos elevados a la "n" potencia
 (donde "n" es el número de cifras del número). La metáfora de su nombre alude a lo mucho que parecen 
 "quererse a sí mismos" estas cifras. Por ejemplo, el 153 es un número narcisista 
 puesto que 13 + 53 + 33 = 1 + 125 + 27 = 153. */

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int numero;
	double cifra = 0;
	int suma = 0;
	int potencia = 1;
	int contador = 0;
	int numero1, numero2;
	
	do
	{
		cout << "\nIntroduzca un numero mayor que 0 para comprobar si es narcista ---> ";
		cin >> numero;
	}while(numero < 0);
	
	numero1 = numero;
	numero2=numero;
	
	while(numero != 0)
	{
		numero = numero/10;
		contador++;
	}
	
	do
	{
		cifra  = numero1 % 10;
		numero1 = numero1 / 10;
		potencia = pow(cifra, contador);
		suma = suma + potencia;
	}while(numero1 != 0);
	
	if(numero2 == suma)
	{
		cout << "\n\t\tEl numero " << numero2 << " es narcisista.";
	}
	else
	{
		cout << "\n\t\tEl numero " << numero2 << " no es narcisista.";
	}
	 
}
