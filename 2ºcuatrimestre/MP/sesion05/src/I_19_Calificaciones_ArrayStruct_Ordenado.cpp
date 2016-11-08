//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
//I_19_Calificaciones_ArrayStruct_Ordenado.cpp
//
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include "Calificaciones_ArrayStruct.h"

using namespace std;

int main(int argc, char const *argv[]){
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 


	// Cadena clásica usada para la lectura de todos los datos

	char cad[TAM_CAD];

	//ptr_cad se ira moviendo y copiando ,lo que haya en la cadena de lectura de datos, en los vectores correspondientes
	char *ptr_cad = &cad[0];

	double pesos[NUM_NOTAS];	// Vector de pesos
	//ptr_pesos va a recivir los pesos y copiarlos en pesos[]
	double *ptr_pesos = &pesos[0];

	RegAlumno alumnos[TAMANIO];
	int num_alumnos = 0;	// Número de casillas ocupadas
							//PRE: 0 <= num_alumnos <= TAMANIO
	RegAlumno *ptr_vector_alumnos = &alumnos[0];	
	//creo el vector calificacion media con su puntero asociado, 
	//vuelvo a inicializa los punteros al vector de alumnos y al vector de pesos
	double calificacion_media[TAMANIO] = {0.0};
	double *medias = &calificacion_media[0];
	
	if(argc == 1){
		cout << "Sin argumentos" << endl;
		LeePesos(ptr_pesos, ptr_cad, NUM_NOTAS);
		
		// Si no suman 100 se aborta la ejecución del programa
		
		if(!CorrectosPesos(ptr_pesos,NUM_NOTAS)){
			cerr << "Error: los pesos no suman 100" << endl;
			exit (1); 
		}

		cout << endl;
		ptr_pesos = &pesos[0];
		MuestraPesos(ptr_pesos, NUM_NOTAS);	
		//.......................................................................
		// Leer datos: apellidos, nombre, y cuatro calificaciones por alumno. 
		
		cin.getline (cad, TAM_CAD); // Lectura adelantada de apellidos

		while (strcmp (cad, "*")){

			RegAlumno nuevo_alumno;
			//ptr_alumno apunta al struct
			RegAlumno *ptr_alumno = &nuevo_alumno;		

			//le paso, vector al struct para modificar los campos, vector a la cadena desde donde se leen los datos,
			//ptr al vector donde se almacenan los nombres_apellidos de los alumnos, y devuelve el numeros de alumnos
			num_alumnos  = LeerAlumnos(ptr_alumno, ptr_cad, ptr_vector_alumnos, num_alumnos);
			
			ptr_vector_alumnos++;
		} 

		ptr_vector_alumnos = &alumnos[0];
		ptr_pesos = &pesos[0];

		CalculaCalificacionesMedias (medias, ptr_vector_alumnos, num_alumnos, ptr_pesos, NUM_NOTAS);
		
		OrdenaVectorAlumnos (ptr_vector_alumnos, medias, num_alumnos);
		cout << endl;
		MuestraVectorAlumnos (ptr_vector_alumnos, medias,num_alumnos,0.0,10.0);
		cout << endl; 
	}

	if(argc == 3){
		cout << "Sin argumentos" << endl;
		LeePesos(ptr_pesos, ptr_cad, NUM_NOTAS);
		
		// Si no suman 100 se aborta la ejecución del programa
		
		if(!CorrectosPesos(ptr_pesos,NUM_NOTAS)){
			cerr << "Error: los pesos no suman 100" << endl;
			exit (1); 
		}

		cout << endl;
		ptr_pesos = &pesos[0];
		MuestraPesos(ptr_pesos, NUM_NOTAS);	

		//.......................................................................
		// Leer datos: apellidos, nombre, y cuatro calificaciones por alumno. 
		
		cin.getline (cad, TAM_CAD); // Lectura adelantada de apellidos

		while (strcmp (cad, "*")){

			RegAlumno nuevo_alumno;
			//ptr_alumno apunta al struct
			RegAlumno *ptr_alumno = &nuevo_alumno;		

			//le paso, vector al struct para modificar los campos, vector a la cadena desde donde se leen los datos,
			//ptr al vector donde se almacenan los nombres_apellidos de los alumnos, y devuelve el numeros de alumnos
			num_alumnos  = LeerAlumnos(ptr_alumno, ptr_cad, ptr_vector_alumnos, num_alumnos);
			
			ptr_vector_alumnos++;
		} 

		ptr_vector_alumnos = &alumnos[0];
		ptr_pesos = &pesos[0];

		CalculaCalificacionesMedias (medias, ptr_vector_alumnos, num_alumnos, ptr_pesos, NUM_NOTAS);
		
		//.......................................................................
		// Mostrar la lista de los alumnos con todas las calificaciones y su media
	 
		cout << "La clase tiene " << num_alumnos << " alumnos." << endl; 
		cout << endl; 
		double izq = atof(argv[1]);
		double der = atof(argv[2]);
		
		OrdenaVectorAlumnos (ptr_vector_alumnos, medias, num_alumnos);
		MuestraVectorAlumnos (ptr_vector_alumnos, medias,num_alumnos,izq,der);
		cout << endl;
	}

	if(argc == 2){
		cout << "ERROR argumentos inválidos" << endl;
		exit(1);
	}
	if(argc > 3){
		cout << "ERROR argumentos inválidos" << endl;
		exit(2);
	}
	//.......................................................................

	return (0);
}