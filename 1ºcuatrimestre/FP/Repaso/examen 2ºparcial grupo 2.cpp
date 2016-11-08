/* Definid la clase ConjutnoOrdenado para que alamcene una secuencia entera sin repetidos
definid los metodos:
-aniede para aniadir un entero ordenado sin repetir
-Union, para calcular la union con otro conjunto, incluir los elemento que este en cualquiera
-Interseccion , elementos comunes.
*/

#include <iostream>
using namespace std;

class ConjuntoOrdenado{
	private:
		static const int TAMANIO = 50;
		int vector_privado[TAMANIO];
		int total_utilizados;
	public:
		ConjuntoOrdenado()
			:total_utilizados(0){
			}
		
		int Capacidad(){
			return TAMANIO;
		}
		
		int TotalUtilizados(){
			return total_utilizados;
		}
		
		int GetElemento(int posicion){
			return vector_privado[posicion];
		}
		
		void Aniade(int nuevo){
			int i;
			bool menor;
			int aux;
			bool existe;
			if(total_utilizados < TAMANIO){
								
				for(i = 0; i < total_utilizados; i++){
					menor = (vector_privado[i] < vector_privado[i + 1]);
					existe = (vector_privado[i] == vector_privado[total_utilizados] ); // como comparamos desde el principio evitamos tener que meter todos los datos y despues voler a recorre el vector comprobandolos
					//ordena los elementos
					if(menor){
						aux = vector_privado[i];
						vector_privado[i] = vector_privado[i + 1];
						vector_privado[i + 1] = aux;
					}
					if(!existe){
						vector_privado[total_utilizados] = nuevo;
						total_utilizados++;
					}
				}
			}	
		}
		
		int GetUnion(ConjuntoOrdenado conjunto){
			int i, j, k;
			int utilizados;
			utilizados = total_utilizados + conjunto.TotalUtilizados();			
			
			int vector_union[utilizados];		
			
			for(i = 0; i < utilizados; i++){
				for(j = 0; j < total_utilizados; j++){
					vector_union[i] = vector_privado[j];
					
					for(k = 0; k < conjunto.TotalUtilizados(); k++){
						vector_union[total_utilizados + 1] = conjunto.GetElemento(k);
					}
				}
				return vector_union[i];	
			}
		}
		
		int GetInterseccion(ConjuntoOrdenado conjunto){
			int i, j, k;
			int utilizados;
			utilizados = total_utilizados + conjunto.TotalUtilizados();
				
			int vector_interseccion[utilizados];
			bool comunes;
			
			for(i = 0; i < utilizados; i++){
				for(j = 0; j < total_utilizados; j++){
					for(k = 0; k < conjunto.TotalUtilizados(); k++){
						comunes = (vector_privado[j] == conjunto.GetElemento(k));
					
						if(comunes){
							vector_interseccion[i] = vector_privado[j];
							vector_interseccion[total_utilizados + 1] = conjunto.GetElemento(k);
						}	
					}
				}
				return vector_interseccion[i];
			}
			
		}
};


int main(){
	ConjuntoOrdenado vector1;
	ConjuntoOrdenado vector2;
	int i;
	int utilizados1;
	int utilizados2;
	int numero;
	int total_utilizados;
	
	cout << "\nConjunto A, para dejar de introducir caracteres pulse '-1'";
	do{
		cout << "\nIntroduzca un entero: ";
		cin >> numero;
		if(numero =! -1){
			vector1.Aniade(numero);
			utilizados1 = vector1.TotalUtilizados();
		}
	}while(numero != -1);
	
	cout << "\nEl conjuto A es: ";
	for(i = 0; i < utilizados1; i++){
		cout << " " << vector1.GetElemento(i);
	}
	
	cout << "\nConjunto B, para dejar de introducir caracteres pulse '-1'";
	do{
		cout << "\nIntroduzca un entero: ";
		cin >> numero;
		if(numero =! -1){
			vector2.Aniade(numero);
			utilizados2 = vector2.TotalUtilizados();
		}
	}while(numero != -1);
	
	cout << "\nEl conjunto B es: ";
	for(i = 0; i < utilizados2; i++){
		cout << " " << vector2.GetElemento(i);
	}
	
	total_utilizados = utilizados1 + utilizados2;
	
	cout << "\nEL resultado de la union de los dos conjuntos es: ";
	
	for(i = 0; i < total_utilizados; i++){
		cout << " " << vector1.GetUnion(vector2);
	}
	
	cout << "\nEl resultado de la interseccion de los dos conjuntos es: ";
	
	for(i = 0; i < total_utilizados; i++){
		cout << " " << vector1.GetInterseccion(vector2);
	}
	
}
