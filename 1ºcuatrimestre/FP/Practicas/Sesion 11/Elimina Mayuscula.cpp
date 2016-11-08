/*Añadid el método EliminaMayusculas para eliminar todas las mayúsculas.
Por ejemplo, después de aplicar dicho método al vector
{'S','o','Y',' ','y','O'}, éste debe quedarse con {'o',' ','y'}.
Un primer algoritmo para resolver este problema sería el siguiente (en ejercicios posteriores
se verán métodos más eficientes):
Recorrer todas las componentes de la secuencia
Si la componente es una mayúscula, borrarla
Queremos implementarlo llamando al método Elimina que se ha definido en el ejercicio
4 de esta relación de problemas:
class SecuenciaCaracteres{
.........
	void EliminaMayusculas(){
		for (int i=0; i<total_utilizados; i++)
			if (isupper(vector_privado[i]))
				Elimina(i);
	}
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
     			IntercambiarComponentes(i, j);
     			i++;
     			j--;
     		  }
      }
	   void EliminarMayusculas(){
			bool es_mayus;
			int i;
			
			for( i = 0; i <= total_utilizados - 1; i++){
				es_mayus = ((vector_privado[i] >= 'A') && (vector_privado[i] <= 'Z'));
				if(es_mayus){
					vector_privado[i] = -1;
					total_utilizados--;
				}
			}
		}
};

int main(){
	SecuenciaCaracteres secuencia;
	char cadena;
	int i = 0;
	int j;
	char vector_nuevo;
		
	do{
		cout << "\nIntroduzca un caracter: ";
		cin >> cadena;
		secuencia.SetCoeficientes(cadena);
		i++;
	}while(cadena != '#' && i <= 49);				
	
	secuencia.EliminarMayusculas();
	
	for(j = 0; j <= i - 1; j++){
		vector_nuevo = secuencia.Elemento(j);
		
		cout << "\nEl vector que tiene ahora es: " << vector_nuevo << "\n\n";
	}
}
