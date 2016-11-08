////////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////

/*
   Eliminar los elementos repetidos de un vector de caracteres
*/

/*
Sobre la clase MiVectorCaracteres, a�adir un m�todo EliminaRepetidos que
quite los elementos repetidos, de forma que cada componente s�lo aparezca una
�nica vez. Por ejemplo, si el vector contiene
   {'b','a','a','h','a','a','a','a','c','a','a','a','g'}
despu�s de quitar los repetidos, se quedar�a como sigue:
   {'b','a','h','c','g'}
Implementad los siguientes algoritmos para resolver este problema:

a) Usar un vector local sin_repetidos en el que almacenamos una �nica aparici�n de cada componente:

   Recorrer todas las componentes del vector original
      Si la componente NO est� en el vector sin_repetidos, a�adirla (al vector sin_repetidos)
      Asignar las componentes de sin_repetidos al vector original

b) El problema del algoritmo anterior es que usa un vector local, lo que podr�a suponer una 
carga importante de memoria si trabaj�semos con vectores grandes.
Por lo tanto, vamos a resolver el problema sin usar vectores locales.
Si una componente est� repetida, se borrar� del vector. Para borrar una componente, 
podr�amos desplazar una posici�n a la izquierda, todas las componentes
que est�n a su derecha. El algoritmo quedar�a:

   Recorrer todas las componentes del vector original
      Si la componente se encuentra en alguna posici�n anterior, 
      la eliminamos desplazando hacia la izquierda todas las componentes que hay a su derecha.

c) El anterior algoritmo nos obliga a desplazar muchas componentes cada vez que
encontremos una repetida. Proponed una alternativa (sin usar vectores locales)
para que el n�mero de desplazamientos sea lo menor posible, e implementadla
en el m�todo EliminaRepetidos
*/

#include <iostream>
using namespace std;

class  MiVectorCaracteres{
private:
	static  const  int  TAMANIO  =  50;
	char  vector_privado[TAMANIO];
	int  total_utilizados;
public:
	MiVectorCaracteres()
		:total_utilizados(0)        
	{    
	}

	int  TotalUtilizados(){
		return  total_utilizados;
	}

	void  Aniade(char  nuevo){
		if (total_utilizados  <  TAMANIO){
			vector_privado[total_utilizados]  =  nuevo;
			total_utilizados++;
		}
	}

	void AniadeCadena(string nuevo){
		int tope = nuevo.size();

		for (int i = 0; i < tope; i++)
			Aniade(nuevo[i]);
	}

	char Elemento(int  indice){
		return  vector_privado[indice];
	}

	void Modifica(int indice_componente, char nuevo){
		if (indice_componente >= 0  &&  indice_componente < total_utilizados)
			vector_privado[indice_componente] = nuevo;
	}	

	// Elimina una componente, dada por su posici�n
	void Elimina(int posicion){
		if (posicion >= 0 && posicion < total_utilizados){
			int tope = total_utilizados-1;

			for (int i=posicion ; i<tope ; i++)
				vector_privado[i] = vector_privado[i+1];

			total_utilizados--;    
		}
	}

	int PrimeraOcurrenciaEntre(int pos_izda, int pos_dcha, char buscado){
		int i = pos_izda; 
		bool encontrado = false;

		while (i <= pos_dcha  &&  !encontrado)
			if (vector_privado[i] == buscado)
				encontrado = true;
			else
				i++;

		if (encontrado)
			return i;
		else
			return -1;
	}

	int PrimeraOcurrencia (char buscado){
		return PrimeraOcurrenciaEntre(0, total_utilizados - 1, buscado);
	}

   void EliminaRepetidos_con_VectorLocal(){
      /*
      Recorrer todas las componentes del vector original
         Si la componente NO est� en el vector sin_repetidos,
         a�adirla (al vector sin_repetidos)

      Asignar las componentes de sin_repetidos al vector original
      */
		char sin_repetidos[TAMANIO];     
		bool encontrado_en_repetidos;
		int utilizados_en_repetidos;

		if (total_utilizados > 0){
			sin_repetidos[0] = vector_privado[0];
			utilizados_en_repetidos = 1;

			for (int actual = 1; actual < total_utilizados; actual++){
				encontrado_en_repetidos = false;

				for (int j = 0; j < utilizados_en_repetidos && !encontrado_en_repetidos; j++){
					if (vector_privado[actual] == sin_repetidos[j])
						encontrado_en_repetidos = true;
				}

				if (!encontrado_en_repetidos){
					sin_repetidos[utilizados_en_repetidos] = vector_privado[actual];
					utilizados_en_repetidos++;
				}
			}

			for (int i=0; i<utilizados_en_repetidos; i++)
				vector_privado[i] = sin_repetidos[i];

			total_utilizados = utilizados_en_repetidos;
		}
	}

	void EliminaRepetidosIneficiente(){
		/*
			Recorrer todas las componentes del vector original
				Si la componente es igual a alguna de las componentes que
				hay a su izquierda, eliminarla
		*/ 
		int i = 1, pos_encontrado;

		while (i < total_utilizados){
			pos_encontrado = PrimeraOcurrenciaEntre (0, i-1, vector_privado[i]); 

			if (pos_encontrado != -1)
				Elimina(i);
			else									
				i++;  
		}

		// Importante: i++ debe ir dentro de else. En caso contrario, no funcionar�a
      // correctamente si hubiese dos repetidos consecutivos que hubiese que eliminar
   }


};

int main(){
	MiVectorCaracteres frase;
	int tope;

	frase.Aniade('H');
	frase.Aniade('H');
	frase.Aniade('o');
	frase.Aniade('l');
	frase.Aniade('a');
	frase.Aniade('a');
	frase.Aniade('a');
	frase.Aniade('H');
	
	tope = frase.TotalUtilizados();

	for (int i = 0; i < tope; i++)
		cout  << frase.Elemento(i) << " ";

	frase.EliminaRepetidos();
	tope = frase.TotalUtilizados();          // Hay que recalcular tope ya que el n�mero de componentes utlizadas ha cambiado

	cout << "\n";

	for (int i = 0; i < tope; i++)
		cout  << frase.Elemento(i) << " ";

	system ("pause");
}

