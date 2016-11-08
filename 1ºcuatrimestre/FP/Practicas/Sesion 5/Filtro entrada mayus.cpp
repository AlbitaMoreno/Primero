/*Se pide leer un carácter desde teclado, obligando al usuario a que sea una letra mayúscula.
Para ello, habrá que usar una estructura repetitiva do while, de forma que
si el usuario introduce un carácter que no sea una letra mayúscula, se le volverá a
pedir otro carácter. Calculad la minúscula correspondiente e imprimidla en pantalla.
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
		
	}while(!es_mayusc);	//El bucle se repite hasta que se introduce una mayúscula.	
			
	letra_minus = letra_mayus + dist_mayus_minus;			
	cout << "\nLa minuscula correspondiente es--> " << letra_minus << "\n\n";
				
}
