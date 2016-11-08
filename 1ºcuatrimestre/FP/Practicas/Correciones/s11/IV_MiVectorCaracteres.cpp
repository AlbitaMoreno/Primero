////////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////

/*
   Elimina Mayúsculas
*/

#include <iostream>
#include <cctype>
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

   char  Elemento(int  indice){
      return  vector_privado[indice];
   }

   void Modifica (int indice_componente, char nuevo){
      if (indice_componente >= 0  &&  indice_componente < total_utilizados)
         vector_privado[indice_componente] = nuevo;
   }


   // Elimina una componente, dada por su posición
	void Elimina (int posicion){
      /*
      Algoritmo:

		   Recorremos de izquierda a derecha toda las componentes
		   que hay a la derecha de la posición a eliminar
			   Le asignamos a cada componente la que hay a su derecha
      */
      if (posicion >= 0 && posicion < total_utilizados){
         int tope = total_utilizados-1;

         for (int i = posicion ; i < tope ; i++)         // i < tope ya que la última asignación  ultimo <- ? no es necesaria
            vector_privado[i] = vector_privado[i+1];

         total_utilizados--;
      }

      // Nota:

      // En vez de usar la asignación
      //    vector_privado[i] = vector_privado[i+1];
      // también podríamos haber puesto lo siguiente:
      //    Modifica(i, Elemento(i+1));
      // Hemos preferido acceder directamente a las componentes con la notación en corchete
      // para aumentar la eficiencia del método Elimina, ya que si el vector es muy grande
      // tendrá que realizar muchos desplazamientos.

      // Además, cuando entramos en la función Elimina, comprobamos con el condicional
      // que los accesos a los índices son correctos.
      // Si usamos el método Modifica, volveríamos a comprobar lo mismo.

      // En general, desde dentro de la clase, los métodos de la clase MiVector
      // accederán directamente a las componentes con la notación corchete
	}

   void EliminaMayusculasIneficiente(){
 		/*
      Algoritmo:
		   Recorrer todas las componentes que hay en el vector
			   Si la componente actual es mayúscula
				   Elimirla (llamar al método Elimina)
			   en otro caso
               Pasar a la siguiente componente

		   Actualizar el número de componentes utilizadas
		*/
      int i;
      i = 0;

      while (i < total_utilizados){
         if (isupper(vector_privado[i]))
            Elimina(i);
         else
            i++;
      }

		
		// El siguiente bucle es incorrecto porque cuando ha borrado una mayúscula, no debe avanzar i. 
      // Al estar dentro de un for, siempre se ejecuta i++, por lo que si hay dos mayúsculas contiguas, 
      // no borra la segunda.
		/*
		for (int i=0; i<total_utilizados; i++)
			if (isupper(vector_privado[i])){
				Elimina(i);
				i--;
		*/
	}

	void EliminaMayusculas(){
		int pos_escritura, pos_lectura;

		/*
      Usamos dos "apuntadores":
            pos_lectura: para ir leyendo las componentes
            pos_escritura: para ir colocando las componentes en el sitio correcto.
      
      Algoritmo:

		   Recorrer todas las componentes que hay en el vector
			   Si la componente actual no es mayúscula
				   ponedla donde indique pos_escritura
			   Avanzar pos_lectura

		   Actualizar el número de componentes utilizadas
		*/

      pos_escritura = 0;
      pos_lectura = 0;

      while (pos_lectura < total_utilizados){
         if (! isupper(vector_privado[pos_lectura])){
            vector_privado[pos_escritura] = vector_privado[pos_lectura];
            pos_escritura++;
         }

         pos_lectura++;
      }

      total_utilizados = pos_escritura;
   }
};

int main(){
   MiVectorCaracteres frase;
   int tope;

	frase.AniadeCadena("asxAABB");
	frase.EliminaMayusculas();

	tope = frase.TotalUtilizados();

	for (int i = 0; i < tope; i++)
      cout  << frase.Elemento(i) << " ";

   cout << "\n\n";
   system ("pause");
}

