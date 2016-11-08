/*En este ejercicio no hay que definir ninguna clase. Todas las operaciones se realizan
directamente en el main.
Realizad un programa que vaya leyendo caracteres hasta que se encuentre un punto
'.'. Contad el n�mero de veces que aparece cada una de las letras may�sculas e
imprimirlo en pantalla.
Una posibilidad ser�a declarar un vector contador_mayusculas y conforme se va
leyendo cada car�cter, ejecutar un conjunto de sentencias del tipo:
if (letra == 'A')
contador_mayusculas[0] = contador_mayusculas[0] + 1;
else if (letra == 'B')
contador_mayusculas[1] = contador_mayusculas[1] + 1;
else if (letra == 'C')
contador_mayusculas[2] = contador_mayusculas[2] + 1;
else ....
Sin embargo, este c�digo es muy redundante. Como soluci�n se propone calcular de
forma directa el �ndice entero que le corresponde a cada may�scula, de forma que
todos los if-else anteriores los podamos resumir en una �nica sentencia del tipo:
contador_mayusculas[indice] = contador_mayusculas[indice] + 1;
Hacedlo, declarando la secuencia directamente dentro del main.
Finalidad: Acceder a las componentes de un vector con unos �ndices que representen
algo.*/

#include <iostream>

using namespace std;

int main()
{
	int tope = 50;
	char cadena[tope];
	int utilizados;
	char caracter;
	bool es_mayus;
	int contador_mayus = 0;
	int i = 0;
	int j; 
	

	
	cout << "\nPara dejar de introducir caracteres introduzca '.'";
	
	do{
		cout << "\n\nIntroduzca un caracter: ";
		cin >> caracter;
		utilizados++;
		i++;
		cadena[i] = caracter;
	}while(caracter != 46 && i <= tope);				// 46 es el valor del '.' en la tabla ASCII
	
	for( j = 0; j <= utilizados - 1; j++){
		es_mayus = ((cadena[j] >= 'A') && (cadena[j] <= 'Z'));
		if(es_mayus){
			contador_mayus++;
		}
	}
	
	cout << "\nEn total hay " << contador_mayus << " mayusculas en la cadena.";
}


