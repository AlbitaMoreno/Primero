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
// Fichero: utils.cpp
// Definici�n de funciones globales
//
/***************************************************************************/

#include <cmath>

#include "utils.h"

using namespace std;

/***************************************************************************/
// Funci�n global (asociada a la constante PRECISION_SON_IGUALES) que
// permite que dos n�meros reales muy pr�ximos sean considerados iguales.

bool SonIguales(double uno, double otro)
{
	return (fabs(uno-otro) <= UMBRAL);
}

/***************************************************************************/

