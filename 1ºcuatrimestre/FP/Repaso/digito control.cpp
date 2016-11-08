#include <iostream>
using namespace std;

int main()
{
	long long numero;
	int suma_sp = 0;
	int suma_si= 0;
	int suma_total = 0;
	int resto = 0;
	int decena_sup = 0;
	int suma_total1 = 0;
	int contador=0;
	 
	do
	{
		cout << "\nIntroduzca una secuencia: ";
		cin >> numero;
		
		resto = numero % 10;
		numero = numero / 10;
		contador++;
		
		if(contador % 2 == 0)		// ver si es par.
		{
			suma_sp = suma_sp + resto;
		}
		else
		{
			suma_si = suma_si + resto;
		}	

	}while(numero <= 0);

	suma_total = suma_sp + 3 * suma_si;
	suma_total1 = suma_total % 10;
	decena_sup = 10 - suma_total1;
		
	if(decena_sup == 10)
	{
		decena_sup = 0;
		cout << "\n\tEl digito de control es: " << decena_sup << "\n\n";
	}
	else
	{
		cout << "\n\tEl digito de control es: " << decena_sup << "\n\n";
	}
	
}
