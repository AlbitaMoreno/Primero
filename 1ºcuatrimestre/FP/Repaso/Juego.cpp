/*Dise�ar un programa para jugar a adivinar un n�mero. El juego tiene que dar pistas
de si el n�mero introducido por el jugador est� por encima o por debajo del n�mero
introducido. Como reglas de parada considerad a) que haya acertado o b) se haya
hartado y decida terminar (escoged c�mo se quiere que se especifique esta opci�n)
Realizar el mismo ejercicio pero permitiendo jugar tantas veces como lo desee el
jugador.*/

#include <iostream>
using namespace std;

int main()
{
	int buscar = 29;
	int numero;
	
	cout << "\n\nSi no quiere introducir mas numeros, pulse -1";
	
	do
	{
		cout << "\n\nIntroduzca un numero ";
		cin >> numero;
		
		if(numero < buscar)
		{
			cout << "\n\tEl numero introducido es menor que el numero que se busca.";
		}
		
		if(numero > buscar)
		{
			cout << "\n\tEl numero introducido es mayor que el numero que se busca.";
		}
		
		if(numero == buscar)
		{
			cout << "\n\t��HA ACERTADO!!";
		}
			
	}while(numero != (-1));
	
}
