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
Implementad los siguientes algoritmos para resolver ester problema:

a) Usad un vector local sin_repetidos en el que almacenamos una única aparición
de cada componente:
Recorrer todas las componentes de la secuencia original
Si la componente NO está en "sin_repetidos", añadirla (al vector "sin_repetidos")
Asignar las componentes de "sin_repetidos" a la secuencia

b) El problema del algoritmo anterior es que usa un vector local, lo que podría suponer
una carga importante de memoria si trabajásemos con vectores grandes.
Por lo tanto, vamos a resolver el problema sin usar vectores locales.
Si una componente está repetida, se borrará de la secuencia. Para borrar una
componente, podríamos desplazar una posición a la izquierda, todas las componentes
que estén a su derecha. Implementad el siguiente algoritmo:
Recorrer todas las componentes de la secuencia original
Si la componente se encuentra en alguna posición
anterior, la eliminamos desplazando hacia la
izquierda todas las componentes que hay a su derecha.*/
 
 #include <iostream>
 using namespace std;
 
class ContadorMayusculas{
	private:
		static const int TAMANIO = 50;
		char cadena[TAMANIO];
		int utilizados;
	public:
		SecuenciaCaracteres()
			:utilizados(0)
	
		int TotalUtilizados(){
			return utilizados;
		}
	
		int Capacidad(){
			return TAMANIO;
		}
	
		void SetCoeficientes(char nuevo){
			if (total_utilizados < TAMANIO){
				vector_privado[utilizados] = nuevo;
				utilizados++;
			}
		}
		int ContadorMayusculas(){
			bool es_mayus;
			int i;
			
			for( i = 0; i <= utilizados - 1; i++){
				es_mayus = ((cadena[i] >= 'A') && (cadena[i] <= 'Z'));
				if(es_mayus){
					contador_mayus++;
				}
			}
			return contador_mayus;
		}
		void EliminaSiExiste(char letra){
			int posicion_elim, i;
			bool eliminar = false;
			//comprobamis si la letra introducida existe y nos quedamos con su posicion para borrarlo
			for( i = 0; i < total_utilizados; i++){
				if (vector_privado[i] == letra){
					posicion_elim = i;
					eliminar = true;
				}
			}
			// borramos el registro de la letra existente
			if (eliminar){
				for (i = posicion_elim; i < total_utilizados; i++){
					vector_privado[i] = vector_privado[i + 1];
				}
				total_utilizados--;
			}
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
	
	cout << "\nIntroduzca el caracter que desea eliminar: ";
	cin >> caracter;
	cadena.EliminarSiExiste(caracter);
	
	for(j = 0; j <= i - 1; j++){
		vector_nuevo = caracter.Elemento(j);
		
		cout << "\nEl vector que tiene ahora es: " << vector_nuevo << "\n\n";
	}
}
