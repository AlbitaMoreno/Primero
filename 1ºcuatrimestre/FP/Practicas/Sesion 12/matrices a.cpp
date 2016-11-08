/*En este ejercicio, no hay que construir ninguna clase ni función.
 Es un ejercicio sobre recorridos de una matriz.

Leed desde teclado dos variables util_filas y util_columnas y leed los datos
de una matriz de enteros de tamaño util_filas x util_columnas. Sobre dicha
matriz, se pide lo siguiente:
a) Calcular la traspuesta de la matriz, almacenando el resultado en otra matriz.*/

#include <iostream>

using namespace std;

int main(){
	int util_filas;
	int util_columnas;
	int i, j;

	
	cout << "\nIntroduzca el numero de filas: ";
	cin >> util_filas;
	cout << "\nIntroduzcal el numero de columnas: ";
	cin >> util_columnas;
	
	int matriz[util_filas][util_columnas];
	int matriz2[util_filas][util_columnas];
	
	for(i = 0; i < util_filas; i++){			//llenar la matriz
		for(j = 0; j < util_columnas; j++){
			cout << "\nIntroduzca para la posicion " << i << " x " << j << " un dato: ";
			cin >> matriz[i][j];
		}
		cout << "\n ";
	}
	
	cout << "\nLa matriz es: \n";
	
	for(i = 0; i < util_filas; i++){		//leer matriz y escribir los datos en otra matriz
		for(j = 0; j < util_columnas; j++){
			
			matriz2[j][i] = matriz[i][j];		//Matriz traspuesta.
			
			cout << " " << matriz[i][j];
		}
		cout << "\n";
	}
	
	cout << "\nLa matriz traspuesta: \n";
	
	for(i = 0; i < util_columnas; i++){		// este cambio es necesario ya que si no tenemos una matriz cuadrada el programa no haria la matriz traspuesta correctamente
	
		for(j = 0; j < util_filas; j++){
			
			cout << " " << matriz2[i][j];
		}
		cout << "\n";
	}
}
