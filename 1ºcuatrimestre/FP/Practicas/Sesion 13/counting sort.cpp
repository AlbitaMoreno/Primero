/*(Examen Septiembre 2014) Sobre la clase SecuenciaCaracteres implemente el
algoritmo Counting Sort para ordenar sus valores. El m�todo no modificar� las componentes
del vector privado sino que debe construir una secuencia nueva y devolverla.
El algoritmo funciona de la siguiente forma:

 Calculad los caracteres m�nimo y m�ximo del vector. Por ejemplo, si el vector
contiene
c b b a b c c a g c b g c
el m�nimo es 'a' y el m�ximo 'g'.

 Construid un vector auxiliar de frecuencias con los conteos de todos los caracteres
que hay entre el m�nimo y el m�ximo. Con el ejemplo anterior, el vector de
conteos ser�
2 4 5 0 0 0 2
que corresponden a las frecuencias de las letras que hay entre 'a' y 'g'.

 Recorrer el vector de frecuencias almacenando cada car�cter tantas veces como
indique su frecuencia (2 veces el 'a', cuatro veces el 'b', etc)
a a b b b b c c c c c g g

Haced lo mismo pero parametrizando el m�todo CountingSort para que ordene
s�lo los valores de la secuencia que hay entre un car�cter izquierda y otro car�cter
derecha. Por ejemplo, si izquierda = 'b' y derecha = 'g' el resultado ser�a:
b b b b c c c c c g g*/

#include<iostream>
using namespace std;

class SecuenciaCaracteres{					
	private:										
		static const int TAMANIO = 50;
		char vector_privado[TAMANIO];
		int total_utilizados;
		
	public:
		SecuenciaCaracteres()						
			:total_utilizados = 0{
		}
		
		void SetCoeficientes(char dato){			
			if (total_utilizados < TAMANIO){
				vector_privado[total_utilizados] = dato;
				total_utilizados ++;
			}
		}
		
		int FrecuenciaCaracter(char caracter){			// m�todo para contar cuantas veces se repite un carcater
			int frecuencia = 0;
			int i;
			
			for (i = 0 ; i < total_utilizados ; i++){
				if (caracter == vector_privado[i])
					frecuencia++;
			}
			return frecuencia;
		}
		
		SecuenciaCaracteres CountigSort(char topei, char toped){		// m�todo para ordenar la secuencia de car�cteres entre los topes indicados
			SecuenciaCaracteres secuencia;
			if (topei <= toped){
				int vector[25];
				int total_utilizados2 = 0;
				int i, j;
				
				for (i = topei + 'a'; i <= toped + 'a' ; i++){
					vector[total_utilizados2] = FrecuenciaCaracter(i-'a');
					total_utilizados2 ++;
				}
				
				for (i = 0; i < total_utilizados2; i++){
					for (j = 0; j < vector[i]; j++){
						secuencia.SetCoeficientes(topei);
					}
					topei ++;
				}
				return secuencia;	
			}
		}
		
		int Utilizados(){						// m�todo para devolver el valor de utilizados
			return total_utilizados;
		}
		
		char Visualizar(int dato){			
			if (dato < total_utilizados)
				return vector_privado[dato];
		}
};

int main(){
	SecuenciaCaracteres secuencia;			
	SecuenciaCaracteres secuencia_sort;		//secuencia ordenada
	char caracter;									
	char topei, toped;
	int utilizados;							//  m�todo para guardar las posiciones usadas					
	bool datos, tope, caracteres;
	
	//Introducimos los datos
	cout << "\nPara dejar de introducir caracteres introduzca '#'";
	
	do{
		cout << "\n\nIntroduzca un caracter: ";
		cin >> caracter;
		caracteres = caracter >= 'a' && caracter <= 'z';
		//de esta manera el terminador no lo introduce en la secuencia
		if(caracteres){
			secuencia.SetCoeficientes(caracter);
		}
	}while(caracteres);
	
	datos = secuencia.Utilizados() >= 1;
	//filtro booleano que comprueba que se han introducido datos 
	if (datos){
		cout << "\nLetra de inicio y final para la secuencia ordenada: ";
		cout << "\n\t- Inicio: ";
		cin >> topei;
		cout << "\n\t- Final: ";
		cin >> toped;
		
		tope = topei <= toped;
		//filtro que comprueba que los datos estan dentro del rango del vector
		if (tope){
			secuencia_sort = secuencia.CountigSort(topei, toped);
			utilizados = secuencia_sort.Utilizados();
			
			cout << "\nEsta es la nueva secuencia ordenada:\n";
			
			for (int i = 0; i < utilizados; i++){
				cout << secuencia_sort.Visualizar(i);
			}
		}
		else
			cout << "\nLos topes indicados no son v�lidos\n\n";
	}
	else
		cout << "\nNo has introducido ninguna secuencia\n\n";
}	
