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
// Fichero: PoligonoRegular.h
// Declaración de la clase PoligonoRegular
//
/***************************************************************************/

#ifndef POLIGONO_REGULAR
#define POLIGONO_REGULAR

#include <string>

#include "Punto2D.h"

using namespace std;


/////////////////////////////////////////////////////////////////////////////
// Un polígono regular tiene todos los lados de la misma longitud, y todos
// los ángulos interiores son iguales. Su centro geométrico es el centro de
// la circunferencia circunscrita (la que lo envuelve).
// Supondremos que dos polígonos son distintos si se diferencian o bien en
// sus centros geométricos, o bien en el número de lados o bien en la longitud
// de cualquiera de ellos. Así pues, por ejemplo, no tendremos en cuenta las
// distintas posiciones en el plano que se podrían obtener girando el polígono
// sobre su centro.

class PoligonoRegular
{

private:

	Punto2D centro;     // Centro de la circunferencia circunscrita
 						// que encierra al polígono.

	int 	num_lados; 	// Num. de lados del polígono
	double 	longitud;   // Longitud de cada lado

public:

	/***********************************************************************/
	// Constructores
	/***********************************************************************/

	PoligonoRegular ();

	/***********************************************************************/

	PoligonoRegular (int el_numero_lados, double la_longitud_lado);

	/***********************************************************************/

	PoligonoRegular(int el_numero_lados, double la_longitud_lado,
					Punto2D el_centro);

	/***********************************************************************/
	// Métodos de consulta directa
	/***********************************************************************/

	Punto2D GetCentro ();
	
	/***********************************************************************/

	double GetLongitud ();
	
	/***********************************************************************/

	int GetNumLados ();

	/***********************************************************************/
	// Método de consulta indirecta
	/***********************************************************************/

	double GetRadio ();

	/***********************************************************************/
	// Métodos de cálculo
	/***********************************************************************/

	double Perimetro ();
	
	/***********************************************************************/

	double Area ();

	/***********************************************************************/

	/***********************************************************************/
	// Otros métodos
	/***********************************************************************/

	// Develve un nuevo polígono, inscrito en la misma circunferencia,
	// pero multiplicando por un entero k el número de lados.

	PoligonoRegular MultiplicaNumLados (int k);

	/***********************************************************************/

	bool MayorQue (PoligonoRegular otro);

	/***********************************************************************/
	// Devuelve el área de la región comprendida entre la circunferencia
 	// circunscrita y el polígono (en realidad, la suma de las áreas de
	// las num_lados regiones)

	double AreaEntreCircunferenciaYPoligono ();

	/***********************************************************************/
	// DMuestra un polígono rregular
	
	void Pinta (string msg);

private:

	/***********************************************************************/
	// Devuelve la longitud del lado del nuevo poligono resultado de
	// multiplicar por k el núnero de lados. El radio sigue siendo el mismo
	// porque el nuevo polígono está inscrito en la misma circunferencia.

	double NuevaLongitudLado (int k);

	/***********************************************************************/

};


/////////////////////////////////////////////////////////////////////////////

#endif
