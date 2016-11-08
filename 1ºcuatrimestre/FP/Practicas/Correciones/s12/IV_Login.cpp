// Login automático

/*
Se está diseñando un sistema web que recolecta datos
personales de un usuario y, en un momento dado, debe sugerirle un nombre de
usuario (login). Dicho login estará basado en el nombre y los apellidos; en 
concreto estará formado por los N primeros caracteres de cada nombre y apellido
(en minúsculas, unidos y sin espacios en blanco). Por ejemplo, si el nombre es
"Antonio Francisco Molina Ortega" y N=2, el nombre de usuario sugerido
será "anfrmoor".
Debe tener en cuenta que el número de palabras que forman el nombre y los apellidos
puede ser cualquiera. Además, si N es mayor que alguna de las palabras que
aparecen en el nombre, se incluirá la palabra completa. Por ejemplo, si el nombre
es "Ana CAMPOS de la Blanca" y N=4, entonces la sugerencia será
"anacampdelablan" (observe que se pueden utilizar varios espacios en blanco
para separar palabras).
Implemente la clase Login que tendrá como único dato miembro el tamaño N. Hay
que definir el método Codifica que recibirá una cadena de caracteres (tipo string)
formada por el nombre y apellidos (separados por uno o más espacios en blanco) y
devuelva otra cadena con la sugerencia de login.
*/

#include <iostream>
#include <string>
using namespace std;


class Login{
private:
	int num_caracteres_a_coger;
public:
	Login (int numero_caracteres_a_coger)
		:num_caracteres_a_coger(numero_caracteres_a_coger)
	{
	}
	string Codifica(string nombre_completo){
		/*
			Primera versión.
				Este algoritmo está diseñado para ir
				recorriendo el vector con varios bucles secuenciales
				que van comprobando las condiciones que se exigen.

			Recorrer con un índice inicio la cadena
				Saltar todos los espacios en blanco a partir de inicio 
				Añadir al login las n primeras letras de la palabra actual
					(sin salirnos de la cadena y hasta que lleguemos a un blanco)
				Saltar al final de la palabra actual y colocar ahí el índice inicio
		*/
		/*
		int inicio, actual;
		int final = nombre_completo.size();
		string login;
		inicio = 0;

		while (inicio < final){			
			while (inicio < final && nombre_completo[inicio] == ' ')
				inicio++;

			actual = inicio;

			while (actual < final 
				    && actual - inicio < num_caracteres_a_coger 
					 && nombre_completo[actual] != ' '){

				login.push_back(tolower(nombre_completo[actual]));
				actual++;
			}

			while (actual < final && nombre_completo[actual] != ' ')
				actual++;

			inicio = actual;
		}
		*/

		/*	
			Segunda versión.
				Este algoritmo está diseñado centrándose en la componente 
				actual que en cada momento se está procesando.

				Usamos un contador de número de letras almacenadas
				en cada momento en el login (aniadidos)

				Recorrer con un índice i la cadena
					Si la componente i es un blanco, reseteamos aniadidos
					En otro caso, añadimos la letra actual, siempre
						y cuando no se hayan añadido ya n letras
		*/
		
		int final = nombre_completo.size();
		string login;
		int aniadidos = 0;

		for(int i = 0; i < final; i++){
			if (nombre_completo[i] == ' ')
				aniadidos = 0;
			else if (aniadidos < num_caracteres_a_coger){
				login.push_back(tolower(nombre_completo[i]));
				aniadidos++;
			}
		}
		
		return login;
	}
};



int main(){
	Login login_automatico(3);
	string codificada;
	codificada = login_automatico.Codifica("   Halo  Adi   ");
	cout << codificada << "\n";
   codificada = login_automatico.Codifica("Halo   Adi");
	cout << codificada << "\n";

   cout << "\n\n";
	system("pause");
}
