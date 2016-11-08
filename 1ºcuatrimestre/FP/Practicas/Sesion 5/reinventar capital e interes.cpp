/* Modifiquemos el ejercicio 2 del capital y los intereses de la primera relaci�n. Supongamos
ahora que se quiere reinvertir todo el dinero obtenido (el original C m�s los
intereses producidos) en otro plazo fijo a un a�o. Y as�, sucesivamente. Construid un
programa para que lea el capital, el inter�s y un n�mero de a�os N, y calcule e imprima
todo el dinero obtenido durante cada uno de los N a�os, suponiendo que todo
lo ganado (incluido el capital original C) se reinvierte a plazo fijo durante el siguiente
a�o. El programa debe mostrar una salida del tipo:
Total en el a�o n�mero 1 = 240
Total en el a�o n�mero 2 = 288
Total en el a�o n�mero 3 = 345.6
......................
*/

#include <iostream>

using namespace std;

int main()
{
	double capital;
	double interes;
	int i=1;				//Se declara la variable contador i.
	int anio;
		
	cout << "\nIntroduzca el capital: ";
	cin >> capital;
	cout << "\nIntroduzca el interes: ";
	cin >> interes;
	cout << "\nIntroduzca anio: ";
	cin >> anio;
	
	while(i <= anio)		 //i se incrementa en uno mientras sea inferior o igual al a�o, en el momento que sea superior el bucle se para.
	{
		capital = (capital + capital*(interes/100));	
		cout << "\nTotal en el anio numero " << i << " = " << capital << "\n\n";			
		i++;																										
	}	
}
