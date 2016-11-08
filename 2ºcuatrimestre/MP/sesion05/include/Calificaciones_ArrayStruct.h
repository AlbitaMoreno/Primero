//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
//Calificaciones_ArrayStruct.h
//
/***************************************************************************/

#ifndef CALIFICACIONES_ARRAYSTRUCT
#define CALIFICACIONES_ARRAYSTRUCT

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


bool Iguales (double uno, double dos, double precision);

//Lee los pesos de las calificaciones y los guarda en el vector de pesos
void LeePesos (double *ponderaciones, char *cad, int num_peso);

//Comprueba la validez de los pesos leidos: deben sumar 100.0.
bool CorrectosPesos(double *ponderaciones,int num_pesos);

//Muestra los pesos leídos para las ponderaciones de las calificaciones.
void  MuestraPesos(double *ponderaciones, int num_pesos);

//Lee los datos de los alumnos y los guarda en un vector.
int LeerAlumnos (RegAlumno *datos, char *cad, RegAlumno *ptr_vector_alumnos, int num_alumnos);

//Calcula las calificaciones medias de los alumnos.
void CalculaCalificacionesMedias (double *medias, RegAlumno *datos, int num_alumnos, double *ponderaciones, int num_notas);

//Mostrar la lista de los alumnos con todas las calificaciones y su media.
void MuestraVectorAlumnos (RegAlumno *datos, double *medias, int num_alumnos,double izq, double der);

//Ordenar el vector de datos de alumnos en base a la nota media.
void OrdenaVectorAlumnos (RegAlumno *ptr_alumno, double *medias, int num_alumnos);


#endif