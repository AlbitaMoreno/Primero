/*Sobre la clase SecuenciaCaracteres:

a)implementa el metodo eliminar para borra eficientemente todas las posiciones indicadas de un objeto de la clase 
SecuenciaEnteros. pj.: si la SecCaract contiene FUNDAMENTOS  y la SecEnte contiene 2 5 3 --> FUAMENTOS

b)crear un programa sencillo que utilice dicho metodo.
*/

#include <iostream>
using namespace std;

class SecuenciaEnteros{
	private:
		static const int TAMANIO = 50;
		int vector_posiciones[TAMANIO];
		int total_utilizados;
	public:
		SecuenciaEnteros()
			:total_utilizados(0)
		{}
		
		int GetCapacidad(){
			return TAMANIO;
		}
		
		int TotalUtilizados(){
			return total_utilizados;
		}
		
		void SetCoeficientes(int nuevo){
			if(total_utilizados < TAMANIO){
				vector_posiciones[total_utilizados] = nuevo;
				total_utilizados++;
			}
		}
		
		int GetElemento(int posicion){
			return vector_posiciones[posicion];
		}	
};

class SecuenciaCaracteres{
	private:
		static const int TAMANIO = 50;
		char vector_privado[TAMANIO];
		int total_utilizados;
	public:
		SecuenciaCaracteres()
			:total_utilizados(0)
			{}
	
		int GetCapacidad(){
			return TAMANIO;
		}
	
		int TotalUtilizados(){
			return total_utilizados;
		}
	
		void SetCoeficientes(char nuevo){
			if(total_utilizados <= TAMANIO){
				vector_privado[total_utilizados] = nuevo;
				total_utilizados++;
			}
		}
	
		char GetElemento(int posicion){
			return vector_privado[posicion];
		}	
				
		void EliminarPosiciones(SecuenciaEnteros posiciones){
			int i, j;
			
			for(i = 0; i < total_utilizados; i++){
				for (j = 0; j < posiciones.TotalUtilizados(); j++){
					if(j == posiciones.GetElemento(j)){
						vector_privado[j] = -1;
						total_utilizados--;
					}
				}
			}
		}
};

int main(){
	SecuenciaCaracteres letras;
	SecuenciaEnteros posiciones;
	char caracter;
	int numero;
	int utilizados = 0;
	int i;
	
	cout << "\nIntroducir caracteres, para terminar pulsar '#'";

	do{
		cout << "\nIntroduce un caracter: ";
		cin >> caracter;
		if(caracter != '#'){
			letras.SetCoeficientes(caracter);
			utilizados++;
		}
	}while(caracter != '#');
	
	cout << "\n\tHa introducido la siguiente cadena:\n";
	
	for(i = 0; i < utilizados; i++){
		cout << " " << letras.GetElemento(i);
	}
	
	cout << "\n\nIntroduzca las posiciones de los elementos que desea borrar,\npara terminar pulsar '-1'";
	
	do{
		cout << "\n\nIntroduce una posicion: ";
		cin >> numero;
		if(numero != -1){
			posiciones.SetCoeficientes(numero);
		}
	}while(numero != -1);
	
	
	cout << "\n\nLa cadena resultante es: ";
	
	for(i = 0; i < utilizados; i++){
		letras.EliminarPosiciones(posiciones);
		cout << " " << letras.GetElemento(i);
	}
}
