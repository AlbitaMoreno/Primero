/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2015-2016
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// SESIÓN PRACTICA 12
//
// Fichero: Utils.h
//
/***************************************************************************/

#ifndef UTILS
#define UTILS

/***************************************************************************/
// Comentar cuando no se quiera ejecutar en modo DEBUG
//#define DEBUG
/***************************************************************************/

/***************************************************************************/
/***************************************************************************/
// CONSTANTES
/***************************************************************************/
/***************************************************************************/

// Máximo número de caracteres permitido en cadenas. Se supone que apellidos 
// más nombre no superá los 100 (realmente 99) caracteres.  

const int TAM_CAD = 100; 

/***************************************************************************/
/***************************************************************************/
// PROTOTIPOS DE LAS FUNCIONES
/***************************************************************************/
/***************************************************************************/

/***************************************************************************/
// Compone y devuelve una línea de "n" caracteres "c".

char * Linea (int n, char c);

/***************************************************************************/
// Compara dos números decimales
//
// Recibe: "uno" y "dos", los dos números a comparar.
//		   "precisión", la precisión deseada en la comparación. 
// Devuelve: true, si se consideran iguales "uno" y "dos". En definitiva, si 
//			 la distancia entre "uno" y "dos" es menor que "precisión".

bool Iguales (double uno, double dos, double precision);

/***************************************************************************/

#endif
 
