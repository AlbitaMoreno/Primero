/*
(Examen Febrero 2013) Se est� dise�ando un sistema web que recolecta datos
personales de un usuario y, en un momento dado, debe sugerirle un nombre de
usuario (login). Dicho login estar� basado en el nombre y los apellidos; en concreto
estar� formado por los N primeros caracteres de cada nombre y apellido
(en min�sculas, unidos y sin espacios en blanco). Por ejemplo, si el nombre es
"Antonio Francisco Molina Ortega" y N=2, el nombre de usuario sugerido
ser� "anfrmoor".
Debe tener en cuenta que el n�mero de palabras que forman el nombre y los apellidos
puede ser cualquiera. Adem�s, si N es mayor que alguna de las palabras que
aparecen en el nombre, se incluir� la palabra completa. Por ejemplo, si el nombre
es "Ana CAMPOS de la Blanca" y N=4, entonces la sugerencia ser�
"anacampdelablan" (observe que se pueden utilizar varios espacios en blanco
para separar palabras).
Implemente la clase Login que tendr� como �nico dato miembro el tama�o N. Hay
que definir el m�todo Codifica que recibir� una cadena de caracteres (tipo string)
formada por el nombre y apellidos (separados por uno o m�s espacios en blanco) y
devuelva otra cadena con la sugerencia de login.
class Login{
private:
int num_caracteres_a_coger;
public:
Login (int numero_caracteres_a_coger)
:num_caracteres_a_coger(numero_caracteres_a_coger)
{ }
string Codifica(string nombre_completo){
......
}
};
Los �nicos m�todos que necesita usar de la clase string son size y
push_back. Para probar el programa o bien lea una cadena de caracteres con
getline(cin, cadena); o bien use directamente literales string en el main.
Dificultad Media.
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Login{

private:

	int num_caracteres_a_coger;

public:

	Login(int n)
	: num_caracteres_a_coger(n){
	}

	string Codifica(string nombre_completo){

		string sugerido;
		int cogidos = 0;
		int i;
		
		for(i = 0; i <= nombre_completo.size(); i++){
			if(nombre_completo[i] != ' ' && cogidos < num_caracteres_a_coger){
				sugerido.push_back(tolower(nombre_completo[i]));
				cogidos++;
			}

			else if (nombre_completo[i] == ' '){
				cogidos = 0;
			}
		}
		return sugerido;
	}
};

int main(){

	char nombre[100];
	int num_caracteres;

	cout << "\n\nIntroduce un nombre: ";
	cin.getline(nombre, 100);
	cout << "introduce caracteres a coger: ";
	cin >> num_caracteres;
	Login usuario(num_caracteres);
	cout << "\n\nEl nombre de usuario sugerido es: " << usuario.Codifica(nombre) << "\n\n";

}
