/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2015-2016
// ALBA MORENO ONTIVEROS
//
// SESIÓN PRACTICA 12
//
// Implementación de la clase alumno
//
// Fichero: ClaseAlumno.cpp
//
/***************************************************************************/

#include <iostream>
#include "ClaseAlumno.h"
#include "ClaseGrupoDeAlumnos-ClaseAlumno-Lista.h"
#include "Utils.h"
#include <cstring>
#include <iomanip>

using namespace std;

/***********************************************************************/
// Constructores / destructor
/***********************************************************************/
// Constructor sin argumentos: crea una clase vacia.
Alumno :: Alumno (void){
	apellido_nombre = DNI = 0;	//apellido nombre y DNI punteros a null
	notas = 0;					//puntero de notas a null
	num_notas = 0;				//no hay numeor de notas
	nota_media = 0.0;			//no hay nota media
}

/***********************************************************************/
// Constructor con argumentos: crea un objeto "Alumno" inicializando los 
// cammpos con los valores suministrados. 
Alumno :: Alumno (char * el_nombre_completo, char * el_DNI, double * las_notas,int numero_notas){

	PonNombreCompletoAlumno(el_nombre_completo);
	PonDNIAlumno(el_DNI);
	PonNotasAlumno(las_notas, numero_notas);
	num_notas = numero_notas;
	nota_media = 0.0;					//la nota media sigue siendo 0, no la he calculado aún
}
	
/***********************************************************************/
// Constructor de copia
Alumno :: Alumno (const Alumno & otro){
	ReservarMemoria(otro);
	CopiarDatos(otro);
}
		
/***********************************************************************/
// Destructor
Alumno :: ~Alumno (void){
	LiberarMemoria();
}

/***********************************************************************/
// Métodos de lectura
/***********************************************************************/
// Devuelve el nombre completo de un alumno
char * Alumno :: NombreCompletoAlumno (void) const{
	return(apellido_nombre);
}

/***********************************************************************/
// Devuelve el DNI de un alumno
char * Alumno :: DNIAlumno (void) const{
	return(DNI);
}
	
/***************************************************************************/
// Devuelve una nota concreta de un alumno
// PRE: 1 <= n <= num_notas 
const double Alumno :: Nota (int n) const{	
		return(notas[n]);
}

/***********************************************************************/
// Devuelve el número de notas registradas de un alumno
int Alumno :: NumNotasAlumno (void) const{
	return(num_notas);
}
	
/***********************************************************************/
// Devuelve la nota media de un alumno
double Alumno :: NotaMediaAlumno (void) const{
	return(nota_media);
}
	
/***********************************************************************/
// Métodos de escritura
/***********************************************************************/
// Establece el nombre de un alumno
void Alumno :: PonNombreCompletoAlumno (char * nombre_completo){
	apellido_nombre = new char [strlen(nombre_completo)];
	
	strcpy(apellido_nombre, nombre_completo);
}
	
/***********************************************************************/
// Establece el DNI de un alumno
void Alumno :: PonDNIAlumno (char * el_DNI){
	DNI = new char [strlen(el_DNI)];
	
	strcpy(DNI,el_DNI);
}
	
/***********************************************************************/
// Establece las notas de un alumno
void Alumno :: PonNotasAlumno (double * las_notas, int num_notas){		
	notas = new double [num_notas];
			
	for (int n = 0; n < num_notas; n++) { 
		notas[n] = las_notas[n];		
	}
}
	

/***********************************************************************/
// Establece la nota media de un alumno
void  Alumno :: CalculaNotaMediaAlumno (const double * pesos){
	
	double suma = 0.0;
 
	for (int i = 0; i < num_notas; i++)			
		suma += notas[i]*pesos[i];

	nota_media = suma / 100.0;	
}

/***********************************************************************/
// Operador de asignación
Alumno & Alumno :: operator =  (const Alumno & otro){
	
	if(this != &otro){	//evitamos la autoasignacion
		LiberarMemoria();
		ReservarMemoria(otro);
		CopiarDatos(otro);
	}
	return(*this);
}
	
/***********************************************************************/

/***********************************************************************/
// Petición / liberación de memoria / Copia de datos
void Alumno :: ReservarMemoria (const Alumno & otro){

	if(otro.NumNotasAlumno() > 0){
		notas = new double [otro.NumNotasAlumno()];
		apellido_nombre = new char [80];	//alumnos con un maximo de 80 caracteres por nombre
		DNI = new char [10];	//el DNI tendra como máximo 10 char
	}
}

void Alumno :: CopiarDatos (const Alumno & otro){
	//copio los campos
	//copio en apellido_nombre el nombre y apellido del otro alumno
	
	ReservarMemoria(otro);
	
	strcpy(apellido_nombre, otro.NombreCompletoAlumno());	
	
	strcpy(DNI, otro.DNIAlumno());
	
	num_notas = otro.NumNotasAlumno();
	nota_media = otro.NotaMediaAlumno();
	
	//copio las notas
	for(int i = 0; i < num_notas; i++){
		notas[i] = otro.Nota(i);
	}
}

void Alumno :: LiberarMemoria (void){
	if(apellido_nombre)
		delete [] apellido_nombre;
	if(DNI)
		delete [] DNI;
	if(notas)
		delete [] notas;
}

// Muestra datos de un alumno  
void PintaAlumno (const Alumno & un_alumno, bool verbose){
	if(verbose){
		cout << endl;
		cout << Linea (80, '-') << endl;
		cout << "ALUMNO " << endl;
		cout << Linea (80, '-') << endl;
		
		cout << un_alumno.DNIAlumno() << endl;
		
		// Mostrar datos del alumno "alumno"
		cout << setw(30)<< left << un_alumno.NombreCompletoAlumno();

		for (int n = 0; n < un_alumno.NumNotasAlumno(); n++) 
			cerr << setw(6) << setprecision(2) << right << un_alumno.Nota(n); 
		}
		
		cout << " --> "; 
		cout << setw(6) << setprecision(2) << right << un_alumno.NotaMediaAlumno();
		cout << endl;
		
		cout << Linea (80, '-') << endl;
		cout << endl;
		
}	

