/*Se quiere calcular la moda de una secuencia de caracteres, es decir, el carácter que
más veces se repite. Por ejemplo, si la secuencia fuese
{'l','o','s',' ','d','o','s',' ','c','o','f','r','e','s'}
los caracteres que más se repiten son 'o' y 's' con un total de 3 apariciones. La
moda sería cualquiera de ellos, por ejemplo, el primero encontrado 'o'. Sobre la
clase SecuenciaCaracteres, se pide construir el método Moda que devuelva un
struct del tipo:

struct FrecuenciaCaracter{
	char caracter;
	int frecuencia;
}
en el que el campo caracter contendrá el carácter en cuestión ('o') y en el campo
frecuencia el conteo de la moda (3).*/

#include <iostream>
using namespace std;


struct FrecuenciaCaracter{
	char caracter;		
	int frecuencia;

};

class SecuenciaCaracteres{
	
	private:
		static const int TAMANIO = 50;
		char vector_privado[TAMANIO], vector_sin_repetidos[TAMANIO];
		int total_utilizados, total_utilizados_sin_repetidos;
		static const int SIZE = 122;  //  122 es el valor ascii que le corresponde a la z minuscula, es el tope.
		int vector[SIZE];

	public:
		SecuenciaCaracteres()
			:total_utilizados(0), total_utilizados_sin_repetidos(0){

				for(int i = 0; i < SIZE	; i++ ){
					vector[i] = 0;

				}
			}

		int TotalUtilizados(){
			return total_utilizados;
		}

		int Capacidad(){
			return TAMANIO;
		}

		void Aniade(char nuevo){
			if (total_utilizados < TAMANIO){
				vector_privado[total_utilizados]= nuevo;
				total_utilizados++;
			}
		}

		char Elemento(int indice){
			return vector_privado[indice];
		}

		void Conteo( char letra){
			int indice = letra;
			vector[indice]++;
		}

		FrecuenciaCaracter Moda(){
			FrecuenciaCaracter frecuencia_caracter;		//pertenece a la clase struct, solo almacena objetos
			frecuencia_caracter.frecuencia = 0;
			for(int i = 0; i < total_utilizados; i++){
				char caracter = vector_privado[i];
				Conteo(caracter);
			}
		
			for(int i = 65; i < SIZE; i++){   // se recorren solo los indices correspondientes a las letras mayusculas y minusculas
				if (vector[i] > frecuencia_caracter.frecuencia) {
					frecuencia_caracter.frecuencia = vector[i];		//almacena en la clase strcut la frecuencia y el caracter que se repite
					frecuencia_caracter.caracter = i;
				}
			}
			return frecuencia_caracter;
		}
};

struct Moda{
	char caracter;
	int frecuencia;
	
	SecuenciaCaracteres Caracter(){
		SecuenciaCaracteres caracter;
		caracter.Moda();
	}
};

int main(){
	char caracter;
	SecuenciaCaracteres letras;
	
	cout << "\nIntroduce una secuencia de caracteres (# para terminar): \n";
	//filtro
	while(caracter != '#'){
		caracter = cin.get();
		cin.ignore();
		if (caracter != '#'){
			letras.Aniade(caracter);
		}	
	}
	
   FrecuenciaCaracter objetoDevuelto (letras.Moda());		//crea el objeto de la clase struct donde se han ido almacenando los objetos frecuencia y caracter de la clase SecuenciaCaracteres

	cout << "\n\nEl caracter " << objetoDevuelto.caracter << " ha sido introducido " << objetoDevuelto.frecuencia << " veces ";
}

