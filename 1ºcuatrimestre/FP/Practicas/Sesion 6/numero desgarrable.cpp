/*Un número entero n se dice que es desgarrable (torn) si al dividirlo en dos partes
izda y dcha, el cuadrado de la suma de ambas partes es igual a n.*/

#include <iostream>

using namespace std;

int main()
{
	int num_entra;
	int num_der;
	int num_izq;
	int divisor = 10;
	bool desgarrable;
	
	cout << "\nIntroduzca un numero: ";
	cin >> num_entra;
	
	while(num_entra / divisor >1)		 //Asegura que el último digito a la izquierda no sea 0. 
	{
		num_der = num_entra / divisor;		//parte derecha
		num_izq = num_entra % divisor;		//parte izquierda, es el resto, así partimos el numero para hacer las combinaciones.
		
		if((num_der + num_izq) * (num_der + num_izq) == num_entra)
		{
			desgarrable = true;
		}
		
		divisor = divisor * 10;		
	}
	
	if(desgarrable)
	{
		cout << "\n\tEl numero es desgarrable \n"; 
	}
	else
	{
		cout << "\n\tEl numero " << num_entra << " no es desgarrable";
	}
}
