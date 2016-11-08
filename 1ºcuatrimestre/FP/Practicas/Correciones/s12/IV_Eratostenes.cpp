// Eratóstenes

/*
(Examen Septiembre 2012) La criba de Eratóstenes (Cirene, 276 a. C. Alejandría,
194 a. C.) es un algoritmo que permite hallar todos los números primos menores que
un número natural dado n.

El procedimiento “manual” consiste en escribir todos los números naturales compren
didos entre 2 y n y tachar los números que no son primos de la siguiente manera: el
primero (el 2) se declara primo y se tachan todos sus múltiplos; se busca el siguiente
número entero que no ha sido tachado, se declara primo y se procede a tachar todos
sus múltiplos, y así sucesivamente. El proceso para cuando el cuadrado del número
entero es mayor o igual que el valor de n.

El programa debe definir una clase llamada Eratostenes que tendrá tres métodos:

• void CalculaHasta(int n) para que calcule los primos menores que n.
• int TotalCalculados() que devuelva cuántos primos hay actualmente almacenados.
• int Elemento(int indice) para que devuelva el indice-ésimo primo.

El programa principal quedaría de la forma:

Eratostenes primos;
int n = 100; 
int tope;

primos.CalculaHasta(n);
tope = primos.TotalCalculados();

for (int i=0; i<tope; i++)
	cout << primos.Elemento(i) << " ";

	Para almacenar los primos, se usará un dato miembro de tipo vector de la STL.
*/

#include <iostream>

using namespace std;

class Eratostenes{
private:
		static  const  int  TAMANIO  =  50;
		int  vector_privado[TAMANIO];
		int  total_utilizados;

public:

   Eratostenes()
      :total_utilizados(0)
	{
   }

   int  TotalCalculados(){
      return  total_utilizados;
   }

   void  Aniade(int  nuevo){
      if (total_utilizados  <  TAMANIO){
         vector_privado[total_utilizados]  =  nuevo;
         total_utilizados++;
      }
   }

   int  Elemento(int  indice){
      return  vector_privado[indice];
   }


	// Calcula los primos menores que n
	void CalculaHasta(int n){
		/*
      Versión ineficiente:

      Guardar todos los enteros menores que tope en un vector
      Recorrer todos los enteros -i- de dicho vector
         Recorrer todos los enteros -j- mayores que i
            Si j es múltiplo de i, borrarlo físicamente, desplazando
            hacia la izquierda todas las componentes que hay a su derecha.
		*/

		/*
      Versión eficiente:

      Alternativa A. Usando un vector de enteros.
         Guardamos en un vector de enteros todos los enteros menores o iguales que n         
         "Tachar" significará que pondremos a -1 la posición correspondiente.

      Alternativa B. Usamos un vector de bool.
         Si un entero es primo, su correspondiente posición en el vector de bool será true.
         
			Como el primer primo es 2 y los vectores tienen índice 0, la posición dentro del vector
         que corresponde a un entero será (entero - 2).         
			Para no tener que ir repitiendo esta cuenta (entero - 2), podemos hacer una correspondencia
			más intuitiva  entero == índice. El precio a pagar es que 
			las dos primeras no las usaremos (corresponden al 0 y al 1)

         "Tachar" significará que pondremos a false la posición correspondiente.
         Si queremos guardar los primos en un vector, basta con recorrer posteriormente los no tachados.

      Tanto si seguimos la alternativa A, como la alternativa B, 
      la descripción del algoritmo es la misma:

      Recorremos todos los enteros hasta llegar a uno cuyo cuadrado sea mayor que n
         Si el entero no está tachado
            Tachamos todos sus múltiplos 
            (el primer múltiplo es 2*entero y los siguientes se calculan sumando el entero sucesivamente)          

      Implementamos la alternativa B). La alternativa A) es similar.
		*/

	
		// Alternativa A:
		int primos_local[TAMANIO];

		for (int i=0; i<=n; i++)
			primos_local[i] = i;

		for (int entero = 2; entero * entero < n; entero++){			
			if (primos_local[entero] != -1){

				for (int a_tachar = 2*entero; a_tachar <= n; a_tachar = a_tachar + entero)
					primos_local[a_tachar] = -1;
			}
		}

		for (int i=2; i<=n; i++)       
			if (primos_local[i] != -1)
				Aniade(i);


		/*
		// Alternativa B:

		bool es_primo[TAMANIO];
	
		for (int i=0; i<=n; i++)
			es_primo[i] = true;

		for (int entero = 2; entero * entero < n; entero++){			
			if (es_primo[entero]){

				for (int a_tachar = 2*entero; a_tachar <= n; a_tachar = a_tachar + entero)
					es_primo[a_tachar] = false;
			}
		}

		for (int i=0; i<=n; i++)
			if (es_primo[i]){
				Aniade(i);
			}
		*/
	}

};


int main(){
	int tope;
	int total_generados;
	Eratostenes primos;

	cout << "\nIntroduzca un entero: ";
	cin >> tope;

	primos.CalculaHasta(tope);
	total_generados = primos.TotalCalculados();

	for (int i=0; i<total_generados; i++)
		cout << primos.Elemento(i) << " ";
}
