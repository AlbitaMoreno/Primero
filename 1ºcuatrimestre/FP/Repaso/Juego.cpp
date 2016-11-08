/*Diseñar un programa para jugar a adivinar un número. El juego tiene que dar pistas
de si el número introducido por el jugador está por encima o por debajo del número
introducido. Como reglas de parada considerad a) que haya acertado o b) se haya
hartado y decida terminar (escoged cómo se quiere que se especifique esta opción)
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
			cout << "\n\t¡¡HA ACERTADO!!";
		}
			
	}while(numero != (-1));
	
}
