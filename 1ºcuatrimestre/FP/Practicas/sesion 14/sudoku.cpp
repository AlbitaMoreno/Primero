/*(Examen Septiembre 2013) Sudoku es un juego muy popular que consiste en rellenar
una cuadrícula de 9  9 celdas que está dividida en subcuadrículas de 3  3 (denominadas
regiones) con cifras del 1 al 9. Un sudoku se considera resuelto si verifica
que:
 En cada fila aparecen todos los números del 1 al 9 (sin repetir)

 En cada columna aparecen todos los números del 1 al 9 (sin repetir)

 En cada región aparecen todos los números del 1 al 9 (sin repetir)

Realizar un programa que lea todos los elementos de un sudoku y determine si está
resuelto o no. Un ejemplo de sudoku resuelto es el siguiente:
Implemente la solución con una clase Sudoku con un dato miembro matriz de doble
corchete y añada un programa principal de prueba.*/

#include <iostream> 

using namespace std; 

class Sudoku{
	private:
		static const int MAXIMO_FILAS = 9;
		static const int MAXIMO_COLUMNAS = 9;
		int matriz_tablero[MAXIMO_FILAS][MAXIMO_COLUMNAS	];
		int util_filas;
		int util_columnas;
	public:
		Sudoku()
			:util_filas(MAXIMO_FILAS), util_columnas(MAXIMO_COLUMNAS){
			}
		
		void SetCoeficientes(int nuevo, int i, int j){
			matriz_tablero[i][j] = nuevo;	
		}
		
		int GetUtilizadosFilas(){
			return util_filas;
		}
		
		int GetUtilizadosColumnas(){
			return util_columnas;
		}
		//devuelve un elemento de la matriz
		int GetElemento(int i, int j){
			if (i < util_filas && j < util_columnas){
				return matriz_tablero[i][j];
			}
		}
		
		bool SudokuCorrecto(){						// método para ver si el Sudoku es correcto
			if (ComprobarResueltoFila())
				if (ComprobarResueltoColumna())
					if (ComprobarRegionesCorrectas())
						return true;
					else
						return false;
				else
					return false;
			else
				return false;
		}
		
		bool ComprobarResueltoFila(){		//Comprueba si hay numeros rpetidos en una misma fila
			int iguales = 0;
			int i, j, k;
			
			for (i = 0 ; i < util_filas ; i++){
				for (j = 1 ; j <= 9 ; j++){							//recorre la matriz t controla que se cumpla que la matriz sea de 9*9
					for (k = 0 ; k < util_columnas ; k++){			//También de paso sirve para que de falso si aparece un 0, una letra... o algo que no sea un número entre 1-9
						if (matriz_tablero[i][k] == j)
							iguales ++;
					}
					if (iguales != 1)
						return false;
					else
						iguales = 0;
				}
			}
			return true;
		}
		
		bool ComprobarResueltoColumna(){				// Declara un método para ver si las columnas del Sudoku son correctas
			int iguales = 0;
			int i, j, k;
			
			for (i = 0 ; i < util_columnas; i++){
				for (j = 1 ; j <= 9; j++){
					for (k = 0 ; k < util_filas; k++){
						if (matriz_tablero[k][i] == j)
							iguales ++;
					}
					if (iguales != 1)
						return false;
					else
						iguales = 0;
				}
			}
			return true;
		}
		
		bool ComprobarRegionesCorrectas(){				// Declara un método para ver si las regiones o "celdas" del Sudoku son correctas
			int suma = 0;
			int fila, columna, i, j;
			
			for (fila = 0; fila < 9 ; fila = fila + 3){
				for (columna = 0; columna < 9; columna = columna + 3){
					for (i = fila; i < fila + 3; i++){
						for (j = columna; j < columna + 3; j++){
							suma = suma + matriz_tablero[i][j];
						}
					}
					if (suma != 45)			//cada region 3x3 debe sumar en total 45
						return false;
					else
						suma = 0;
				}
			}
			return true;
		}
};

int main(){ 
   bool correcto;
	int i, j; 
   Sudoku celda;
   int numero;
   
	for (i = 0; i < 8; i++) { 
      for (j = 0; j < 8; j++) { 
         cout << "Introduce el elemento de la fila" << "[ " << i + 1 << " ] y la columna [ " << j + 1 << " ]"; 
         cin >> numero;
			celda.SetCoeficientes(numero, i, j); 
      } 
   }
   
   cout << "\nLa matriz introducida es: \n";
   for(i = 0; i < celda.GetUtilizadosFilas(); i++){
   	for(j = 0; j < celda.GetUtilizadosColumnas(); j++){
   		cout << celda.GetElemento(i, j);
   	}
   	cout << "\n";
   }
	correcto = celda.SudokuCorrecto();
	
	if (correcto)
	 cout << "\nEl Sudoku es correcto\n";
	else
		cout << "\nEl Sudoku NO es correcto\n";
}
