/* A�adid un m�todo EsPalindromo a la clase SecuenciaCaracteres que nos diga
si la secuencia es un pal�ndromo, es decir, que se lee igual de izquierda a derecha
que de derecha a izquierda. Por ejemplo, {'a','b','b','a'} ser�a un pal�ndromo,
pero {'a','c','b','a'} no lo ser�a. Si la secuencia tiene un n�mero
impar de componentes, la que ocupa la posici�n central es descartada, por lo que
{'a','b','j','b','a'} ser�a un pal�ndromo. Incluya un progama principal que
lea una serie de caracteres hasta llegar al terminador '#' y diga si es un pal�ndromo.
Tenga en cuenta la observaci�n de la p�gina anterior sobre la lectura de los caracteres
con cin.get().
*/

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
			int j = total_utilizados-2;
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
};

int main(){
	SecuenciaCaracteres secuencia;
	char cadena;
	int i= 0;
	
	do{
		cout << "\nIntroduzca un caracter: ";
		cin >> cadena;
		secuencia.SetCoeficientes(cadena);
		i++;
	}while(cadena != '#' && i <= 49);

	if(secuencia.EsPalindromo()){
		cout << "\nEs palindromo";
	}
	else{
		cout << "\nNO es palindromo";
	}
}
