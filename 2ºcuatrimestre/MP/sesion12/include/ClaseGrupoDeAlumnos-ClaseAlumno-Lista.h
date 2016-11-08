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
// Declaraci�n de la clase GrupoDeAlumnos
//
// Fichero: ClaseGrupoDeAlumnos-ClaseAlumno-Lista.h
//
/***************************************************************************/

#ifndef CLASEGRUPODEALUMNOS_CLASEALUMNO_LISTA
#define CLASEGRUPODEALUMNOS_CLASEALUMNO_LISTA
	
#include "ClaseAlumno.h"

/***************************************************************************/
/***************************************************************************/
// Declaraci�n del tipo asociado a cada nodo de la lista

struct Nodo 
{
	Alumno     info;  // Valor guardado en el nodo
	Nodo * sig;   // Puntero al siguiente nodo
};

typedef Nodo * PNodo;
typedef Nodo * Lista;

/***************************************************************************/

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class GrupoDeAlumnos 
{

private:

	Lista datos; // Direcci�n del primer nodo de datos de alumnos. 

	int numero_alumnos;	 // N�mero de alumnos de la clase (=n�mero de nodos).
	// PRE: numero_alumnos >= 0

	double   * pesos; // Puntero al vector din�mico de pesos.	

	int numero_notas;	 // N�mero de calificaciones (=n�mero de pesos).
	// PRE: numero_notas >= 0
		
public:

	/***********************************************************************/
	// Constructor sin argumentos: crea una clase vacia.
	GrupoDeAlumnos (void);

	/***********************************************************************/
	// Constructor con argumentos: crea una clase con "n_alumnos" almunos y 
	// "n_notas" notas. 
	// PRE: n_alumnos > 0
	GrupoDeAlumnos (int n_alumnos, int n_notas);  

	/***********************************************************************/
	// Constructor de copia
	GrupoDeAlumnos (const GrupoDeAlumnos & otro);
		
	/***********************************************************************/
    // Destructor
    ~GrupoDeAlumnos (void);

	/***********************************************************************/
    // Consulta si la clase esta vacia
	bool EstaVacia(void) const;
		
	/***********************************************************************/
	// Devuelve el numero de alumnos
	int  NumeroAlumnos (void) const;
	
	/***********************************************************************/
	// Devuelve el numero de notas
	int  NumeroNotas (void) const;

	/***********************************************************************/
	// Devuelve el valor del peso "n" 
	double Peso (int n) const;

	/***********************************************************************/
	// Permite la lectura de los pesos
	//double * LeePesos (void) const;

	// Inicializa los campos privados "pesos" y "numero_notas" leyendo los 
	// datos de cin. Commprueba la validez de los pesos leidos: deben 
	// sumar 100.0
	// Si no suman 100.0 devuelve FALSE
	bool LeePesosCalificaciones (void); 

	/***********************************************************************/
	// Inicializa los campos privados "datos" y "numero_alumnos" leyendo los 
	// datos de cin 
	void LeeDatosAlumnos (void); 
	
	/***********************************************************************/
	// Calcula la nota media de los alumnos. Se emplean los valores del 
	// campo "pesos" para la ponderaci�n. 	
	void CalculaNotaMedia (void);
	
	/***********************************************************************/
	// Ordena los datos de los alumnos usando como clave la nota media.
	// Se emplea el algoritmo de ordenaci�n por inserci�n.
	void Ordena_por_Insercion (void);

	/***********************************************************************/
	// Busca un alumno con el DNI especificado. Devuelve la posici�n del 
	// primer nodo coincidente, o -1 si no se encuentra.
	/***********************************************************************/
	int Busca (char * DNI);
	
	/***********************************************************************/
    // M�todos de acceso para escribir/leer en una posici�n dada: 
    // NO MODIFICAN EL N�MERO DE NODOS
	/***********************************************************************/
	Alumno & operator [] (int pos);
	Alumno & operator [] (int pos) const;

	/***********************************************************************/
    // M�todos que modifican el tama�o de la lista 
  	// MODIFICAN EL N�MERO DE NODOS
	/***********************************************************************/
	// Aniade (al final) un nuevo elemento
	//
	// PRE: El objeto que se va a a�adir ha reservado su propia memoria 
	// 		para alojar una copia propia de sus datos (nombre, DNI y notas).
	void Aniade (Alumno valor);

    // Borra el primer nodo que contiene el DNI indicado
	void Elimina (char * DNI);

	/***********************************************************************/
	// Inserta un nuevo elemento en la posici�n "pos_insertar"
	// PRE: 1 <= pos_insertar <= tamanio+1
	// El criterio seguido para especificar una posicion ser� : 
	// 1 -> primero, 2 -> segundo,...
	// Nota: Si pos_insertar == tamanio+1, el resultado es id�ntico a la 
	// 		 ejecuci�n del m�todo Aniade()
	//
	// PRE: El objeto que se va a insertar ha reservado su propia memoria 
	// 		para alojar una copia propia de sus datos (nombre, DNI y notas).
	void Inserta (Alumno valor, int pos_insertar);

	/***********************************************************************/
	// Borra el elemento de la posici�n "pos_borrar" 
	// PRE: 1 <= pos_borrar <= tamanio
	// El criterio seguido para especificar una posicion ser� : 
	// 1 -> primero, 2 -> segundo,...
	void Borra (int pos_borrar);
	
	/***********************************************************************/
	//Devuelve el primer nodo de la lista GrupoDeAlumnos
	Lista GetPrimerNodo(void)const;
	
	/***********************************************************************/
	// Operador de asignaci�n
	GrupoDeAlumnos & operator =  (const GrupoDeAlumnos & otro);
		
	/***********************************************************************/

private:
		
	/***********************************************************************/
	// Petici�n / liberaci�n de memoria
	void ReservarMemoria (int num_alumnos, int num_notas);
	void LiberarMemoria (void); 

	/***********************************************************************/
    // Copiar datos desde otro objeto de la clase
	void CopiarDatos (const GrupoDeAlumnos & otro);			
		
};

/////////////////////////////////////////////////////////////////////////////


/***************************************************************************/
/***************************************************************************/
// Muestra los pesos leidos para las ponderaciones de las calificaciones
// precedido del mensaje "msg"
void MuestraPesos (const GrupoDeAlumnos & una_clase, const char * msg);

/***********************************************************************/
// Muestra un listado de una clase de alumnos, precedido del mensaje "msg"
void Listado (const GrupoDeAlumnos & una_clase, const char * msg, bool verbose);

#endif
 
