/*numeros primos*/
#include <iostream>
using namespace std;

int main()
{
	int tope;
	int i;
	bool primo = true;
	
	do
	{
		cout << "\nIntroduzca un numero mayor que cero: ";
		cin >> tope;
		
	}while(tope <= 0);		//asegurar que el numero es mayor que 0.
	
	
	for(i = 2; i < tope; i++)
	{
		if(tope % i == 0)
		{
			primo = false;
		}
	}
	if(primo)
	{
		cout << "\n\tEl numero " << tope << " es primo.";
	}
	else 
	{
		cout << "\n\tEl numero " << tope << " no es primo.";
	}
}

