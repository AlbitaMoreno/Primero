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
// Fichero: Gestion-Lista.cpp
//
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

#include "ClaseGrupoDeAlumnos-ClaseAlumno-Lista.h"
#include "Utils.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/

int main (int argc, char **argv)
{
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 

	//.......................................................................
	// Comprobar número y validez de argumentos
 
	if (argc > 2) {
		cerr << "Error:    Demasiados parametros." << endl;
		cerr << "Formato:  " << argv[0] << " [-v]" << endl;
		exit (1); 	
	}
	
	bool verbose = false;	
	
	if (argc==2) {
	
		if (strcmp(argv[1],"-v")) {
			cerr << "Error:    argumento incorrecto." << endl;
			cerr << "Formato:  " << argv[0] << " [-v]" << endl;
			exit (2); 		
		}
		else verbose = true;
	}

	//.......................................................................
	// Crear un objeto "GrupoDeAlumnos" vacío

	GrupoDeAlumnos PrimeroB;
	
	//.......................................................................
	// Leer los pesos de las calificaciones y comprobar su validez 

	if (!PrimeroB.LeePesosCalificaciones()) { 
		cerr << "Error: los pesos no suman 100" << endl << endl;
		exit (1); 
	} 

	// Muestra los pesos leidos

	cout << endl << Linea (80, '-') << endl;	
	MuestraPesos (PrimeroB, "Pesos empleados en PrimeroB");
	cout << endl << Linea (80, '-') << endl;	

	//.......................................................................
	// Procesamiento de los datos de alumnos 
	
	// Lee los datos de los alumnos 

	cout << endl << Linea (80, '-') << endl;	
	PrimeroB.LeeDatosAlumnos(); 

	// Mostrar listado 

	cout << endl << Linea (80, '-') << endl;	
	Listado (PrimeroB, "Listado antes de calcular las medias", verbose);
	cout << endl << Linea (80, '-') << endl;	
	
	// Calcular nota media de los alumnos

	PrimeroB.CalculaNotaMedia ();

	// Mostrar listado 

	cout << endl << Linea (80, '-') << endl;	
	Listado (PrimeroB, "Listado despues de calcular las medias", verbose);
	cout << endl << Linea (80, '-') << endl;	

	// Ordenar 

	PrimeroB.Ordena_por_Insercion();
	
	// Mostrar listado 

	cout << endl << Linea (80, '-') << endl;	
	Listado (PrimeroB, "Listado despues de ordenar", verbose);
	cout << endl << Linea (80, '-') << endl;	
	
	return (0);
}

/***************************************************************************/
/***************************************************************************/
 
