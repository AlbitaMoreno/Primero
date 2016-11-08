////////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////

// Cuenta may�sculas

/*
Realizar un programa que vaya leyendo caracteres hasta que se encuentre un punto '.'. 
Queremos contar el n�mero de veces que aparece cada una de las letras may�sculas.
Una posibilidad ser�a leer el car�cter, y despu�s de comprobar si es una may�scula,
ejecutar un conjunto de sentencias del tipo:

	if (letra == 'A')
		contador_mayusculas[0] = contador_mayusculas[0] + 1;
	else if (letra == 'B')
		contador_mayusculas[1] = contador_mayusculas[1] + 1;
	else if (letra == 'C')
		contador_mayusculas[2] = contador_mayusculas[2] + 1;
	else ....

	Sin embargo, este c�digo es muy redundante. Proponed una soluci�n e implementarla.
Para resolver este ejercicio puede usarse o bien un vector cl�sico -array- de enteros,
o bien un objeto de la clase MiVectorEnteros. La idea es que todos los if-else
anteriores los podamos resumir en una �nica sentencia del tipo:

	contador_mayusculas[indice] = contador_mayusculas[indice]+1;

si empleamos un vector cl�sico -array- o bien

	contador_mayusculas.Modifica(indice, contador_mayusculas.Elemento(indice)+1);

si empleamos un objeto de la clase MiVectorEnteros.
*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;
/*
	Vamos a ver tres versiones:
	1. Todo en el main con un vector cl�sico
	2. Todo en el main con un MiVectorEnteros
	3. Definiendo una clase espec�fica que lleve el contador de may�sculas
*/

/*
int main(){
	const int numero_mayusculas = 'Z' -'A' + 1;
	const char TERMINADOR = '.';
	int conteo_mayusculas[numero_mayusculas] = {0};  // Todas se inicializan a cero
	char letra;

	cin >> letra;

	while (letra != TERMINADOR){
		if (isupper(letra)){
			int indice_letra = letra - 'A';
			conteo_mayusculas[indice_letra] = conteo_mayusculas[indice_letra]  + 1;
		}

		cin >> letra;
	}

	cout << "\n\n";

   for (char mayuscula = 'A'; mayuscula <= 'Z' ; mayuscula++){
		string mensaje_num_apariciones;
		int indice_letra = mayuscula - 'A';
		int conteo = conteo_mayusculas[indice_letra];

		if (conteo == 1)
			mensaje_num_apariciones = "vez" ;
		else
			mensaje_num_apariciones = "veces";

		cout << mayuscula << " --> " << conteo << " " << mensaje_num_apariciones << "\n" ;
	}

	cout << "\n";
   system ("pause");
}
*/

// Versi�n con un MiVectorEnteros en vez de un vector cl�sico

/*
class  MiVectorEnteros{
private:
   static  const  int  TAMANIO  =  50;
   int  vector_privado[TAMANIO];
   int  total_utilizados;
public:
   MiVectorEnteros()
      :total_utilizados(0)        
   {    
   }
   int  TotalUtilizados(){
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

	void Modifica (int indice_componente, int nuevo){
		if (indice_componente >= 0  &&  indice_componente < total_utilizados)
			vector_privado[indice_componente] = nuevo;
	}		
};

int main(){
   MiVectorEnteros conteo_mayusculas;   
	char letra;
	const int numero_mayusculas = 'Z' -'A' + 1;
	const char TERMINADOR = '.';
	
	for (int i=0; i<numero_mayusculas; i++)
		conteo_mayusculas.Aniade(0);

	cin >> letra;

	while (letra != TERMINADOR){
		if (isupper(letra)){
			int indice_letra = letra - 'A';
			int cuantos_habia =  conteo_mayusculas.Elemento(indice_letra);
			conteo_mayusculas.Modifica(indice_letra, cuantos_habia + 1);
		}

		cin >> letra;
	}

	cout << "\n\n";

   for (char mayuscula = 'A'; mayuscula <= 'Z' ; mayuscula++){
		string mensaje_num_apariciones;
		int indice_letra = mayuscula - 'A';
		int conteo = conteo_mayusculas.Elemento(indice_letra);

		if (conteo == 1)
			mensaje_num_apariciones = "vez" ;
		else
			mensaje_num_apariciones = "veces";

		cout << mayuscula << " --> " << conteo << " " << mensaje_num_apariciones << "\n" ;
	}

   system ("pause");
}
*/

/*
	En la siguiente versi�n se utiliza una clase espec�fica ContadorMayusculas.
	El programa principal queda mucho m�s "limpio" y sencillo de entender.
*/
class  ContadorMayusculas{
private:
	static  const  int  NUMERO_MAYUSCULAS = 'Z' -'A' + 1;
	int  conteo[NUMERO_MAYUSCULAS];

	int IndiceLetra(char letra){
		return letra - 'A';
	}

public:
	ContadorMayusculas()
	{    
		for (int i=0; i<NUMERO_MAYUSCULAS; i++)
			conteo[i] = 0;
	}

	int  NumeroMayusculas(){
		return  NUMERO_MAYUSCULAS;
	}

	void IncrementaConteo(char mayuscula){
		int indice_mayuscula;

		if (isupper(mayuscula)){
			indice_mayuscula = IndiceLetra(mayuscula);
			conteo[indice_mayuscula] = conteo[indice_mayuscula] + 1; 
		}
	}

	int CuantasHay(char mayuscula){
		return  conteo[IndiceLetra(mayuscula)];
	}	

	string MensajeNumApariciones(char mayuscula){
		string mensaje_num_apariciones;

		int conteo = CuantasHay(mayuscula);

		if (conteo == 1)
			mensaje_num_apariciones = "vez" ;
		else
			mensaje_num_apariciones = "veces";

		return mensaje_num_apariciones;
	}
};


int main(){
	const char TERMINADOR = '.';
	char letra;	
	ContadorMayusculas conteo_mayusculas; 

	cin >> letra;

	while (letra != TERMINADOR){
		conteo_mayusculas.IncrementaConteo(letra);	
		cin >> letra;
	}

	cout << "\n";	

	for (char mayuscula = 'A'; mayuscula <= 'Z'; mayuscula++)
		cout  << mayuscula << " --> " 
		      << conteo_mayusculas.CuantasHay(mayuscula) << " "
		      << conteo_mayusculas.MensajeNumApariciones(mayuscula) << "\n";

	cout << "\n";
	system ("pause");
}

  