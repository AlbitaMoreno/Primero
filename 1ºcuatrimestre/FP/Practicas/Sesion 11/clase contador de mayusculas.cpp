/*Sobre el ejercicio 9, cread una clase específica ContadorMayusculas que implemente
los métodos necesarios para llevar el contador de las mayúsculas. Lo que se
pretende es que la clase proporcione los métodos siguientes:
void IncrementaConteo (char mayuscula)
int CuantasHay (char mayuscula)
Modificad el programa principal para que cree un objeto de esta clase y llame a sus
métodos para realizar los conteos de las mayúsculas. Finalmente, hay que imprimir en
pantalla cuántas veces aparece cada mayúscula.*/

#include <iostream>

using namespace std;

class ContadorMayusculas{
	private:
		static const int TAMANIO = 50;
		char cadena[TAMANIO];
		int utilizados;
	public:
		SecuenciaCaracteres()
			:utilizados(0){
		}
	
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
};

int main(){
	char caracter;
	int contador = 0;
	ContadorMayusculas cadena;
	
	cout << "\nPara dejar de introducir caracteres introduzca '.'";
	
	do{
		cout << "nIntroduzca un caracter: ";
		cin >> caracter;
		cadena.SetCoeficientes(caracter);
	}while(caracter != 46 && cadena <= tope);
	
	contador = caracter.ContadorMayusculas();
	
	cout << "\nEn total hay " << contador_mayus << " mayusculas en la cadena.";
}
