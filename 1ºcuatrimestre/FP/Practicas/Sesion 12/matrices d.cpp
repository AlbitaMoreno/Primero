/*En este ejercicio, no hay que construir ninguna clase ni función. Es un ejercicio sobre
recorridos de una matriz.

Leed desde teclado dos variables util_filas y util_columnas y leed los datos
de una matriz de enteros de tamaño util_filas x util_columnas. Sobre dicha
matriz, se pide lo siguiente:

d) Leer los datos de otra matriz y multiplicar ambas matrices (las dimensiones de la
segunda matriz han de ser compatibles con las de la primera para poder hacer la
multiplicación)*/

#include <iostream>

using namespace std;

int main(){
	int util_filas1, util_filas2;
	int util_columnas1, util_columnas2;
	int i, j, k;
	
	do{
		cout << "\nIntroduzca el numero de filas para la primera matriz: ";
		cin >> util_filas1;
		cout << "\nIntroduzcal el numero de columnas para la primera matriz: ";
		cin >> util_columnas1;
		cout << "\nIntroduzca el numero de filas para la segunda matriz: ";
		cin >> util_filas2;
		cout << "\nIntroduzcal el numero de columnas para la segunda matriz: ";
		cin >> util_columnas2;
	}while(util_columnas1 != util_filas2); 			//Dos matrices A y B son compatibles para el producto si el número de columnas de A coincide con el número de filas de B.
	
	
	int matriz[util_filas1][util_columnas1];
	int matriz2[util_filas2][util_columnas2];
	int multiplicacion[util_columnas1][util_filas2];
	
	cout << "\nPara la primera matriz: \n";
	
	for(i = 0; i < util_filas1; i++){			//llenar la matriz
		for(j = 0; j < util_columnas1; j++){
			cout << "\nIntroduzca para la posicion " << i << " x " << j << " un dato: ";
			cin >> matriz[i][j];
		}
		cout << "\n ";
	}
	
	cout << "\nPara la segunda matriz: \n";
	
	for(i = 0; i < util_filas2; i++){		//leer matriz y escribir los datos en otra matriz
		for(j = 0; j < util_columnas2; j++){
			cout << "\nIntroduzca para la posicion " << i << " x " << j << " un dato: ";
			cin >> matriz2[i][j];			
			cout << " " << matriz2[i][j];
		}
		cout << "\n";
	}
	
		for(i = 0; i < util_filas2; i++){			//Inicializamos la matriz a 0
			for(j = 0; j < util_columnas2; j++){
				multiplicacion[i][j] = 0;
			}
		}
	cout << "\nLa matriz resultante: \n";
	
	for(i = 0; i < util_filas1; i++){
		for(j = 0; j < util_columnas2; j++){
			for(k = 0; k < util_columnas1; k++){
				multiplicacion[i][j] = multiplicacion[i][j] + matriz[i][k] * matriz2[k][j];
				
				cout << "\t " << multiplicacion[i][j];
			}	
		}
		cout << "\n";
	}
}
