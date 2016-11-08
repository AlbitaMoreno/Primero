/* Sobre el mismo ejercicio del capital y los intereses, construid un programa para calcular
cuántos años han de pasar hasta llegar a doblar, como mínimo, el capital inicial.
Los datos que han de leerse desde teclado son el capital inicial y el interés anual. */

#include <iostream>

using namespace std;

int main()
{
	double capital_inicial;
	double capital2; 
	double interes;
	int i=0; 		
	
	cout << "\nIntroduzca el capital: ";
	cin >> capital_inicial;
	cout << "\nIntroduzca el interes anual: ";
	cin >> interes;

	/*Se ejecuta el do, de modo que se calcule un total en función del valor del contador, hasta que no se cumpla la condición de while, es decir, que 
	el total sea superior o igual al capital2, el bucle continuará*/

	capital2 = capital_inicial;
	
	do			
	{		
		capital2 = (capital2 + capital2*interes/100);		
		i++;		//i incrementa en 1 hasta que se cumpla el while.						
	}	
	while(capital2 < 2*capital_inicial);				
	
	cout << "\nEl capital " << capital_inicial << " al interes  " << interes << " tardara en duplicarse: "<< i << " anios\n\n";		
	//Por pantalla debe salir i, ya que el contador son los años que pasan.
}
