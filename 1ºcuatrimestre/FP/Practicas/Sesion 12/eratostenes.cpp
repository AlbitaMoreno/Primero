/*(Examen Septiembre 2012) La criba de Erat�stenes (Cirene, 276 a. C. Alejandr�a,
194 a. C.) es un algoritmo que permite hallar todos los n�meros primos menores que
un n�mero natural dado n.

El procedimiento consiste en escribir todos los n�meros naturales comprendidos entre
2 y n y tachar los n�meros que no son primos de la siguiente manera: 
el primero (el 2) se declara primo y se tachan todos sus m�ltiplos; 
se busca el siguiente n�mero entero que no ha sido tachado, se declara primo y se procede a tachar todos sus m�ltiplos, y
as� sucesivamente. 
El proceso para cuando el cuadrado del n�mero entero es mayor o igual que el valor de n.

El programa debe definir una clase llamada Eratostenes que tendr� tres m�todos:

 void CalculaHasta(int n) para que calcule los primos menores que n.
Este es el m�todo que implementa el algoritmo de Erat�stenes. Cuando se ejecute
el m�todo, se almacenar�n en un vector interno del objeto todos los primos
menores que n. Debe implementarse tal y como se ha indicado anteriormente,
por lo que tendr� que decidir, por ejemplo, c�mo gestiona el tachado de los n�meros.

 int TotalCalculados() que devuelva cu�ntos primos hay actualmente almacenados.

 int Elemento(int indice) para que devuelva el indice-�simo primo.

El programa principal quedar�a de la forma:

Eratostenes primos;
int n = 100; int num_primos;
primos.CalculaHasta(n);
num_primos = primos.TotalCalculados();
for (int i=0; i<num_primos; i++)
cout << primos.Elemento(i) << " ";*/

#include <iostream>

using namespace std;

class Erastotenes{
	private:
		bool vector_primo[100];
		int total_utilizados;
	public:
		Erastotenes()
			:total_utilizados(0){			//El uno es el primer numero primo que hay 
			}
			
		int TotalCalculados(){
			return total_utilizados;
		}
		
		int Elemento(int i){
			return vector_primo[i];
		}
		void SetCoeficientes(int numero){
			if (total_utilizados < 100){
				vector_primo[total_utilizados] = numero;
				total_utilizados++;
			}
		}
		void CalcularHasta(int n){
			int i, j, k;
			
			for(i = 0; i < n; i++){				//incializamos la tabla y la rellenamos con todos los valores
				vector_primo[i] = true;
			}
			
			for(i = 2; i < n; i++){
															//tachar numeros: i* 2, i*3... quitamos los multiplos
				for(j = 2; (i * j) < n; j++){
					vector_primo[i * j] = false;
				}
			}
			
			for(i = 2; i < n; i++){				//recorremos el vector y enviamos a SetCoef s�lo los numeros para los cuales vector_primo es true.
				if(vector_primo[i]){
					cout << i << " ";
					total_utilizados++;
				}	
			}
		}
};

int main(){
	Erastotenes primos;
	int n = 100;
	int num_primos;
	
	cout << "\nLos 100 primeros primos son: \n";
	
	primos.CalcularHasta(n);
	num_primos = primos.TotalCalculados();
	
	cout << "\nHay " << num_primos << " primos.\n";	
}


