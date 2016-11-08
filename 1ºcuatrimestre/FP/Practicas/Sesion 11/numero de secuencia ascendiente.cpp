/*(Examen Septiembre Doble Grado 2013) Defina la clase SecuenciaEnteros análoga
a SecuenciaCaracteres. Defina lo que sea necesario para calcular el número
de secuencias ascendientes del vector. Por ejemplo, el vector {2,4,1,1,7,2,1}
tiene 4 secuencias que son {2,4}, {1,1,7}, {2}, {1}.*/

#include <iostream>
using namespace std;

class SecuenciaNumerica{
private:
	static const int TAMANIO = 50;
	int vector_privado[TAMANIO];
	int total_utilizados;

public:
	SecuenciaNumerica()
		:total_utilizados(0){

		}	
	int TotalUtilizados(){
		return total_utilizados;
	}

	int Capacidad(){
		return TAMANIO;
	}

	void Añadir(int nuevo){
		if (total_utilizados < TAMANIO){
			vector_privado[total_utilizados]= nuevo;
			total_utilizados++;
		}
	}

	int Elemento(int indice){
		return vector_privado[indice];
	}

	int SecuenciaEnteros(){
		int contador = 1;
		int i;
		for( i = 1; i < total_utilizados; i++){
			if (vector_privado[i] < vector_privado[i-1]){
				contador++;
			}
		}
		return contador;
	}
};

int main(){

	int terminador = -1;
	int numero;
	int i;
	SecuenciaNumerica numeros;
	
	do{
		cout << "\nIntroduce una secuencia de numeros (-1 para terminar): \n";
		cin >> numero;
		
		if (numero != terminador){
			numeros.Añadir(numero);
		}	
	}while(numero != terminador);

	nuevo = numeros.SecuenciaEnteros();
	cout << "\n\nEl numero de secuencias ascendentes es: " << nuevo << "\n";
}
