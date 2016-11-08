/* Se dice que un número es triangular si se puede poner como la suma de los primeros
m valores enteros, para algún valor de m. Por ejemplo, 6 es triangular ya que 
6 = 1 + 2 + 3. Se pide construir un programa que obtenga todos los números triangulares que
hay menores que un entero k introducido desde teclado. Para ello, debe ir probando
la suma de todas las posibles secuencias de enteros menores que el número dado.
Hay que calcular explícitamente la suma con un bucle, por lo que no puede aplicarse
la fórmula que nos da la sumatoria de los n primeros valores, a saber, n(n + 1)=2 */

#include <iostream>

using namespace std;

int main()
{
	int tope_k;
	int num_incio = 0;
	int i;
	
	cout << "\nIntroduzca el numero tope para calcular todos los numeros triangulares menores que el: ";
	cin >> tope_k;
	
	for(i = 1; num_incio <= tope_k; i++)
	{
		num_incio = num_incio + i;
		
		if(num_incio < tope_k)
		{
			cout << "\n\tLos numeros triangulares menores que " << tope_k <<  " son: " << num_incio;
		}
	}
	
}
