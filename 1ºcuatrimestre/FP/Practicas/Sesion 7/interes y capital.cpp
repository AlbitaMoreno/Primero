/* Sobre la solución del ejercicio 15 de esta relación de problemas, se pide lo siguiente.
Supondremos que sólo pueden introducirse intereses enteros (1, 2, 3, etc). Se pide
calcular el capital obtenido al término de cada año, pero realizando los cálculos para
todos los tipos de interés enteros menores o iguales que el introducido (en pasos de
1). Por ejemplo, si el usuario introduce un interés igual a 5 y un número de años igual
a 3, hay que mostrar el capital ganado al término de cada uno de los tres años a un
interés del 1 %, a continuación, lo mismo para un interés del 2% y así sucesivamente
hasta llegar al 5 %. El programa debe mostrar una salida del tipo:
Cálculos realizados al 1%:
Dinero obtenido en el año número 1 = 2020
Dinero obtenido en el año número 2 = 2040.2
Dinero obtenido en el año número 3 = 2060.6

Cálculos realizados al 2%:
Dinero obtenido en el año número 1 = 2040
Dinero obtenido en el año número 2 = 2080.8
Dinero obtenido en el año número 3 = 2122.42
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
