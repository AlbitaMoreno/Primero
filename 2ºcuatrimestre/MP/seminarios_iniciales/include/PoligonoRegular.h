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
// Fichero: PoligonoRegular.h
// Declaraci�n de la clase PoligonoRegular
//
/***************************************************************************/

#ifndef POLIGONO_REGULAR
#define POLIGONO_REGULAR

#include <string>

#include "Punto2D.h"

using namespace std;


/////////////////////////////////////////////////////////////////////////////
// Un pol�gono regular tiene todos los lados de la misma longitud, y todos
// los �ngulos interiores son iguales. Su centro geom�trico es el centro de
// la circunferencia circunscrita (la que lo envuelve).
// Supondremos que dos pol�gonos son distintos si se diferencian o bien en
// sus centros geom�tricos, o bien en el n�mero de lados o bien en la longitud
// de cualquiera de ellos. As� pues, por ejemplo, no tendremos en cuenta las
// distintas posiciones en el plano que se podr�an obtener girando el pol�gono
// sobre su centro.

class PoligonoRegular
{

private:

	Punto2D centro;     // Centro de la circunferencia circunscrita
 						// que encierra al pol�gono.

	int 	num_lados; 	// Num. de lados del pol�gono
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
	// M�todos de consulta directa
	/***********************************************************************/

	Punto2D GetCentro ();
	
	/***********************************************************************/

	double GetLongitud ();
	
	/***********************************************************************/

	int GetNumLados ();

	/***********************************************************************/
	// M�todo de consulta indirecta
	/***********************************************************************/

	double GetRadio ();

	/***********************************************************************/
	// M�todos de c�lculo
	/***********************************************************************/

	double Perimetro ();
	
	/***********************************************************************/

	double Area ();

	/***********************************************************************/

	/***********************************************************************/
	// Otros m�todos
	/***********************************************************************/

	// Develve un nuevo pol�gono, inscrito en la misma circunferencia,
	// pero multiplicando por un entero k el n�mero de lados.

	PoligonoRegular MultiplicaNumLados (int k);

	/***********************************************************************/

	bool MayorQue (PoligonoRegular otro);

	/***********************************************************************/
	// Devuelve el �rea de la regi�n comprendida entre la circunferencia
 	// circunscrita y el pol�gono (en realidad, la suma de las �reas de
	// las num_lados regiones)

	double AreaEntreCircunferenciaYPoligono ();

	/***********************************************************************/
	// DMuestra un pol�gono rregular
	
	void Pinta (string msg);

private:

	/***********************************************************************/
	// Devuelve la longitud del lado del nuevo poligono resultado de
	// multiplicar por k el n�nero de lados. El radio sigue siendo el mismo
	// porque el nuevo pol�gono est� inscrito en la misma circunferencia.

	double NuevaLongitudLado (int k);

	/***********************************************************************/

};


/////////////////////////////////////////////////////////////////////////////

#endif
