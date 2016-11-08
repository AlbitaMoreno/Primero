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
// Fichero: utils.h
// Declaración e inicialización de constantes globales y declaración de 
// funciones globales de utilidad general 
//
/***************************************************************************/

#ifndef UTILS
#define UTILS

/***************************************************************************/

const double PI = 3.1415926;

/***************************************************************************/
// Función global (asociada a la constante PRECISION_SON_IGUALES) que
// permite que dos números reales muy próximos sean considerados iguales.

const double UMBRAL = 1e-5; // 0.00001


bool SonIguales(double uno, double otro);

/***************************************************************************/

#endif
