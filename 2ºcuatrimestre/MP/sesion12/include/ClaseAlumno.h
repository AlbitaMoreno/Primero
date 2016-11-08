/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2015-2016
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// SESI�N PRACTICA 12
//
// Declaraci�n de la clase Alumno
//
// Fichero: ClaseAlumno.h
//
/***************************************************************************/

#ifndef CLASEALUMNO
#define CLASEALUMNO

/////////////////////////////////////////////////////////////////////////////
// El tipo de dato "Alumno" se emplea para representar los datos de 
// inter�s de cada alumno.

class Alumno{
private:
	char   * apellido_nombre; // Vector din�mico de caracteres (cad. cl�sica)
	char   * DNI;    	// Vector din�mico de caracteres (cad. cl�sica)	
	
	double * notas;		// Vector din�mico de notas
	int 	 num_notas; // N�mero de notas	

	double nota_media;	// Calificaci�n media del alumno
	
public:
	/***********************************************************************/
    // Constructores / destructor
	/***********************************************************************/
	// Constructor sin argumentos: crea una clase vacia.
	Alumno (void);

	/***********************************************************************/
	// Constructor con argumentos: crea un objeto "Alumno" inicializando los 
	// cammpos con los valores suministrados. 
	Alumno (char * el_nombre_completo, char * el_DNI, 
            double * las_notas,int num_notas);
	
	/***********************************************************************/
	// Constructor de copia
	Alumno (const Alumno & otro);
		
	/***********************************************************************/
    // Destructor
    ~Alumno (void);

	/***********************************************************************/
    // M�todos de lectura
	/***********************************************************************/
	// Devuelve el nombre completo de un alumno
	char *  NombreCompletoAlumno (void) const;
	
	/***********************************************************************/
	// Devuelve el DNI de un alumno
	char *  DNIAlumno (void) const;
	
	/***************************************************************************/
	// Devuelve una nota concreta de un alumno
	// PRE: 1 <= n <= num_notas 
	const double Nota (int n) const;

	/***********************************************************************/
	// Devuelve el n�mero de notas registradas de un alumno
	int NumNotasAlumno (void) const;
	
	/***********************************************************************/
	// Devuelve la nota media de un alumno
	double  NotaMediaAlumno (void) const;
	
	/***********************************************************************/
    // M�todos de escritura
	/***********************************************************************/
	// Establece el nombre de un alumno
	void PonNombreCompletoAlumno (char * nombre_completo);
	
	/***********************************************************************/
	// Establece el DNI de un alumno
	void PonDNIAlumno (char * el_DNI);
	
	/***********************************************************************/
	// Establece las notas de un alumno
	void PonNotasAlumno (double * las_notas, int num_notas);
	
	/***********************************************************************/
	// Establece la nota media de un alumno
	void  CalculaNotaMediaAlumno (const double * pesos);

	/***********************************************************************/
	// Operador de asignaci�n
	Alumno & operator =  (const Alumno & otro);
	
	/***********************************************************************/

private:
	/***********************************************************************/
	// Petici�n / liberaci�n de memoria / Copia de datos
	void ReservarMemoria (const Alumno & otro);
	void CopiarDatos (const Alumno & otro);
	void LiberarMemoria (void); 	
};
/////////////////////////////////////////////////////////////////////////////

/***************************************************************************/
// Muestra datos de un alumno  
void PintaAlumno (const Alumno & un_alumno, bool verbose);	

/***************************************************************************/

#endif
 
