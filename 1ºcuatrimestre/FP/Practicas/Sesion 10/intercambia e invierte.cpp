/* Añadid el método IntercambiaComponentes para intercambiar dos componentes
de la secuencia. Por ejemplo, si la secuencia contiene {'h','o','l','a'}, después
de intercambiar las componentes 1 y 3, se quedaría con {'h','a','l','o'}.
¿Qué debería hacer este método si los índices no son correctos?
Añadid otro método llamado Invierte para invertir la secuencia. Si contenía, por
ejemplo, los caracteres {'m','u','n','d','o'}, después de llamar al método
se quedará con {'o','d','n','u','m'}. Implementad el método Invierte llamando
a IntercambiaComponentes.
Imprimid las componentes de la secuencia desde el main, antes y después de llamar
a dicho método. Observad que se repite el mismo tipo de código cuando se imprimen
las componentes de la secuencia. Ya lo arreglaremos en el tema siguiente. */

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
		void IntercambiarComponentes(int posicion1, int posicion2){
			char auxiliar;
			auxiliar = vector_privado[posicion1];
			vector_privado[posicion1] = vector_privado[posicion2];  //En la posicion1 tenemos el valor de dos
			vector_privado[posicion2] = auxiliar;			//auxiliar tenia el valor de posicion1, que ahora equivale a posicion2.
		}
		char InvertirVector(){
			int i = 0;
			int j = total_utilizados - 1;
     		while(i < j){
     			IntercambiarComponentes(i ,j);
     			i++;
     			j--;
     		  }
      }
};

int main(){
	SecuenciaCaracteres secuencia;
	char cadena;
	int i = 0;
	int j;
	int utilizo = 0;
	bool seguir_leyendo;
	bool dato; 
	int posicion_inicial, posicion_final;
	char vector_nuevo;
	char vector_invertido;
		
	do{
		cout << "\nIntroduzca un caracter: ";
		cin >> cadena;
		secuencia.SetCoeficientes(cadena);
		i++;
	}while(cadena != '#' && i<= 49);				//filtro para el terminador
	
	do{
		cout << "\nIntroduzca la posicion del valor que desea intercambiar: ";
		cin >> posicion_inicial;
		cout << "\nIntroduzca la posicion de destino: ";
		cin >> posicion_final;
		secuencia.IntercambiarComponentes(posicion_inicial, posicion_final);
	}while(posicion_inicial <= -1 && posicion_final <= i);
	
	
	for(j = 0; j <= i - 1; j++){
		vector_nuevo = secuencia.Elemento(j);
		
		cout << "\nComponente " << j << " del vector: " << vector_nuevo;
	}
	cout << "\n\nVector invertido\n";
	
	secuencia.InvertirVector();
	
	for(j  = 0; j <= i - 1; j++){
		vector_invertido = secuencia.Elemento(j);
		
		cout << "\nComponente " << j << " del vector: " << vector_invertido;
	}
}
