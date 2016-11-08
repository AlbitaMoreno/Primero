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
// Fichero: utils.cpp
// Definición de funciones globales
//
/***************************************************************************/

#include <cmath>

#include "utils.h"

using namespace std;

/***************************************************************************/
// Función global (asociada a la constante PRECISION_SON_IGUALES) que
// permite que dos números reales muy próximos sean considerados iguales.

bool SonIguales(double uno, double otro)
{
	return (fabs(uno-otro) <= UMBRAL);
}

/***************************************************************************/

