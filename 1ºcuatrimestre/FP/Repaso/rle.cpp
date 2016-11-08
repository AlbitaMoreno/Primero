/*El m´etodo RLE (Run Length Encoding) codifica una secuencia de datos
formada por series de valores id´enticos consecutivos como una secuencia
de parejas de n´umeros (valor de la secuencia y n´umero de veces que se
repite). Realizar un programa que lea una secuencia de n´umeros naturales
terminada con un n´umero negativo que se supone codificada con el m´etodo
RLE y obtenga la secuencia decodificada.

Entrada: 3 1 5 2 6 3 1 5 -1
			(tres veces 1, cinco veces 2, seis veces 3, una vez 5)
Salida: 1 1 1 2 2 2 2 2 3 3 3 3 3 3 5
*/

#include <iostream>
using namespace std;

int main(){
	int numero;
	int repeticion;
	int i = 0;
	int j, k;
	int tope;
	int rle_numero[150];
	int suma = 0;
	int utilizados = 0;
	
	cout << "\nPara dejar de introducir caracteres en la cadena introzca '-1'";
	do{
		cout << "\nPareja: " << i + 1 << " ";
		cout << "\nIntroduzca el primer dijito de la pareja: ";
		cin >> numero;
		utilizados++;
		rle_numero[i] = numero;
		cout << "\nIntroduzca el segundo dijito de la pareja: ";
		cin >> repeticion;
		utilizados++;
		rle_numero[i+1] = repeticion;
		i++;
	}while(numero >= 0 && repeticion >= 0);
	
	for(i = 1; i < 150; i = i + 2){ // lee las repeticiones
		suma = suma + rle_numero[i];
		
	}
	for(i = 0; i<utilizados; i++){
		cout << rle_numero[i];
	}
	int rle_posicion[suma];
	
	for(i = 0; i < utilizados; i++){ //Lee el numero
		for(j = 1; j < utilizados; j++){//Lee la repeticion
			for(k = 0;  k <= rle_numero[j]; k++){
				
				rle_posicion[k] = rle_numero[i];
				cout << rle_posicion[k];
			}
			
		}
		cout << " ";
	}
}
