/*Modificad los dos ejercicios anteriores para que se lea desde teclado el valor inicial
y el número de filas a imprimir. En los ejemplos anteriores, el valor inicial era 1 y se
imprimían un total de 6 filas.*/

#include <iostream>

using namespace std;

int main()
{
	int fila;
	int columna;
	int numero;
	int numero_1;
	int total;
	int numero_2;
	int numero_o;
	
	do														
	{
		cout << "\nIntroduzca un numero de filas: ";
		cin >> numero;
		cout << "\nIntroduzca el numero de incio: ";
		cin >> numero_1;
	}while(numero <= 0);
	
	for(fila = 1; fila <= numero; fila++)
		{
			for(columna = 1; 	columna <= numero; columna++)
			{
				total = numero_1 + columna;
				cout << " " << total - 1;
			}
			numero_1++;
			cout << "\n";
		}
		
		cout << "\n\n";
		
		numero_o = numero;
	
	for(fila = 1; fila <= numero; fila++)
	{ 
		for(columna = 1; columna <= numero_o; columna++)
		{
			numero_2 = numero_1 + columna;
			
			cout << " " << numero_2 - 1;
		}
		
		numero_o--;
		numero_1++;	
		cout << "\n";	
	}
}

