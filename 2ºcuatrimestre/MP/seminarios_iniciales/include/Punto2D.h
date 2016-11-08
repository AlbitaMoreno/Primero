/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2015-2016
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// Examen de Febrero 2016
//
// Fichero: Punto2D.h
// Declaración de la clase Punto2D
//
/***************************************************************************/

#ifndef PUNTO_2D
#define PUNTO_2D

#include <string>

using namespace std;


/////////////////////////////////////////////////////////////////////////////
// NOTA: La clase Punto2D que se adjunta proporciona más funcionalidad que la
// que requiere el problema que se está solucionando en este ejercicio.

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
	// respectivamente del punto que se está creando.

	Punto2D (double abscisaPunto, double ordenadaPunto);
	
	/***********************************************************************/
	// Método Set para fijar simultaneamente las coordenadas.
	//
	// Recibe: abscisaPunto y ordenadaPunto, la abscisa y ordenada,
	// respectivamente del punto que se está modificando.

	void SetCoordenadas (double abscisaPunto, double ordenadaPunto);

	/***********************************************************************/
	// Métodos Get para leer las coordenadas

	double GetX (void);

	double GetY (void);

	/***********************************************************************/
	// Calcula si dos puntos son iguales
	//
	// Recibe: otro, el punto que se quiere comparar con el objeto implícito.
	// Devuelve: true, si se consideran iguales los dos objetos.

	bool EsIgual (Punto2D otro);

	/***********************************************************************/
	// Calcula la distancia Euclídea del punto (objeto implícito) a otro que
	// se recibe como argumento.
	//
	// Recibe: otro, el punto respecto al cual que se quiere calcular la
	// distancia euclídea.
	// Devuelve: la distancia entre los dos puntos.

	double DistanciaEuclidea (Punto2D otro);
	
	/***********************************************************************/
	// Devuelve un string con la representación textual de un dato Punto2D

	string ToString ();
	
	/***********************************************************************/

};

/////////////////////////////////////////////////////////////////////////////

#endif

