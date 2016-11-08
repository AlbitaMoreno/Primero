/*Se pide leer un car�cter desde teclado, obligando al usuario a que sea una letra may�scula.
Para ello, habr� que usar una estructura repetitiva do while, de forma que
si el usuario introduce un car�cter que no sea una letra may�scula, se le volver� a
pedir otro car�cter. Calculad la min�scula correspondiente e imprimidla en pantalla.
No pueden usarse las funciones tolower ni toupper de la biblioteca cctype*/

#include <iostream>

using namespace std;

int main()
{
	char letra_mayus;
	char letra_minus;
	bool es_mayusc;
	const int dist_mayus_minus = 'a'-'A';		//Para convertir de mayusculas a minusculas, el valor es siempre constante
	
	do
	{
		cout << "\nInserte letra mayuscula--> ";
		cin >> letra_mayus;
		es_mayusc = ((letra_mayus >= 'A') && (letra_mayus <= 'Z'));
		
	}while(!es_mayusc);	//El bucle se repite hasta que se introduce una may�scula.	
			
	letra_minus = letra_mayus + dist_mayus_minus;			
	cout << "\nLa minuscula correspondiente es--> " << letra_minus << "\n\n";
				
}
