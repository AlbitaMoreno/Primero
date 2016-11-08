// M�ximo de los m�nimos
// MaxiMin

/*
En este ejercicio, no hay que construir ninguna clase ni
funci�n. Es un ejercicio sobre recorridos de una matriz.
Leed desde teclado dos variables util_filas y util_columnas y leed los datos
de una matriz de enteros de tama�o util_filas x util_columnas. Sobre dicha
matriz, calcular lo siguiente:
� La posici�n de aquel elemento que sea el mayor de entre los m�nimos de cada
fila. Por ejemplo, dada la matriz M (3 � 4),
9 7 4 5
2 18 2 12
7 9 1 5
el m�ximo entre 4, 2 y 1 (los m�nimos de cada fila) es 4 y se encuentra en la
posici�n (0,2).
� Ver si existe un valor MaxiMin, es decir, que sea a la vez, m�ximo de su fila y
m�nimo de su columna.
*/

#include <iostream>
using namespace std;

int main(){
	const int MAX_FIL = 10, MAX_COL = 10;
	double matriz[MAX_FIL][MAX_COL];
	int util_filas, util_columnas;
   double maximo, minimo;
	int fila_max_min, col_max_min;
	int fila_minimo, columna_minimo;

	// No etiquetamos las entradas porque suponemos que leemos de un fichero
	// Supondremos que util_filas y util_columnas son > 0

	cin >> util_filas;
	cin >> util_columnas;

	for (int i=0; i<util_filas; i++)
		for (int j=0; j<util_columnas; j++)
			cin >> matriz[i][j];

	// M�ximo de los m�nimos

	/*
		Inicializar Max al m�nimo de la primera fila
		Recorrer el resto de filas -i-
			Calcular el m�nimo de la fila i
			y actualizar, en su caso, el m�ximo
	*/

	minimo = matriz[0][0];
	columna_minimo = 0;
	
	for (int j=0; j<util_columnas; j++)
		if (matriz[0][j] < minimo){
			minimo = matriz[0][j];
			columna_minimo = j;
		}

   maximo = minimo;
	fila_max_min = 0;
	col_max_min = columna_minimo;

   for (int i=1 ; i<util_filas ; i++){
		minimo = matriz[i][0];
		columna_minimo = 0;

      for (int j=0; j<util_columnas; j++){
			if (matriz[i][j] < minimo){
				minimo = matriz[i][j];
				columna_minimo = j;
			}
		}

		if (minimo > maximo){
			maximo = minimo;
			fila_max_min = i;
			col_max_min	 = columna_minimo;
		}
   }

	cout << "\nMaxiMin:\nFila: " << fila_max_min <<
		"\nColumna: " << col_max_min << "\nValor: " << maximo;

	/*
		El anterior algoritmo se puede mejorar:
		Si durante el recorrido de una fila f encontramos un elemento
		que es menor que el m�ximo del resto de las filas anteriores,
		el m�nimo de f ser� menor que dicho m�ximo por lo que
		�ste no cambiar�. Nos quedar�a:

		Inicializar Max al m�nimo de la primera fila
		Recorrer el resto de filas -i-
			Calcular el m�nimo de la fila i
			saliendo del recorrido cuando encontremos
			un valor menor que Max
			Actualizar, en su caso, Max
	*/

	bool es_mayor_igual_que_Max;

	minimo = matriz[0][0];
	columna_minimo = 0;
	
	for (int j=0; j<util_columnas; j++)
		if (matriz[0][j] < minimo){
			minimo = matriz[0][j];
			columna_minimo = j;
		}

   maximo = minimo;
	fila_max_min = 0;
	col_max_min = columna_minimo;

   for (int i=1 ; i<util_filas ; i++){
		minimo = matriz[i][0];
		columna_minimo = 0;
		es_mayor_igual_que_Max = true;

      for (int j=0; j<util_columnas && es_mayor_igual_que_Max; j++){
			if (matriz[i][j] < es_mayor_igual_que_Max)
				es_mayor_igual_que_Max = false;
			else{
				if (matriz[i][j] < minimo){
					minimo = matriz[i][j];
					columna_minimo = j;
				}
			}
		}

		if (minimo > maximo){
			maximo = minimo;
			fila_max_min = i;
			col_max_min	 = columna_minimo;
		}
   }

	cout << "\nMaxiMin:\nFila: " << fila_max_min <<
		"\nColumna: " << col_max_min << "\nValor: " << maximo;



	// M�ximo de su fila y m�nimo de su columna

	/*
		Para no tener que recalcular los m�nimos de cada columna, 
		los guardamos en un vector

		Calcular en un vector las filas d�nde se alcanzan 
		los m�nimos de cada columna, es decir:
		fila_minimos_columnas[j] contendr� el n�mero de fila 
		en el que se alcanza	el m�nimo de la columna j

		Recorrer las filas -i- hasta terminarlas o hasta encontrarlo
			Calcular la columna col_maximo en la que se alcanza el m�ximo de la fila i
			Si fila_minimos_columnas[col_maximo] es la fila actual, se ha encontrado

		Tambi�n se podr�a mejorar, calculando �nicamente el m�nimo de cada columna
		cuando sea necesario. Se deja como ejercicio implementarlo:

		Iremos calculando en un vector las filas d�nde se alcanzan 
		los m�nimos de cada columna, es decir:
		fila_minimos_columnas[j] contendr� el n�mero de fila 
		en el que se alcanza	el m�nimo de la columna j
		Al principio, se inicializan a -1 sus componentes

		Recorrer las filas -i- hasta terminarlas o hasta encontrarlo
			Calcular la columna col_maximo en la que se alcanza el m�ximo de la fila i
			Si fila_minimos_columnas[col_maximo] es:
				a) -1 => No se hab�a calculado ese m�nimo => Calcular el m�nimo de la columna col_maximo
				b) Distinto de -1 => Ya se hab�a calculado el m�nimo de la columna col_maximo
						Si fila_minimos_columnas[col_maximo] es la fila actual, se ha encontrado
	*/

	int fila_minimos_columnas[MAX_COL];
	// int fila_minimo;
	bool encontrado_max_fil_min_col;
	int col_maximo;
	int fil_max_fil_min_col;
	int col_max_fil_min_col;

	for (int col=0; col<util_columnas; col++){
		minimo = matriz[0][col];
		fila_minimo = 0;

		for (int fil=1; fil<util_filas; fil++)
			if (matriz[fil][col] < minimo){
				minimo = matriz[fil][col];	
				fila_minimo = fil;
			}
		
		fila_minimos_columnas[col] = fila_minimo;
	}

	encontrado_max_fil_min_col = false;

	for (int i=0; i<util_filas && !encontrado_max_fil_min_col; i++){
		maximo = matriz[i][0];

		for (int j=0; j<util_columnas; j++)
			if (matriz[i][j] > maximo){
				maximo = matriz[i][j];
				col_maximo = j;
			}

		if (fila_minimos_columnas[col_maximo] == i){
			encontrado_max_fil_min_col = true;
			fil_max_fil_min_col = i;
			col_max_fil_min_col = col_maximo;
		}
	}

	cout << "\n\n";

	if (encontrado_max_fil_min_col)
		cout << "\nEncontrado MaxFilMinCol:" 
			  << "\nFila: " << fil_max_fil_min_col
			  << "\nColumna: " << col_max_fil_min_col 
			  << "\nValor: " << matriz[fil_max_fil_min_col][col_max_fil_min_col];
	else
		cout << "\nNo Encontrado MaxFilMinCol";

   cout << "\n\n";
	system("pause");
}
