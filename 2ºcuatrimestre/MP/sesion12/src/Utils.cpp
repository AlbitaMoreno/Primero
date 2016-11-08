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
// Fichero: Utils.cpp
//
/***************************************************************************/

#include <cmath>
#include <cstring>

#include "Utils.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/
// Compone y devuelve una línea de caracteres
// Recibe: 	
//		n, número de caracteres de la línea. 
//		c, el carácter que se empleará en la línea.

char *Linea (int n, char c)
{
	char * la_linea = new char [n];
	memset (la_linea, c, n-1);
	la_linea[n-1] = '\0';
	
	return (la_linea);
}

/***************************************************************************/
/***************************************************************************/
// Compara dos números decimales
//
// Recibe: "uno" y "dos", los dos números a comparar.
//		   "precisión", la precisión deseada en la comparación. 
// Devuelve: true, si se consideran iguales "uno" y "dos". En definitiva, si 
//			 la distancia entre "uno" y "dos" es menor que "precisión".

bool Iguales (double uno, double dos, double precision)
{
	return (fabs(uno-dos) <= precision);	
}

/***************************************************************************/
/***************************************************************************/
 
