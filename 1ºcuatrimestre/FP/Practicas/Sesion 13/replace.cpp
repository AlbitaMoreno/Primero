/*(Examen Septiembre 2014) Existe un método para la clase string de C++, denominado
replace, que cambia n caracteres de una cadena cad1, empezando en
una determinada posición pos, por los caracteres presentes en una segunda cadena
cad2. La llamada al método es cad1.replace(pos, n, cad2). Ejemplos del
funcionamiento de replace son:

string cad1="Fundamental Programación";
cad1.replace(9,2,"os de la"); 		// "al" -> "os de la"
		// Ahora cad1 tiene "Fundamentos de la Programación"
cad1.replace(12,5,"en"); 				// "de la" -> "en"
		// Ahora cad1 tiene "Fundamentos en Programación"

Puede observar que, dependiendo de la cadena a insertar y de las posiciones especificadas,
la secuencia final puede ser más grande o más pequeña que la original.
Sobre la clase SecuenciaCaracteres construid un método llamado Reemplaza
con la misma funcionalidad que replace (el método no devuelve ningún objeto sino
que modifica los datos de éste).
Restricciones para este ejercicio: No se puede utilizar la clase string en ninguna
parte del programa, debe hacerse lo más eficiente posible y no puede utilizarse un
vector o secuencia auxiliar en el que se vaya almacenando el resultado, es decir, las
modificaciones deben hacerse directamente sobre los datos originales.*/


#include <iostream>
#include <string>
using namespace std;

class SecuenciaCaracteres{	
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
	
		void Aniade(char nuevo){
			if (total_utilizados < TAMANIO){
				vector_privado[total_utilizados]= nuevo;
				total_utilizados++;
			}
		}
	
		char Elemento(int indice){
			return vector_privado[indice];
		}
		
		void Reemplaza(SecuenciaCaracteres objeto, int inicio, int longitud, string texto){
	
			SecuenciaCaracteres secuencia (objeto);		
			//Datos de vector
			for (int i = 0; i < inicio; i++){
				Aniade(secuencia.Elemento(i));
			}
	
			// insertamos la nueva cadena la nueva cadena
			for (int i = 0; i < texto.size(); i++){
				Aniade(texto[i]);
			}
	
			//  añade los elementos que van desde "inicio + longitud" hasta el final
			for (int i = inicio + longitud; i < secuencia.TotalUtilizados(); i++){
				Aniade(secuencia.Elemento(i));
			}		
		}
	
	};

int main(){
	char caracter;
	int i, inicio, longitud;
	char cadena[50];		//vector donde se introduce la cadena nueva que se va a introducir.
	SecuenciaCaracteres letras;

	cout << "\nIntroduce una secuencia de caracteres (# para terminar): \n";

	do{
		cout << "\nIntroduce un caracter: ";
		cin >> caracter;
		letras.Aniade(caracter);
	}while(caracter != 46 &&caracter != '#');

	//imprimimos el vector original

	cout << "\n\nDatos del vector original" << "\n";

	for(i = 0; i < letras.TotalUtilizados(); i++){
		cout << "\n\t";
		cout << letras.Elemento(i);
	}

	cout << "\nDatos para modificar el vector:";
	
	cout <<"\t\nPosicion inicio: ";
	cin >> inicio;
	cout << "\t\nLongitud de la cadena que se va a insertar: ";
	cin >> longitud;
	cin.ignore();
	cout << "\n\tCadena a insertar: ";
	cin.getline(cadena,50);

	letras.Reemplaza(letras, inicio, longitud, cadena);

	cout << "\n\nDatos del vector modificado:" << "\n";

	for(i = 0; i < letras.TotalUtilizados(); i++){
		cout << "\n\t";
		cout << letras.Elemento(i);

	}
}
