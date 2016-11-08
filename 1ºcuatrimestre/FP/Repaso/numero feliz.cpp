#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int cifra;
	int contador =0; // el numero de cifras sera el numero de pasos a dar. 
	int suma;
	int cifra1 = 0.0;
	int digito =10;
	int contador2= 0;
	
	cout << "\nmete numero ";
	cin >> cifra;
	
	cifra1 = cifra;
	
	do
	{
		cifra = cifra % 10;
		contador++;
		do
		{
			cifra1 = cifra1 % digito;
			cifra1 = cifra1 /10;
			suma = suma + pow (cifra1, 2);
			
			digito= digito * 10;
			contador2++;
		}while(contador2 <= contador);
	
	}while(cifra != 0);
	
	cout << contador;

	
	
	if(suma == 1)
	{
		cout << "\nfeliz";
	}
	else
	{
		cout << "no feliz";
	}
}
