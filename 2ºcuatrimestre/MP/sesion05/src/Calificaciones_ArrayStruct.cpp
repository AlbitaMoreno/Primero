//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
//Calificaciones_ArrayStruct.cpp
//
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include "Calificaciones_ArrayStruct.h"

using namespace std;

bool Iguales (double uno, double dos, double precision){
	return (fabs(uno-dos) <= precision);
}

void LeePesos(double *ponderaciones, char *cad, int num_peso){
	double peso;
	
	for (int i=0; i < num_peso; i++,ponderaciones++) {

		cin.getline(cad, TAM_CAD);
		
		//tof convierte de char aa double
		peso = atof(cad);
		 
		*ponderaciones = peso; 	
	}
}


bool CorrectosPesos(double *ponderaciones,int num_pesos){
	double suma = 0;
	bool correcto = true;
	//sumo las notas

	for(int i = 0; i < num_pesos; i++, ponderaciones++){
		suma +=  *ponderaciones;
	}

	if (!Iguales (suma, 100.0,0.001))
		correcto = false;

	return(correcto);
}

void  MuestraPesos(double *ponderaciones, int num_pesos){

	cout << "Los pesos empleados para ponderar las notas son: " << endl;
	for (int i = 0; i < num_pesos; i++,ponderaciones++) {
		cout << "\tNota " << setw(2) << i+1 << " : ";
		cout << setw(6) << setprecision(2) << right << *ponderaciones << "%" << endl;
	}
	cout << endl;
}

//Lee los datos de los alumnos y los guarda en un vector, devuelve el numero de alumnos
int LeerAlumnos (RegAlumno *datos, char *cad, RegAlumno *ptr_vector_alumnos, int num_alumnos){
	
	strcpy(datos -> apellido_nombre, cad); // Copiar apellidos
		 
	cin.getline (cad, TAM_CAD); // nombre

	strcat(datos->apellido_nombre, ", "); // Añadir ", "
	strcat(datos->apellido_nombre,  cad); // Añadir nombre
	

	// Leer y guardar notas
	for (int i=0; i < NUM_NOTAS; i++) {
		cin.getline(cad, TAM_CAD); // nota i-ésima
		datos->notas[i] = atof(cad);
	}

	// Añadir los datos leidos al vector y actualizar contador
	
	*ptr_vector_alumnos = *datos;

	num_alumnos++;
		
	// Se ha terminado de procesar un alumno 
	cin.getline (cad, TAM_CAD); // Lectura adelantada de apellidos
	
	return(num_alumnos);
}

//Calcula las calificaciones medias de los alumnos.
void CalculaCalificacionesMedias (double *medias, RegAlumno *datos, int num_alumnos, double *ponderaciones, int num_notas){
	//media los incremento en el primer bucle
	double *aux = ponderaciones;

	for (int alumno=0; alumno < num_alumnos; alumno++,medias++,datos++) {

		double suma_notas_ponderadas = 0.0;
		aux = ponderaciones; 

		//hago avanzar los punteros vector_alumnos, aux
		for (int i = 0; i < num_notas; i++,aux++){
			//como ptr_alumnos es un vector al strcut alumnos puedo acceder al campo notas de cada alumno
			suma_notas_ponderadas += (datos->notas[i])* *aux;
		} 
		*medias = (suma_notas_ponderadas / 100.0);
	}
}

//Mostrar la lista de los alumnos con todas las calificaciones y su media.
void MuestraVectorAlumnos (RegAlumno *datos, double medias[], int num_alumnos,double izq, double der){

	for (int alumno=0; alumno < num_alumnos; alumno++,datos++,medias++) {
		
		if(*medias >= izq && *medias <= der){
			// Mostrar datos del alumno "alumno"
			cout << setw(3) << right << (alumno+1) << " :  ";
			cout << setw(30)<< left << datos -> apellido_nombre;

			for (int nota = 0; nota < NUM_NOTAS; nota++) 
				cout << setw(6) << setprecision(2) <<right << datos->notas[nota];

			cout << " --> "; 
			cout << setw(6) << setprecision(2) <<right<< *medias;
			cout << endl; 
		}
	}
}

//Ordenar el vector de datos de alumnos en base a la nota media.
void OrdenaVectorAlumnos (RegAlumno *ptr_alumno, double *medias, int num_alumnos){
	double *medias1 = medias;
	double *medias2 = medias + 1;
	RegAlumno *ptr2 = ptr_alumno+1;
	RegAlumno *ptr1 = ptr_alumno;

	//1º for solo controla que se hagan tantas iteraciones como alumnos haya
	for(int i = 0; i < num_alumnos; i++){
		//cada vez que hace una iteracion incializo las varibles que usan los ciclos más internos
		medias1 = medias;
		medias2 = medias + 1;
		ptr2 = ptr_alumno+1;
		ptr1 = ptr_alumno;

		for (int alumno=0; alumno < num_alumnos; alumno++,ptr1++,ptr2++,medias1++,medias2++) {
			//medias 1, 2 y ptr1 son punteros de moviemiento que deben inicializarse con cada iteracion
			for (int i = 0; i < num_alumnos; i++){
				//si media < (media+1) entonces intercambio las notas, los nombres, y la media
				if(*medias1 < *medias2){
					
					//intercambio las medias
					double aux = *medias1;
					*medias1 = *medias2;
					*medias2 = aux;

					double aux_notas;
					//intercambio las notas
					for(int j = 0; j < NUM_NOTAS; j++){
						aux_notas = ptr1->notas[j];
						ptr1->notas[j] = ptr2->notas[j];
						ptr2->notas[j] = aux_notas;
					}

					char aux_nom[TAM_NOMBRE];
					//intercambio los nombres
					strcpy(aux_nom,ptr1->apellido_nombre);
					strcpy(ptr1->apellido_nombre,ptr2->apellido_nombre);
					strcpy(ptr2->apellido_nombre,aux_nom);
				}
			} 	
		}
	}
}

