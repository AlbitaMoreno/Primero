/*Cread un programa que ofrezca en pantalla la siguiente salida:
1 2 3 4 5 6
2 3 4 5 6 7
3 4 5 6 7 8
4 5 6 7 8 9
5 6 7 8 9 10
6 7 8 9 10 11
*/

#include <iostream>

using namespace std;

int main()
{
	int fila;
	int columna;
	int numero;
	int numero_1 = 0;
	int total;
	
	do														
	{
		cout << "\nIntroduzca un numero: ";
		cin >> numero;
	}while(numero <= 0);
	
	for(fila = 1; fila <= numero; fila++)
		{
			for(columna = 1; 	columna <= numero; columna++)
			{
				total = numero_1 + columna;
				cout << " " << total;
			}
			numero_1++;
			cout << "\n";
		}
}

