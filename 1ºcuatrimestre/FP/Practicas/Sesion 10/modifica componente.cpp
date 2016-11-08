/* Añadid un método con la cabecera:
void Modifica (int indice_componente, char nuevo)

para que sustituya la componente con índice indice_componente por el valor
nuevo.
Este método está pensado para modificar una componente ya existente, pero no para
añadir componentes nuevas. Por tanto, en el caso de que la componente no esté
dentro del rango correcto, el método no modificará nada.*/

#include <iostream>

using namespace std;

class SecuenciaCaracteres {
	private:
		static const int TAMANIO = 50;
		char vector_privado[TAMANIO];
		int total_utilizados;
	public:
		SecuenciaCaracteres()
			:total_utilizados(0){
		}
		int TotalUtilizados(){
			return total_utilizados;
		}
		int Capacidad(){
			return TAMANIO;
		}
		void SetCoeficientes(char nuevo){
			if (total_utilizados < TAMANIO){
				vector_privado[total_utilizados] = nuevo;
				total_utilizados++;
			}
		}
		char Elemento(int indice){
			return vector_privado[indice];
		}
		bool EsPalindromo(){		
			int i = 0;
			int j = total_utilizados-1;
			bool palindromo;
			while (i  < j){
				palindromo = vector_privado[i] == vector_privado[j];
				i++;
				j--;
				if (!palindromo){
					i = j = 0;
				}
			}
			return palindromo;
		}
		void ModificarVector(int posicion, char nuevo){
				vector_privado[posicion] = nuevo;
		}
};

int main(){
	SecuenciaCaracteres secuencia;
	char cadena;
	int j = 0;
	char nuevo;
	int posicion;
	char vector_nuevo; 
	int utilizo = 0;
	bool seguir_leyendo;
	bool dato; 
	
	do{
		cout << "\nIntroduzca un caracter: ";
		cin >> cadena;
		secuencia.SetCoeficientes(cadena);
		i++;
	}while(cadena != '#' && i <= 49);

	
	cout << "\nPosicion en la quiere introducirlo: ";
	cin >> posicion;
	cout << "\nIntroduzca el valor que quiere introducir: ";
	cin >> nuevo;
	secuencia.ModificarVector(posicion, nuevo);
	
	if(posicion >= utilizo){
		cout << "\nLa posicion introducida esta fuera del rango del vector";
	}
	else{
		for(j = 0; j < utilizo; j++){		//El vector empieza en 0. 
			
			vector_nuevo = secuencia.Elemento(j);
	
			cout << "\nEl vector tiene como elemento: \n" << vector_nuevo;
		
		}
	}
	
}
