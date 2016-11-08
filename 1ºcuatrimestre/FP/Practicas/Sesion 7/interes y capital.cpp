/* Sobre la soluci�n del ejercicio 15 de esta relaci�n de problemas, se pide lo siguiente.
Supondremos que s�lo pueden introducirse intereses enteros (1, 2, 3, etc). Se pide
calcular el capital obtenido al t�rmino de cada a�o, pero realizando los c�lculos para
todos los tipos de inter�s enteros menores o iguales que el introducido (en pasos de
1). Por ejemplo, si el usuario introduce un inter�s igual a 5 y un n�mero de a�os igual
a 3, hay que mostrar el capital ganado al t�rmino de cada uno de los tres a�os a un
inter�s del 1 %, a continuaci�n, lo mismo para un inter�s del 2% y as� sucesivamente
hasta llegar al 5 %. El programa debe mostrar una salida del tipo:
C�lculos realizados al 1%:
Dinero obtenido en el a�o n�mero 1 = 2020
Dinero obtenido en el a�o n�mero 2 = 2040.2
Dinero obtenido en el a�o n�mero 3 = 2060.6

C�lculos realizados al 2%:
Dinero obtenido en el a�o n�mero 1 = 2040
Dinero obtenido en el a�o n�mero 2 = 2080.8
Dinero obtenido en el a�o n�mero 3 = 2122.42
*/

#include <iostream>

using namespace std;

int main()
{
	double interes;
	int anio;
	double capital, capital1;
	int i;
	int contador;
		
	do{
		cout << "\nIntroduzca el capital: ";
		cin >> capital;
		cout << "\nIntroduzca el anio: ";
		cin >> anio;
		cout << "\nIntroduzca el interes: ";
		cin >> interes;
	}while((capital <= 0) || (anio <= 0) || (interes <= 0));
	
	
	
	for(contador = 1; contador <= interes; contador++)
	{
		capital1 = capital;
		
		cout << "\n\nCalculos realizados al " << contador << " %: \n";
		
		for(i = 1; i <= anio; i++)
		{
			capital1 = capital1 + ((capital1 * contador)/100);	
			
			cout << "\nDinero obtenido en el anio " << i << " = " << capital1;
		}
			
	}
}
