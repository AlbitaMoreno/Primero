/*b) El problema del algoritmo anterior es que usa un vector local, lo que podría suponer
una carga importante de memoria si trabajásemos con vectores grandes.
Por lo tanto, vamos a resolver el problema sin usar vectores locales.
Si una componente está repetida, se borrará de la secuencia. Para borrar una
componente, podríamos desplazar una posición a la izquierda, todas las componentes
que estén a su derecha. Implementad el siguiente algoritmo:
Recorrer todas las componentes de la secuencia original
Si la componente se encuentra en alguna posición
anterior, la eliminamos desplazando hacia la
izquierda todas las componentes que hay a su derecha.
*/

#include <iostream>
 using namespace std;
 
class ContadorMayusculas{
	private:
		static const int TAMANIO = 50;
		char cadena[TAMANIO], vector_sin_repe[TAMANIO];
		int utilizados,  total_utilizados_sin_repetir;
	public:
		SecuenciaCaracteres()
			:utilizados(0), total_utilizados_sin_repetir(0){
			}
	
		int TotalUtilizados(){
			return utilizados;
		}
		
		int GetUtilizadosSinRepetir(){
			return total_utilizados_sin_repetir;
		}
	
		int Capacidad(){
			return TAMANIO;
		}
	
		void SetCoeficientes(char nuevo){
			if (total_utilizados < TAMANIO){
				vector_privado[utilizados] = nuevo;
				utilizados++;
			}
			if (total_utilizados_sin_repetir < TAMANIO){
				bool existe = false;	
				int i;
				for(i = 0; contador < total_utilizados_sin_repetir; i++){				
					if (vector_sin_repe[i] == nuevo){
						existe = true;
					}
				}
				if (!existe){
					vector_sin_repe[total_utilizados_sin_repetir] = nuevo;
					total_utilizados_sin_repetir++;
				}
			}
		}
		char ElementoSinRepetir(int indice){
			return vector_sin_repetidos[indice];
		}		
};

int main(){
	char caracter;
	ContadorMayusculas cadena;
	int j;
	int i = 0;
	char vector_nuevo;
	
	cout << "\nPara dejar de introducir caracteres introduzca '.'";
	
	do{
		cout << "nIntroduzca un caracter: ";
		cin >> caracter;
		cadena.SetCoeficientes(caracter);
		i++;
	}while(caracter != 46 && cadena <= tope);
	
	//imprimimos el vector original

	cout << "\n\nDatos del vector original" << "\n";
	for(j = 0; j <= i - 1; j++){
		cout << letras.Elemento(contador) << "\n";
	}
	
	for(j = 0; j <= i - 1; j++){
		vector_nuevo = caracter.ElementoSinRepetir(j);
		
		cout << "\nEl vector que tiene ahora es: " << vector_nuevo << "\n\n";
	}
}
