/*En el primer apartado del ejercicio 7 de la relación de problemas III se pedía eliminar
los repetidos de un objeto de la clase SecuenciaCaracteres usando como dato
auxiliar local un vector clásico con los elementos que no estuviesen repetidos. Recuperad
la solución vista en clase y resolved este mismo apartado usando como dato
auxiliar local un objeto de la propia clase SecuenciaCaracteres*/

#include <iostream>
using namespace std;

class SecuenciaCaracteres{
	private:
		static const int TAMANIO = 50;
		char vector_privado[TAMANIO], vector_sin_repetidos[TAMANIO];
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
		void Aniade(char dato){		// Declara un método para introducir datos al vector1 de la clase
			if (total_utilizados < TAMANIO){
				vector_privado[total_utilizados] = dato;
				total_utilizados ++;
			}
		}
		int EliminarRepetidos(){						// eliminar carácteres repetidos del vector_privado usando otro objeto de la clase como objeto auxiliar
			SecuenciaCaracteres objeto_aux;
			objeto_aux.vector_privado;
			bool VectorSinRep = false;
			
			for (int j = 0 ; j < total_utilizados ; j++){
				for (int i = 0 ; i < objeto_aux.total_utilizados ; i++){
					if (vector_privado [j] == objeto_aux.vector_privado [i]){
						VectorSinRep = true;
					}
				}
				
				if (!VectorSinRep){
					 objeto_aux.vector_privado[objeto_aux.total_utilizados] = vector_privado [j];
					 objeto_aux.total_utilizados ++;
				}
				VectorSinRep = false;
			}
			
			for (int i = 0 ; i < objeto_aux.total_utilizados ; i++){
				vector_privado[i] = objeto_aux.vector_privado[i];
			}
			total_utilizados = objeto_aux.total_utilizados;
			
			return total_utilizados;
		}
	
	
		char Elemento(int indice){
			return vector_privado[indice];
		}
	
		char Visualizar(int dato){			//  leer posiciones del vector1
			if (dato < total_utilizados)
			
			return vector_privado[dato];
		}
	};

int main(){
	char caracter, vector_nuevo;
	SecuenciaCaracteres letras;
	int j;
	int i = 0;
	bool filtro;
	
	cout << "\nPara dejar de introducir caracteres introduzca '#'";
	
	do{
		cout << "\n\nIntroduzca un caracter: ";
		cin >> caracter;
		
		filtro = caracter != 46 && caracter != '#';
		//de esta manera el terminador no lo introduce en la secuencia
		if(caracter != 46 && caracter != '#'){
			letras.Aniade(caracter);
			i++;
		}
	}while(filtro);
	
	//imprimimos el vector original

	cout << "\n\nDatos del vector original" << "\n";
	for(j = 0; j < i; j++){
		cout << letras.Visualizar(j) << "\n";
	}
	
	cout << "\n\nAhora elimino los carácteres repetidos de la secuencia:\n";
	i = letras.EliminarRepetidos();
	
	for (int j = 0 ; j < i; j++){
		cout << letras.Visualizar(j) << "\n";
	}
		//asi seria con un operador de asignacion:
		/*vector_nuevo = caracter.ElementosinRepetir(j);
		cout << vector_nuevo*/
	
}
