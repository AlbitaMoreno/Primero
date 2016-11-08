/* Realizar un programa que lea enteros desde teclado y calcule cuántos se han introducido
y cual es el mínimo de dichos valores (pueden ser positivos o negativos). Se
dejará de leer datos cuando el usuario introduzca el valor 0. Realizad la lectura de
los enteros dentro de un bucle sobre una única variable llamada dato. Es importante
controlar los casos extremos, como por ejemplo, que el primer valor leído fuese ya el
terminador de entrada (en este caso, el cero).*/

#include <iostream>

using namespace std;

int main()
{
	double dato;
	double menor=0;			//Se inicializa menor a 0.
	int i=0;
	
	do
	{
		cout << "\nIntroduzca un numero entero. Para terminar pulse 0: ";
		cin >> dato;
		
		if(dato != 0)
		{
			if(i == 0)				//Primer dato que se introduce.
			{
			menor = dato;
			}
		
			if(menor > dato)		//Compara el dato y el menor.
			{
			menor = dato; 
			}		
			i++; //contador, suma 1 según se repita el bucle.
		}
		
	}while(dato != 0);	//mientras dato sea distinto de 0, cuando sea 0 sale del bucle.
	
	cout << "\n\tEl numero de digitos introducidos es: " << i << "\n";
	cout << "\n\tEl menor es: " << menor <<"\n";
}
