/* Definid la clase MatrizRectangularEnteros usando una matriz de doble corchete
como dato miembro privado.

int matriz_privada[MAXIMO_FILAS][MAXIMO_COLUMNAS];

Definid métodos para:

a) Obtener el número de filas y columnas utilizadas, así como el dato que haya en
una fila y columna.

b) Devolver una fila completa como un objeto de la clase SecuenciaEnteros.

c) Añadir una fila entera. La fila será un objeto de la clase SecuenciaEnteros.

d) Comprobar si es igual a otra matriz.

e) Obtener la traspuesta.

f ) Comprobar si es simétrica. Hacedlo primero calculando la traspuesta de la matriz
y viendo si es igual a su simétrica, usando los métodos anteriores.

Hacedlo también comprobando directamente si cada componente es igual a su
simétrica y parando el recorrido en cuanto encuentre una componente que no lo
verifique.

g) Multiplicar dos matrices.*/

#include <iostream>
using namespace std;

class SecuenciaEnteros{
	private:
		static const int TAMANIO = 150;
		int vector_fila[TAMANIO];
		int util_filas;
	public:
		SecuenciaEnteros()
			:util_filas(0){
			}
		
		 void SetCoeficientes(int nuevo){
		 	if(util_filas <= TAMANIO){
		 		vector_fila[util_filas] = nuevo;
		 		util_filas++;
		 	}
		 }	
		 
		int TotalUtilizados(){
		 	return util_filas;
		}
	
		int GetNumero(int posicion){		// Declara un método para devolver un dato y añadirlo.
			return vector_fila[posicion];
		}
};

class MatrizRectangularEnteros{
	private:
		static const int MAXIMO_FILAS = 200;
		static const int MAXIMO_COLUMNAS = 200;	
		int matriz_privada[MAXIMO_FILAS][MAXIMO_COLUMNAS];
		int matriz_privada2[MAXIMO_FILAS][MAXIMO_COLUMNAS];
		int utilizados_filas;
		int utilizados_columnas;
		int utilizados_filas2;
		int utilizados_colmnas2;
	public:
		MatrizRectangularEnteros(int util_filas, int util_columnas)		//tamaño de la matriz
			:utilizados_filas(util_filas), utilizados_columnas(util_columnas)	
		{}
		
		int GetMaximoColumnas(){
			return MAXIMO_COLUMNAS;
		}
		
		int GetMaximoFilas(){
			return MAXIMO_FILAS;
		}
	
		int GetFilasUtilizadas(){
			return utilizados_filas;
		}
		
		int GetColumnasUtilizadas(){
			return utilizados_columnas;
		}
		
		//rellenar matriz 
		void RellenarMatriz(int nuevo, int fila, int columna){
			if (utilizados_filas < MAXIMO_FILAS && utilizados_columnas < MAXIMO_COLUMNAS)
				matriz_privada[fila][columna] = nuevo;
		}
		
		int GetElemento(int fila, int columna){
			return matriz_privada[fila][columna];
		}
		
		SecuenciaEnteros Obtener_fila(int fila){
			SecuenciaEnteros mostrar_fila;
			int i;
			
			for(i = 0; i < utilizados_filas; i++){
				mostrar_fila.SetCoeficientes(matriz_privada[fila][i]);
			}
			return mostrar_fila;
		}
		
		void AniadeFila(SecuenciaEnteros nuevo){
			int i;
			if(utilizados_filas < MAXIMO_FILAS){
				for(i = 0; i < nuevo.TotalUtilizados(); i++){
					matriz_privada[utilizados_filas][i] = nuevo.GetNumero(i);
				}
				utilizados_filas++;
			}
		}
		
		//comprobar si es igual a otra matriz
		bool EsIgual(MatrizRectangularEnteros objeto){		
			int i, j;
			
			if (utilizados_filas == objeto.utilizados_filas && utilizados_columnas == objeto.utilizados_columnas){		//las dos matrizes tienen que ser igual de grandes, si no no pueden ser iguales
				for (i = 0; i < utilizados_filas ; i++){
					for (int j = 0 ; j < utilizados_columnas ; j++){ 
						if (matriz_privada[i][j] != objeto.matriz_privada[i][j])		//va comparando cada dato de las dos matrizes, la de la clase y la que se le ha pasao, en cuanto un dato no sea igual retorna falso
							return false;
					}
				}
				return true;
			}
				else
					return false;
		}
		
		MatrizRectangularEnteros GetTraspuesta(){		
			MatrizRectangularEnteros traspuesta(utilizados_columnas, utilizados_filas);
			int i,j;
			
			for (i = 0 ;i < utilizados_filas; i++){
				for (j = 0 ; j < utilizados_columnas; j++){
					traspuesta.matriz_privada[j][i] = matriz_privada[i][j];			//calcula la traspuesta en otro objeto de la clase y lo devuelve
				}
			}
			return traspuesta;
		}
		
		bool EsSimetrica(){		
			MatrizRectangularEnteros objeto(utilizados_filas, utilizados_columnas);
			objeto = GetTraspuesta();
			return EsIgual(objeto);					//una matriz es simétrica si la matriz y su traspuesta son iguales
		}
		
		MatrizRectangularEnteros Multiplicar(MatrizRectangularEnteros objeto){		// Declara un método para multiplicar la matriz con otra matriz pasada como objeto de ésta clase y devolver el resultado en otro objeto también de ésta clase
			MatrizRectangularEnteros multiplicacion(utilizados_filas, objeto.utilizados_columnas);
			int i, j, k;
			
			for (i = 0; i < objeto.utilizados_filas; i++){
				for (j = 0; j < objeto.utilizados_columnas; j++){
					multiplicacion.matriz_privada[i][j] = 0;  //primero incializar a 0 la matriz multiplicada
				}
			}
		
			for (i = 0 ;i < multiplicacion.utilizados_filas; i++){
				for (j = 0 ; j < multiplicacion.utilizados_columnas; j++){
					for (k = 0 ; k < multiplicacion.utilizados_filas; k++){
						multiplicacion.matriz_privada[i][j] = multiplicacion.matriz_privada[i][j] + (matriz_privada[i][k] * objeto.matriz_privada[k][j]);//luego voy haciendo la multiplicacion en objeto_aux que es el que voy a devolver
					}
				}
			}
			return multiplicacion;
		}
};

int main(){
	int columnas, filas, filas2, columnas2;
	int numero;
	int i, j;
	int obtener_fila, dato_fila, fila_aniadir;
	bool iguales, simetrica;
	SecuenciaEnteros fila;
	
	//filtro
	cout << "\nPara la primera matriz: ";
	do{
		cout << "\nIntroduce el numero de filas: ";
		cin >> filas;
		cout << "\nIntroduce el numero de columnas: ";
		cin >> columnas;
	}while(filas >= 1 && columnas >= 1);
	MatrizRectangularEnteros celda(filas,columnas);	
	//rellenar matriz:
	cout << "\n\nRellenar la matriz";
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			cout << "\n\tIntroduzca un digito para la posicion [ " << i << " ] [ " << j << " ]: ";
			cin >> numero;
			celda.RellenarMatriz(numero, i, j);
		}
	}
	
	//filtro para pedir coordenadas apartado a)
	do{
		cout << "\nIntroduce la primera coordenada: ";
		cin  >> i;
		cout << "\nIntroduce la segunda coordenada: ";
		cin >> j;
	}while(i < filas && j < columnas);
	
	cout << "\n\tPara las coordenadas introducidas el digito correspondiente es: " << celda.GetElemento(i, j);
	
	//b) Devolver una fila completa como un objeto de la clase SecuenciaEnteros.
	do{
		cout << "\n¿Que fila desea mostrar?: ";
		cin >> obtener_fila;
	}while(obtener_fila < filas);

	fila = celda.Obtener_fila(obtener_fila);		
	for (i = 0; i < fila.TotalUtilizados(); i++){
		cout << fila.GetNumero(i) << "  ";//saca la fila por pantalla
	}
	
	//c) Añadir una fila entera. La fila será un objeto de la clase SecuenciaEnteros.
	cout << "\nIntroduzca los digitos que tendra la fila nueva: ";

	for (i = 0 ; i < celda.GetColumnasUtilizadas() ; i++){
		cout << "\tDime un valor para Matriz[" << celda.GetFilasUtilizadas() << "][" << i << "]: ";
		cin >> fila_aniadir;
		fila.SetCoeficientes(fila_aniadir);//guarda la fila nueva que se va a introducir como un objeto de la otra clase
	}
	
	//d) comparar dos matrices
	cout << "\nPara la segunda matriz: ";
	do{
		cout << "\nIntroduce el numero de filas: ";
		cin >> filas2;
		cout << "\nIntroduce el numero de columnas: ";
		cin >> columnas2;
	}while(filas2 >= 1 && columnas2 >= 1);
	
	MatrizRectangularEnteros matriz2(filas2, columnas2);
		
	for (i = 0; i < filas2 ; i++){
		for (j = 0 ; j < columnas2 ; j++){
			cout << "Dime un valor para Matriz 2[ " << i << " ][ " << j << " ]: ";
			cin >> numero;
			matriz2.RellenarMatriz(numero, i, j);
		}
	}
	
	//mostrar matriz B
	cout << "\nLa Matriz 2 introducida es:\n\t";
	for (i = 0; i < matriz2.GetFilasUtilizadas(); i++){
		for (j = 0; j < matriz2.GetColumnasUtilizadas(); j++){
			cout << matriz2.GetElemento(i, j) << "  ";
		}
	}
	
	iguales = celda.EsIgual(matriz2);	//pasamos el objetos matriz 2 al metodo
	
	if(iguales){
		cout << "\nLas matrices son iguales";
	}
	else{
		cout << "\nLas matrices son diferentes";
	}
	
	//e)Traspuesta
	cout << "\nLa matriz traspuesta es: \n";
	MatrizRectangularEnteros matriz_traspuesta(celda.GetColumnasUtilizadas(), celda.GetFilasUtilizadas());
	
	matriz_traspuesta = celda.GetTraspuesta();
	
	cout << "\nLa Matriz A Traspuesta es:\n\t";
	for (i = 0; i < filas; i++){
		for (j = 0 ; j < columnas; j++){
			cout << matriz_traspuesta.GetElemento(i, j) << "  ";
		}
		cout << "\n";
	}
	
	//f)Comprobar si una matriz es simetrica
	simetrica = celda.EsSimetrica();
	
	if (simetrica)
		cout << "\nLa Matriz es simétrica\n";
	else
		cout << "\nLa Matriz NO es simétrica\n";
	
	//g) Multiplicar dos matrices.
	
	MatrizRectangularEnteros matriz_producto(celda.GetFilasUtilizadas(), matriz2.GetColumnasUtilizadas());		//precondicion para que se puedan multiplicar
	
	matriz_producto = celda.Multiplicar(matriz2);						//aqui la guarda el producto
	cout << "\nLa Matriz (Matriz 1 * Matriz 2) es: \n";
	for (i = 0 ; i < matriz_producto.GetFilasUtilizadas(); i++){
		for (j = 0 ; j < matriz_producto.GetColumnasUtilizadas(); j++){
			cout << matriz_producto.GetElemento(i, j) << "  ";
		}
	}
	
}
