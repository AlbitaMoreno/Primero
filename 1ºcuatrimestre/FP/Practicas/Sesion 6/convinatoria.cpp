/*Calcular el combinatorio de n m, con n y m  valores enteros. */

#include <iostream>

using namespace std;

int main()
{

	int convinatoria;
	int eme;
	int ene;
	int i;												//contadores para hacer el factorial. 
	int facto_n = 1;
	int facto_m = 1;
	int facto_resta = 1;
	int resta;											//resta n-m
	bool comparacion = true;
	
	do
	{
		cout << "\nIntroduzca n: ";
		cin >> ene;
		cout << "\nIntroduzca m: ";
		cin >> eme;
		
	}while(ene < eme);		//condicion que n >= m, pide datos hasta que se cumpla.
	
	if(comparacion)			//convinatoria siempre va aser true debido al do while, que estará repitiendos
	{
		for(i = 1; i <= ene; i++)		//!n para hacer el calculo final.
		{
			facto_n = facto_n * i;
		}
		
		for(i = 1; i <= eme; i++)
		{
			facto_m = facto_m * i;
		}
		
		resta = ene - eme;
		
		for(i = 1; i <= resta; i++)
		{
			facto_resta = facto_resta * i;
		}
		
		convinatoria = facto_n / (facto_m * facto_resta);
		
		cout << "\n\tLa convinatoria de n sobre m es: " << convinatoria << "\n\n";
	}
}
