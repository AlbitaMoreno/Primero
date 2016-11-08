/*Modificad los dos ejercicios anteriores para que se lea desde teclado el valor inicial
y el número de filas a imprimir. En los ejemplos anteriores, el valor inicial era 1 y se
imprimían un total de 6 filas.*/

#include <iostream>

using namespace std;

int  main()
{
	int fila;
	int columna;
	int numero;
	int numero_o = 0;		//guarda el valor de numero para no pisar valores.
	int numero_1;
	int numero_2;
	
	do														
	{
		cout << "\nIntroduzca un numero incial: ";
		cin >> numero_1;
		cout << "\nIntroduzca el numero de filas: ";
		cin >> numero;
	}while((numero <= 0) && (numero_1 <= 0));
	
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

