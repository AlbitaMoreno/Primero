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
// Fichero: Punto2D.cpp
// Definición de la clase Punto2D
//
/***************************************************************************/

#include <string>
#include <cmath>

#include "utils.h"
#include "Punto2D.h"

using namespace std;


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// Métodos de la clase Punto2D

/***********************************************************************/
// Constructor sin argumentos.

Punto2D :: Punto2D (void)
{ }

/***********************************************************************/
// Constructor con argumentos.
//
// Recibe: abscisaPunto y ordenadaPunto, la abscisa y ordenada,
// respectivamente del punto que se está creando.

Punto2D :: Punto2D (double abscisaPunto, double ordenadaPunto)
{
	SetCoordenadas (abscisaPunto, ordenadaPunto);
}

/***********************************************************************/
// Método Set para fijar simultaneamente las coordenadas.
//
// Recibe: abscisaPunto y ordenadaPunto, la abscisa y ordenada,
// respectivamente del punto que se está modificando.

void Punto2D :: SetCoordenadas (double abscisaPunto, double ordenadaPunto)
{
	x = abscisaPunto;
	y = ordenadaPunto;
}

/***********************************************************************/
// Métodos Get para leer las coordenadas

double Punto2D :: GetX (void)
{
	return (x);
}
double Punto2D :: GetY (void)
{
	return (y);
}

/***********************************************************************/
// Calcula si dos puntos son iguales
//
// Recibe: otro, el punto que se quiere comparar con el objeto implícito.
// Devuelve: true, si se consideran iguales los dos objetos.

bool Punto2D :: EsIgual (Punto2D otro)
{
	return (SonIguales(x,otro.x) && SonIguales(y,otro.y));
}

/***********************************************************************/
// Calcula la distancia Euclídea del punto (objeto implícito) a otro que
// se recibe como argumento.
//
// Recibe: otro, el punto respecto al cual que se quiere calcular la
// distancia euclídea.
// Devuelve: la distancia entre los dos puntos.

double Punto2D :: DistanciaEuclidea (Punto2D otro)
{
	double dif_x = pow (x - otro.x, 2);
	double dif_y = pow (y - otro.y, 2);

	return (sqrt(dif_x + dif_y));
}

/***********************************************************************/
// Devuelve un string con la representación textual de un dato Punto2D

string Punto2D :: ToString ()
{
	return ("["+to_string(x)+", "+to_string(y)+"]");
}

/***********************************************************************/

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////


