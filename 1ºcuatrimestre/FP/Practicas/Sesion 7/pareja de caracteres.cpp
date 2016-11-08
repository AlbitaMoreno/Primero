/* Escribid un programa que lea cuatro valores de tipo char
(min1, max1, min2, max2) e imprima las parejas que pueden formarse con
los conjuntos {min1 ... max1} y {min2 ... max2}. Por ejemplo, si min1 = b,
max1 = d, min2 = j, max2 = m, el programa debe imprimir lo siguiente:
bj, bk, bl, bm, cj, ck, cl, cm, dj, dk, dl, dm */

#include <iostream>

using namespace std;

int main()
{
	char min1;
	char min2;
	char max1;
	char max2;
	char i;							//si lo ponemos como int se muestra el valor de los caracteres en ASCII
	char j;
	
	do
	{
	 cout << "\nIntroduzca un caracter desde donde partira la primera letra: ";
	 cin >> min1;
	 cout << "\nIntrduzca un caracter tope para la primera letra: ";
	 cin >> max1;
	 cout << "\nIntroduzca un caracter desde donde partira la segunda letra: ";
	 cin >> min2;
	 cout << "\nIntroduzca un caracter tope para la segunda letra: ";
	 cin >> max2;
	 cout << "\n";
 }while ((max1 < min1) || (max2 < min2));
 
 	for(i = min1; i <= max1; i++)
 	{
 		for(j = min2; j <= max2; j++)
 		{
 			cout << " " << i << j;		//muestra las convinaciones separadas.
 		}
 		
 	}
}
