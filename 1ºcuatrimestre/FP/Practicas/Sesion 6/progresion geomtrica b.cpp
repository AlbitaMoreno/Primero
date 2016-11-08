/*Se pide crear un programa que lea desde teclado r, el primer elemento a1 y el tope k
y calcule la suma de los primeros k valores de la serie. 
b)Si analizamos la expresión algebraica de la serie numérica, nos damos cuenta
que es una progresión geométrica */

#include <iostream>
using namespace std;

int main()
 {
	double num_a;
	double razon_r;
	int tope_k;
	int i;
	double total;
		
	cout << "\nIntroduzca la base: ";
	cin >> num_a;
	cout << "\nIntroduzca el factor de la progresion (r): ";
	cin >> razon_r;
	cout << "\nIntroduzca el tope exponecial: ";
	cin >> tope_k;

	for (i = 1; i <= tope_k; i++)
	{
		num_a =  (num_a * razon_r); //num_a va almacenando valores hasta que i llegue a tope, el for parará y se mostrara el resultado en pantalla.
		total = total + num_a;		
	}
	
	cout << "\n\tLa progresion como valor final: " << total;
}
