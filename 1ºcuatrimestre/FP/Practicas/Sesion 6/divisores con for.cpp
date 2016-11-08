/*Reescribid la solución a los ejercicios 12 (divisores) usando un bucle
for*/

/*Divisores

int main()
{
	int tope;
	int divisor = 1;
	
	do
	{
		cout << "\nIntroduzca un numero mayor que cero: ";
		cin >> tope;
		
	}while(tope <= 0);		//asegurar que el numero es mayor que 0.

	cout << "\n\nEl numero: " << tope << " tiene como divisores: \n";
	
	while(divisor < tope)
		{
		
			if(tope % divisor == 0)
			{
				cout << "\n\t * " << divisor << "\n\n";
			}
		
		divisor++;
		}	
}
*/

#include <iostream>

using namespace std;

int main()
{
	int tope;
	int divisor = 2;			//todo numero es divisible entre 1.
	
	do
	{
		cout << "\nIntroduzca un numero mayor que cero: ";
		cin >> tope;
		
	}while(tope <= 0);		//Filtro  para introducir un numero mayor que 0.
	
	cout << "\n\nEl numero: " << tope << " tiene como divisores: \n";
	
	for(divisor = 2 ; divisor < tope ; divisor++)
	{
			if(tope % divisor == 0)
			{
				cout << "\n\t * " << divisor << "\n\n";
			}
	}
}


