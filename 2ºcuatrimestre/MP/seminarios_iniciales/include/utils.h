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
// Fichero: utils.h
// Declaraci�n e inicializaci�n de constantes globales y declaraci�n de 
// funciones globales de utilidad general 
//
/***************************************************************************/

#ifndef UTILS
#define UTILS

/***************************************************************************/

const double PI = 3.1415926;

/***************************************************************************/
// Funci�n global (asociada a la constante PRECISION_SON_IGUALES) que
// permite que dos n�meros reales muy pr�ximos sean considerados iguales.

const double UMBRAL = 1e-5; // 0.00001


bool SonIguales(double uno, double otro);

/***************************************************************************/

#endif
