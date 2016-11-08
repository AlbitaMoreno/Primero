//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
//II_02_Calificaciones_ArrayDinamicoStruct_ordenado.cpp//
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

/***************************************************************************/
/***************************************************************************/
// Declaraciones globales

//const int NUM_NOTAS  =  5; // Número de pesos/calificaciones consideradas
const int TAM_CAD = 80; // Número máximo de caracteres para cadenas clásicas
char cad[TAM_CAD];
const int TAM_INICIAL = 6;

struct RegAlumno {
	double 	*notas;
 	char *apellido_nombre;
 	char *DNI;	
};

/***************************************************************************/
/***************************************************************************/
// Prototipos de las funciones

bool Iguales (double, double, double);
void LeePesos (double[], int);
bool CorrectosPesos (double[], int);
void MuestraPesos (double[], int);
void LeerAlumnos (RegAlumno[], int, int&);
RegAlumno *Redimensiona(RegAlumno[],int, int);
void Copia(RegAlumno[], RegAlumno[] , int ,int);
void CalculaCalificacionesMedias (double[], RegAlumno[], int, double[], int);
void MuestraVectorAlumnos (RegAlumno[], double[], int, int);
void OrdenaVectorAlumnos  (RegAlumno[], double[], int);
void Borra(RegAlumno[],double[],double[]);

/***************************************************************************/
/***************************************************************************/

int main(){
	
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 

	/*********************************************************************/
	//Declaración de datos
	/********************************************************************/
	
	cin.getline(cad,TAM_CAD);
	int NUM_NOTAS = atoi(cad);

	int num_alumnos = 0;	//no hay alumnos inicialmente
	double *pesos = new double [NUM_NOTAS];
	
	RegAlumno *alumnos = new RegAlumno [TAM_INICIAL];	//array dinamico de alumnos, incialmente tiene un alumno

	//Leemos los pesos de las notas

	LeePesos(pesos, NUM_NOTAS);

	if(!CorrectosPesos(pesos,NUM_NOTAS)){
		cout << "Los pesos no suman 100" << endl;
		exit(1);
	}

	MuestraPesos(pesos,NUM_NOTAS);

	//Leer alumnos, LeeAlumnos modifica mediante una referencia el numero de alumnos que hay
	//el numero de alumnos

	LeerAlumnos(alumnos,NUM_NOTAS,num_alumnos);

	//una vez tenemos todos los alumnos calculamos las calificaciones medias y las guardamos en un array dinamico

	double *calificaciones_medias = new double [num_alumnos];

	CalculaCalificacionesMedias(calificaciones_medias,alumnos,num_alumnos,pesos,NUM_NOTAS);

	MuestraVectorAlumnos(alumnos,calificaciones_medias,num_alumnos,NUM_NOTAS);

	//.......................................................................
	// Ordena el vector de alumnos y mostrar resultado
	
	OrdenaVectorAlumnos (alumnos, calificaciones_medias, num_alumnos);
	
	MuestraVectorAlumnos (alumnos, calificaciones_medias, num_alumnos, NUM_NOTAS);

	//borramos los arrays dinamicos una vez terminado 
	Borra(alumnos,calificaciones_medias,pesos);
	return(0);
}

/***************************************************************************/
/***************************************************************************/
/***************************************************************************/
/***************************************************************************/

void LeePesos (double ponderaciones[], int num_pesos)
{
	// Cadena clásica usada para la lectura de todos los datos
	double peso; 

	// Leer y guardar pesos.

	for (int i=0; i<num_pesos; i++) {

		cin.getline(cad, TAM_CAD);

		peso = atof(cad); 
		ponderaciones[i] = peso; 	
	}
}

/***************************************************************************/
/***************************************************************************/

bool CorrectosPesos (double ponderaciones[], int num_pesos)
{
	double suma_pesos = 0; 

	for (int i=0; i<num_pesos; i++) 
		suma_pesos += ponderaciones[i]; 

	return (Iguales (suma_pesos, 100.0, 0.001));
}

/***************************************************************************/
/***************************************************************************/

void MuestraPesos (double ponderaciones[], int num_pesos)
{

	cout << endl;
	cout << "Los pesos empleados para ponderar las notas son: " << endl;
	
	for (int i = 0; i < num_pesos; i++) {
		cout << "\tPonderación de la nota " << setw(2) << i+1 << " : ";
		cout << setw(6) << setprecision(2) 
             << right << ponderaciones[i] << "%" << endl;
	}
	cout << endl; 
}

/***************************************************************************/
/***************************************************************************/

void LeerAlumnos (RegAlumno datos[], int NUM_NOTAS, int &num_alumnos){
	
	cin.getline (cad, TAM_CAD);	//Lectura adelantada de DNI

	while (strcmp (cad, "*")) {

		RegAlumno nuevo_alumno;		
		/***************************************************************************/

		nuevo_alumno.DNI = new char [TAM_CAD];

		strcpy(nuevo_alumno.DNI, cad);	//copio el DNI

		/***************************************************************************/

		nuevo_alumno.apellido_nombre = new char [TAM_CAD];

		/***************************************************************************/

		cin.getline (cad, TAM_CAD); // Lectura de apellidos

		strcpy(nuevo_alumno.apellido_nombre, cad); // Copiar apellidos
		
		/***************************************************************************/

		cin.getline (cad, TAM_CAD); // nombre

		strcat(nuevo_alumno.apellido_nombre, ", "); // Anadir ", "
		strcat(nuevo_alumno.apellido_nombre,  cad); // Añadir nombre
		
		/***************************************************************************/

		// Leer y guardar notas, en un array dinamico
		nuevo_alumno.notas = new double [NUM_NOTAS];

		for (int i = 0; i < NUM_NOTAS; i++) {

			cin.getline(cad, TAM_CAD); // nota i-ésima

			nuevo_alumno.notas[i] = atof(cad);

		}


		// Añadir los datos leidos al vector y actualizar contador
		
		datos[num_alumnos] = nuevo_alumno;

		num_alumnos++;

		// Se ha terminado de procesar un alumno 
			
		cin.getline (cad, TAM_CAD); // Lectura adelantada de DNI

		//si se van a seguir leyendo datos, redimensiono el vector datos

		/*if(strcmp (cad, "*")){

			RegAlumno *aux = new RegAlumno [num_alumnos];

			for(int alumno = 0; alumno < num_alumnos; alumno++){
				aux[alumno] = datos[alumno];
			}

			delete[] datos;
			datos = aux;
		}*/
		
	} // while (strcmp (cad, "*"))
}

/***************************************************************************/
/***************************************************************************/

void CalculaCalificacionesMedias (double    medias[], RegAlumno datos[], int num_alumnos, double ponder[], int num_notas){
	
	for (int alumno=0; alumno<num_alumnos; alumno++) {

		double suma_notas_ponderadas = 0.0; 

		for (int nota=0; nota<num_notas; nota++) 

			suma_notas_ponderadas += datos[alumno].notas[nota]* ponder[nota];

		medias[alumno] = suma_notas_ponderadas / 100.0;;
	}

}

/***************************************************************************/
/***************************************************************************/

void MuestraVectorAlumnos (RegAlumno datos[], double medias[], int num_alumnos, int NUM_NOTAS){
	cout << endl; 
	cout << "La clase tiene " << num_alumnos << " alumnos." << endl; 
	cout << endl; 


	for (int alumno=0; alumno<num_alumnos; alumno++) {
	
		// Mostrar datos del alumno "alumno"
		cout << setw(3) << right << (alumno+1) << " :  ";
		cout << setw(30)<< left << datos[alumno].apellido_nombre;

		for (int nota=0; nota<NUM_NOTAS; nota++) 
			cout << setw(6) << setprecision(2) <<right 
                 << datos[alumno].notas[nota];

		cout << " --> "; 
		cout << setw(6) << setprecision(2) <<right<< medias[alumno];
		cout << endl; 
	}
	cout << endl; 
}


/***************************************************************************/
/***************************************************************************/

void OrdenaVectorAlumnos (RegAlumno datos[], double medias[], int num_alumnos){

	// campo clave de ordenación: no es un datos almacenado en "datos"
	double nota_media_a_desplazar;

	// datos a desplazar (copiar en una nueva posición)
	RegAlumno alumno_a_desplazar;

		
	// "izda" marca el límite entre la parte ordenada (0  hasta "izda"-1)
	// y la parte que falta por ordenar ("izda" hasta "total_utilizados"-1)
	// En definitiva, en cada iteración se trata de buscar el sitio para 
	// los datos que están en la casilla "izda".
	
	for (int izda = 1; izda < num_alumnos; izda++) {
			
		// Datos que se van a colocar en su posición corecta. 
		// Los copiamos en la variable "alumno_a_desplazar" 
		// para salvaguardar su contenido. 

		alumno_a_desplazar = datos[izda];
			
		// El valor usado como clave en la ordenación es la nota media: 
		// Obtener la nota media del alumno que ocupa la posición 
		// para poder compararla con la nota media de los demás. 
			
		nota_media_a_desplazar = medias[izda];
						
						
		// Buscamos su sitio en la parte ordenada (la zona con los  
		// índices bajos de los vectores). 
			
		int i = izda; 
			
		while ((i>0) && (nota_media_a_desplazar < medias[i-1])) {
				
			// Copiar los datos de la casilla "i"-1 en la casilla "i"

			datos[i]  = datos[i-1];
			medias[i] = medias[i-1];

								
			i--; // continuar buscando
		}	
							
		// En la casilla "i" guardaremos los datos salvaguardados. 
			
		datos[i]  = alumno_a_desplazar;		
		medias[i] = nota_media_a_desplazar;
		
	} // for izda
}

/***************************************************************************/
/***************************************************************************/

bool Iguales (double uno, double dos, double precision)
{
	return (fabs(uno-dos) <= precision);

}

void Borra(RegAlumno datos[],double calificaciones_medias[],double ponderaciones[]){
	delete[] datos;
	delete[] calificaciones_medias;
	delete[] ponderaciones;
} 
