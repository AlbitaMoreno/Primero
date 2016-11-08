/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2015-2016
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 1
// EJERCICIO 18
//
// Fichero: I_18_Calificaciones_ArrayStruct.cpp
//
/*
	Este programa gestiona las calificaciones de una clase formada por un
	número indeterminado de alumnos, aunque no superior a CIEN.
	Se calcula la nota media final de cada alumno en base a CUATRO
	calificaciones parciales con diferente peso.

	El programa lee, en primer lugar, los pesos que se asignan a las
	calificaciones parciales (en tantos por cien) y se comprueba que las
	asignaciones son correctas (en el caso de que no lo fueran, se aborta 
	la ejecución del programa.
	A continuación lee (por separado) para cada alumno:
		* apellidos
		* nombre
		* las cuatro calificaciones (cada una por separado)
	La lectura finaliza cuando se introduce el caracter * en la lectura de
	los apellidos de un alumno.

	Una vez almacenados todos los datos leidos, se calcula la nota media 
	ponderada y se muestra un listado de apellidos y nombre, notas, y nota
	media para cada alumno.

	Esta solución usa como representación de los datos un array de
	struct. Cada struct guarda los datos (nombre completo (apellidos+nombre) 
	y cuatro notas de cada alumno).

		struct RegAlumno {
			double notas[NUM_NOTAS];
			char   apellido_nombre[TAM_NOMBRE];		
		};

	Los pesos se almacenan en un vector independiente.
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

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
// Declaraciones globales

const int TAMANIO = 100;   // Num. máximo de alumnos

// El tipo de dato "RegAlumno" se emplea para representar los datos de 
// interés de cada alumno.
// Registro para guardar los datos de cada alumno. 
// Como el conjunto de datos es fijo y heterogéneo se emplea un struct.

const int NUM_NOTAS  =  4; // Número de pesos/calificaciones consideradas
const int TAM_NOMBRE = 80; // Num. máximo de caracteres para apellido+nombre

struct RegAlumno {
	double 	notas[NUM_NOTAS];
 	char 	apellido_nombre[TAM_NOMBRE];		
};

const int TAM_CAD = 80; // Número máximo de caracteres para cadenas

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 


	// Cadena clásica usada para la lectura de todos los datos

	char cad[TAM_CAD];

	//.......................................................................
	// Lectura de los pesos asignados a cada calificación y verificación

	double pesos[NUM_NOTAS];	// Vector de pesos
	
	double peso; 
	double suma_pesos = 0; 

	for (int i=0; i<NUM_NOTAS; i++) {

		cin.getline(cad, TAM_CAD);
		
		peso = atof(cad); 
		pesos[i] = peso; 	

		suma_pesos += peso; 
	}
	
	// Si no suman 100 se aborta la ejecución del programa
	
	if (!Iguales (suma_pesos, 100.0, 0.001)) { 
		cerr << "Error: los pesos no suman 100" << endl;
		exit (1); 
	} 

	cout << endl;
	cout << "Los pesos empleados para ponderar las notas son: " << endl;
	for (int i=0; i<NUM_NOTAS; i++) {
		cout << "\tNota " << setw(2) << i+1 << " : ";
		cout << setw(6) << setprecision(2) << right << pesos[i] << "%" << endl;
	}
	cout << endl; 


	//.......................................................................
	// Datos de alumnos

	// El vector "alumnos" es un array que contiene las notas y los nombres de 
	// los alumnos. Tiene espacio para "TAMANIO" datos de tipo "RegAlumno".
	// Solo se ocuparán "num_alumnos" casillas

	RegAlumno alumnos[TAMANIO];

	int num_alumnos = 0;	// Número de casillas ocupadas
							//PRE: 0 <= num_alumnos <= TAMANIO

	// El vector "calificacion_media" es un array que contiene las notas medias 
	// de los alumnos. Tiene espacio para "TAMANIO" datos. 
	// Solo se ocuparán "num_alumnos" casillas 

	double calificacion_media[TAMANIO] = {0.0};
	

	//.......................................................................
	// Leer datos: apellidos, nombre, y cuatro calificaciones por alumno. 
	
	cin.getline (cad, TAM_CAD); // Lectura adelantada de apellidos


	while (strcmp (cad, "*")) {

		RegAlumno nuevo_alumno;		

		strcpy(nuevo_alumno.apellido_nombre, cad); // Copiar apellidos
		 
		cin.getline (cad, TAM_CAD); // nombre

		strcat(nuevo_alumno.apellido_nombre, ", "); // Añadir ", "
		strcat(nuevo_alumno.apellido_nombre,  cad); // Añadir nombre
	

		// Leer y guardar notas

		for (int i=0; i<NUM_NOTAS; i++) {

			cin.getline(cad, TAM_CAD); // nota i-ésima

			nuevo_alumno.notas[i] = atof(cad);
		}


		// Añadir los datos leidos al vector y actualizar contador
		
		alumnos[num_alumnos] = nuevo_alumno;
		num_alumnos++;
		
		// Se ha terminado de procesar un alumno 

		cin.getline (cad, TAM_CAD); // Lectura adelantada de apellidos

	} // while (strcmp (cad, "*"))

	
	//.......................................................................
	// Calcular calificaciones medias y guardarlas en el vector
	// "calificacion_media".

	for (int alumno=0; alumno<num_alumnos; alumno++) {

		double suma_notas_ponderadas = 0.0; 

		for (int nota=0; nota<NUM_NOTAS; nota++) 

			suma_notas_ponderadas += alumnos[alumno].notas[nota]* pesos[nota];

		calificacion_media[alumno] = suma_notas_ponderadas / 100.0;;
	}

	//.......................................................................
	// Mostrar la lista de los alumnos con todas las calificaciones y su media
	
	cout << endl; 
	cout << "La clase tiene " << num_alumnos << " alumnos." << endl; 
	cout << endl; 

	for (int alumno=0; alumno<num_alumnos; alumno++) {
	
		// Mostrar datos del alumno "alumno"
		cout << setw(3) << right << (alumno+1) << " :  ";
		cout << setw(30)<< left << alumnos[alumno].apellido_nombre;

		for (int nota=0; nota<NUM_NOTAS; nota++) 
			cout << setw(6) << setprecision(2) <<right 
                 << alumnos[alumno].notas[nota];

		cout << " --> "; 
		cout << setw(6) << setprecision(2) <<right<< calificacion_media[alumno];
		cout << endl; 
	}
	cout << endl; 
	
	//.......................................................................

	return (0);
}

/***************************************************************************/
/***************************************************************************/
 
