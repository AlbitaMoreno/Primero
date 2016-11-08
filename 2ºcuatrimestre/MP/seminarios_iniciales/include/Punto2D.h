/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2015-2016
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// Examen de Febrero 2016
//
// Fichero: Punto2D.h
// Declaraci�n de la clase Punto2D
//
/***************************************************************************/

#ifndef PUNTO_2D
#define PUNTO_2D

#include <string>

using namespace std;


/////////////////////////////////////////////////////////////////////////////
// NOTA: La clase Punto2D que se adjunta proporciona m�s funcionalidad que la
// que requiere el problema que se est� solucionando en este ejercicio.

class Punto2D
{
private:

	// La pareja (x,y) son las coordenadas de un punto en un espacio 2D
	double x = 0;
	double y = 0;

public:

	/***********************************************************************/
	// Constructor sin argumentos.

	Punto2D (void);

	/***********************************************************************/
	// Constructor con argumentos.
	//
	// Recibe: abscisaPunto y ordenadaPunto, la abscisa y ordenada,
	// respectivamente del punto que se est� creando.

	Punto2D (double abscisaPunto, double ordenadaPunto);
	
	/***********************************************************************/
	// M�todo Set para fijar simultaneamente las coordenadas.
	//
	// Recibe: abscisaPunto y ordenadaPunto, la abscisa y ordenada,
	// respectivamente del punto que se est� modificando.

	void SetCoordenadas (double abscisaPunto, double ordenadaPunto);

	/***********************************************************************/
	// M�todos Get para leer las coordenadas

	double GetX (void);

	double GetY (void);

	/***********************************************************************/
	// Calcula si dos puntos son iguales
	//
	// Recibe: otro, el punto que se quiere comparar con el objeto impl�cito.
	// Devuelve: true, si se consideran iguales los dos objetos.

	bool EsIgual (Punto2D otro);

	/***********************************************************************/
	// Calcula la distancia Eucl�dea del punto (objeto impl�cito) a otro que
	// se recibe como argumento.
	//
	// Recibe: otro, el punto respecto al cual que se quiere calcular la
	// distancia eucl�dea.
	// Devuelve: la distancia entre los dos puntos.

	double DistanciaEuclidea (Punto2D otro);
	
	/***********************************************************************/
	// Devuelve un string con la representaci�n textual de un dato Punto2D

	string ToString ();
	
	/***********************************************************************/

};

/////////////////////////////////////////////////////////////////////////////

#endif

