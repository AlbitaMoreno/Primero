/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2015-2016
// ALBA MORENO ONTIVEROS
//
// SESIÓN PRACTICA 12
//
// Definición de la clase GrupoDeAlumnos
//
// Fichero: ClaseGrupoDeAlumnos-ClaseAlumno-Lista.cpp
/***************************************************************************/

#include <iostream>
#include "ClaseGrupoDeAlumnos-ClaseAlumno-Lista.h"
#include "ClaseAlumno.h"
#include "Utils.h"
#include <iomanip>
#include <cstring>
#include <cstdlib>

using namespace std;

/***********************************************************************/
// Constructor sin argumentos: crea una clase vacia.
GrupoDeAlumnos :: GrupoDeAlumnos (void){
	datos = 0;
	pesos = 0;
	numero_alumnos = 0;
	numero_notas = 0;
}

/***********************************************************************/
// Constructor con argumentos: crea una clase con "n_alumnos" almunos y 
// "n_notas" notas. 
// PRE: n_alumnos > 0
GrupoDeAlumnos :: GrupoDeAlumnos (int n_alumnos, int n_notas){
	if(n_alumnos > 0){
		ReservarMemoria(n_alumnos,n_notas);
		numero_alumnos =  n_alumnos;
		numero_notas = n_notas;		
	}
}

/***********************************************************************/
// Constructor de copia
GrupoDeAlumnos :: GrupoDeAlumnos (const GrupoDeAlumnos & otro){
	ReservarMemoria(otro.NumeroAlumnos(), otro.NumeroNotas());
	CopiarDatos(otro);
}
	
/***********************************************************************/
// Destructor
GrupoDeAlumnos :: ~GrupoDeAlumnos (void){
	LiberarMemoria();
}

/***********************************************************************/
// Consulta si la clase esta vacia
bool GrupoDeAlumnos :: EstaVacia(void) const{
	return(!datos);
}
		
/***********************************************************************/
// Devuelve el numero de alumnos
int  GrupoDeAlumnos :: NumeroAlumnos (void) const{
	return(numero_alumnos);
}
	
/***********************************************************************/
// Devuelve el numero de notas
int  GrupoDeAlumnos :: NumeroNotas (void) const{
	return(numero_notas);
}

/***********************************************************************/
// Devuelve el valor del peso "n" 
double GrupoDeAlumnos :: Peso (int n) const{
		return(pesos[n]);
}

/***********************************************************************/
// Permite la lectura de los pesos
//double * LeePesos (void) const;

// Inicializa los campos privados "pesos" y "numero_notas" leyendo los 
// datos de cin. Commprueba la validez de los pesos leidos: deben 
// sumar 100.0
// Si no suman 100.0 devuelve FALSE

bool GrupoDeAlumnos :: LeePesosCalificaciones (void){
	cout << endl;
	cout << Linea (80, '-') << endl;	
	
	// Lectura de los pesos asignados a cada calificación y comprobación.  

	cout << "LEYENDO PESOS" << endl; 	
	
	char cad[80];
			
	cin.getline(cad, 80); // número de pesos 
	numero_notas = atoi(cad);
	
	// Lectura y almacenamiento de los pesos 	
	pesos = new double [numero_notas];
	
	for (int i = 0; i < numero_notas; i++) {
		cin.getline(cad, 80);   // peso i-ésimo
		pesos[i] = atof(cad);
	}
	
	//compruebo si son correctos
	double suma_pesos = 0; 

	for (int i = 0; i < numero_notas; i++){ 
		suma_pesos = suma_pesos + pesos[i];
	}	 

	return (Iguales (suma_pesos, 100.0, 0.001));
}

/***********************************************************************/
// Inicializa los campos privados "datos" y "numero_alumnos" leyendo los 
// datos de cin 
void GrupoDeAlumnos :: LeeDatosAlumnos (void){
	cout << "LEYENDO DATOS" << endl;
	
	int TAM_CAD = 100;
	const char *TERMINADOR = "*";
	
	char cad[TAM_CAD];	// Cadena clásica usada para la lectura de los datos
	
	cin.getline (cad, TAM_CAD);
	
	
	while(strcmp(cad, TERMINADOR)){
		
		//	1) Reservar memoria para el DNI, y copiarlo. 

		char * DNI = new char[strlen(cad)+1];
		
		strcpy (DNI, cad);		

		//	2) Reservar memoria para el nombre y apellidos, y copiarlo. 

		cin.getline (cad, TAM_CAD); // leer apellidos
		
		//creo el vector dinamico del apellido
		
		char * apellido = new char[strlen(cad)+1];
		
		strcpy (apellido, cad); // Copiar apellidos

		cin.getline (cad, TAM_CAD); // leer nombre
		
		//creo el vector dinamico del nombre
		
		char * nombre = new char[strlen(cad)+1];
		strcpy (nombre, cad); // Copiar nombre
		
		//creo el vector dinamico donde junto apellido y nombre
		char * el_apellido_nombre = new char[(strlen(apellido)+2+strlen(nombre)+1)];
	
		strcpy(el_apellido_nombre, apellido); // Copiar apellidos
		strcat(el_apellido_nombre, ", ");     // Anadir ", "
		strcat(el_apellido_nombre, nombre);   // Añadir nombre
		
		
		// 3)Pongo las notas del alumno

		double * notas = new double[numero_notas]; 		
		
		for (int n=0; n < numero_notas; n++) { 

			cin.getline(cad, TAM_CAD); // nota n-ésima
			notas[n] = atof(cad);					
		}
		
		
		Alumno nuevo_alumno(el_apellido_nombre,DNI,notas,numero_notas);
			
		Aniade(nuevo_alumno);		
		numero_alumnos++;
		
		cin.getline (cad, TAM_CAD);	
	}
} 
	
/***********************************************************************/
// Calcula la nota media de los alumnos. Se emplean los valores del 
// campo "pesos" para la ponderación. 	
void GrupoDeAlumnos :: CalculaNotaMedia (void){
	PNodo aux = datos;

	while(aux){
		//el campo info tiene un objeto del tipo alumno, por tanto puedo acceder a los métodos de la clase alumno
		aux->info.CalculaNotaMediaAlumno(pesos);
		aux = aux->sig;
	}
}
	
/***********************************************************************/
// Ordena los datos de los alumnos usando como clave la nota media.
// Se emplea el algoritmo de ordenación por inserción.
void GrupoDeAlumnos :: Ordena_por_Insercion (void){
	
	PNodo anterior = datos;
	PNodo siguiente = datos->sig;
	PNodo senial = datos;

	Alumno aux;

	for (int i = 1; i < numero_alumnos; i++) {
		anterior = senial;
		siguiente = senial->sig;

		while(siguiente->info.NotaMediaAlumno() > anterior->info.NotaMediaAlumno() && siguiente->sig) {
			aux = siguiente->info;
			siguiente->info = anterior->info;
			anterior->info = aux;

			anterior = anterior->sig;
			siguiente = siguiente->sig;
		}

		senial = senial->sig;
	}	
}

/***********************************************************************/
// Busca un alumno con el DNI especificado. Devuelve la posición del 
// primer nodo coincidente, o -1 si no se encuentra.
/***********************************************************************/
int GrupoDeAlumnos :: Busca (char * DNI){
	int posicion = 0;
	bool sigue = true;

	PNodo aux = datos;

	while(aux && sigue){
		if(!strcmp(aux->info.DNIAlumno(),DNI)){
			sigue = false;
		}
		else{
			posicion++;
			aux = aux->sig;
		}
	}

	if(sigue ==true)	//si cuando acaba el while sigue siendo true, entonces es porque no ha encontrado el DNI
		posicion = -1;

	return(posicion);

}
	
/***********************************************************************/
// Métodos de acceso para escribir/leer en una posición dada: 
// NO MODIFICAN EL NÚMERO DE NODOS
/***********************************************************************/
Alumno & GrupoDeAlumnos :: operator [] (int pos){
	PNodo aux = datos;
	    
	for (int i = 0; i < pos; i++)
		aux = aux->sig;

	return (aux->info);
}

Alumno & GrupoDeAlumnos :: operator [] (int pos) const{
	PNodo aux = datos;
	    
	for (int i = 0; i < pos; i++)
		aux = aux->sig;
	
	return (aux->info);
}

/***********************************************************************/
    // Métodos que modifican el tamaño de la lista 
 	// MODIFICAN EL NÚMERO DE NODOS
	/***********************************************************************/
	// Aniade (al final) un nuevo elemento
	//
	// PRE: El objeto que se va a añadir ha reservado su propia memoria 
	// 		para alojar una copia propia de sus datos (nombre, DNI y notas).

void GrupoDeAlumnos :: Aniade (Alumno valor){
	// Crear un nuevo (último) nodo y rellenar sus campos
	PNodo nuevo = new Nodo;
	
	nuevo->info = valor;
	nuevo->sig = 0;

	if (datos) {  // La lista no está vacía

		// Buscar el último nodo
		PNodo p = datos;
		
		while(p->sig){
			p = p->sig;
		}
					
		p->sig = nuevo;
	}

	else { // La lista estaba vacía
		datos = nuevo; 
	}
	
	numero_alumnos++;
}

// Borra el primer nodo que contiene el DNI indicado
void GrupoDeAlumnos :: Elimina (char * DNI){
	
	int pos = Busca (DNI);
	
	if (pos != -1)
		Borra (pos);
}

	/***********************************************************************/
	// Inserta un nuevo elemento en la posición "pos_insertar"
	// PRE: 1 <= pos_insertar <= tamanio+1
	// El criterio seguido para especificar una posicion será : 
	// 1 -> primero, 2 -> segundo,...
	// Nota: Si pos_insertar == tamanio+1, el resultado es idéntico a la 
	// 		 ejecución del método Aniade()
	//
	// PRE: El objeto que se va a insertar ha reservado su propia memoria 
	// 		para alojar una copia propia de sus datos (nombre, DNI y notas).

void GrupoDeAlumnos :: Inserta (Alumno valor, int pos_insertar){
	PNodo ant = datos;
	PNodo resto = datos;

	// Crear el nodo que se va a insertar e iniciarlo
	PNodo nuevo = new Nodo; 
	nuevo->info = valor; 

	// Buscar el sitio que le corresponde 
	for (int i = 1; i < pos_insertar; i++) { 
		ant = resto; 
		resto = resto->sig;
	}

	if (pos_insertar==1)   // El nuevo nodo sera el primero 
		datos = nuevo;
	else		  // Enlazar el nuevo con el anterior 
		ant->sig = nuevo;

	nuevo->sig = resto; // Enlazar el nuevo nodo con el resto

	numero_alumnos++; // Actualizar tamanio
}

/***********************************************************************/
// Borra el elemento de la posición "pos_borrar" 
// PRE: 1 <= pos_borrar <= tamanio
// El criterio seguido para especificar una posicion será : 
// 1 -> primero, 2 -> segundo,...
void GrupoDeAlumnos :: Borra (int pos_borrar){
	PNodo ant = datos;
	PNodo pos = datos;
	// Colocar los punteros a nodo 
	for (int i = 1; i < pos_borrar; i++) { 
		ant = pos; 
		pos = pos->sig;
	}

	// pos tiene nodo que se va a borrar
	// ant al nodo anterior

	if (pos_borrar==1)   // Saltar el primero 
		datos = datos->sig;
	else 
		ant->sig = pos->sig;
		// Enlazar el anterior con el siguiente 

	delete pos; // Borrar nodo
	
	numero_alumnos--;  // Actualizar tamanio
}


Lista GrupoDeAlumnos :: GetPrimerNodo(void)const{
	return(datos);
}

	
/***********************************************************************/
// Operador de asignación
GrupoDeAlumnos & GrupoDeAlumnos :: operator =  (const GrupoDeAlumnos & otro){

	if(this != &otro){

		LiberarMemoria();
		ReservarMemoria(otro.NumeroAlumnos(),otro.NumeroNotas());
		CopiarDatos(otro);
	}

    return (*this);
}
		
/***********************************************************************/
		
/***********************************************************************/
// Petición / liberación de memoria

void GrupoDeAlumnos :: ReservarMemoria (int numero_alumnos, int num_notas){
	//creo la lista con los alumnos
	PNodo fin = datos;
	
	fin = new Nodo;
	
	for(int i= 1; i < numero_alumnos; i++){
		fin->sig = new Nodo;
		fin = fin->sig;
		fin->sig = 0;
	}
	//creo el vector con las ponderaciones
	
	pesos = new double [num_notas];
}

void GrupoDeAlumnos :: LiberarMemoria (void){
	if(datos){
		PNodo aux = datos; // Colocar aux al principio

		while (aux->sig != 0) {
			aux = aux->sig;	//adelantar aux
			delete datos;	//borrar l
			datos = aux;	//actualizar l
		}
		delete datos; // Borrar el único nodo que queda
	}

	datos = 0;
		
	if(pesos)
		delete [] pesos;
}

/***********************************************************************/
// Copiar datos desde otro objeto de la clase
void GrupoDeAlumnos :: CopiarDatos (const GrupoDeAlumnos & otro){
	
	PNodo este = datos; // Apuntar al primero.
	PNodo p_otro = otro.datos;
	
	ReservarMemoria(otro.NumeroAlumnos(), otro.NumeroNotas());
	
	for(int i = 0; i < numero_alumnos; i++) {
		este->info = p_otro->info; // Inicializar nodo.
		este = este->sig;		 // Adelantar este.
		este = este->sig;
		p_otro = p_otro->sig;
	}

}		
		
/////////////////////////////////////////////////////////////////////////////


/***************************************************************************/
/***************************************************************************/
// Muestra los pesos leidos para las ponderaciones de las calificaciones
// precedido del mensaje "msg"
void MuestraPesos (const GrupoDeAlumnos & una_clase, const char * msg){

	cout << msg << endl;

	for(int i = 0; i < una_clase.NumeroNotas();i++){
		cout << " " << una_clase.Peso(i);
	}
	cout << endl;
}


/***********************************************************************/
// Muestra un listado de una clase de alumnos, precedido del mensaje "msg"
void Listado (const GrupoDeAlumnos & una_clase, const char * msg, bool verbose){
	if(verbose){
		cout << msg << endl;
		cout << endl;

		cout << Linea (80, '-') << endl;
		cout << endl; 
		cout << "La clase tiene " << una_clase.NumeroAlumnos() << " alumnos." << endl; 
		cout << endl; 

		PNodo aux = una_clase.GetPrimerNodo();

		for (int alumno = 0; alumno < una_clase.NumeroAlumnos(); alumno++) {	
			PintaAlumno(aux->info,verbose);
		}

		cout << Linea (80, '-') << endl;
		cout << endl;	
	}

}

