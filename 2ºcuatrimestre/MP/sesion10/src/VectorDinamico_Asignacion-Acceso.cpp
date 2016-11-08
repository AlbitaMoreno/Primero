//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
// VectorDinamico_Asignacion-Acceso.cpp
//
/***************************************************************************/

#include <iostream>
#include <cstring>
#include "VectorDinamico_Asignacion_Acceso.h"

using namespace std;

/********************************************************************************************/
/*******************************************************************************************/
//
//	Constructores y destructor
//	
/********************************************************************************************/
/*******************************************************************************************/

//Constuctor sin argumentos
MiVectorDinamico :: MiVectorDinamico(){
	tam = TAMANIO_DEF;
	ReservaMem(tam);
	MismoValor();		//los inicializo a 0, para luego poder ver las casillas usadas
}

//Constructor que recive como argumento el numero de casillas del vector dinamico
//le da valor al tamaño del vector y reserva memoria llamando al método ReservaMem 

MiVectorDinamico :: MiVectorDinamico(int num_casillas){
	tam = num_casillas;
	ReservaMem(num_casillas);
	MismoValor();
}

MiVectorDinamico :: MiVectorDinamico (const MiVectorDinamico &vector){
	ReservaMem(tam);
	CopiarDatos(vector);
}

//Destructor, llama al método LiberaMem para liberar el vector que hay en el heap
MiVectorDinamico :: ~MiVectorDinamico(){
	LiberaMem();
}

/********************************************************************************************/
/*******************************************************************************************/
//
//	MÉTODOS PÚBLICOS
//	
/********************************************************************************************/
/*******************************************************************************************/

bool MiVectorDinamico :: VectorVacio()const{
	return(!vec);
}

/********************************************************************************************/
/*******************************************************************************************/

int MiVectorDinamico :: GetTamanio()const{
	return(tam);
}

void MiVectorDinamico:: SetRedimension(TipoRedimension tipo){
	redimension = tipo;
}

/********************************************************************************************/
/*******************************************************************************************/

//Método para ver el tipo de redimension usada
void MiVectorDinamico :: MuestraTipoRedimension() const{
	cout << "/**********************************************************/" << endl;
	cout << "TIPO DE REDIMENSION USADA --> ";

	switch (redimension) { 
	
		case (DeUnoEnUno):	
					cout << "de uno en uno";
					break;
		case (EnBloques):	
					cout << "en bloques";
					break;
		case (Duplicando):	
					cout << "duplicando";
					break; 
	}
}

/********************************************************************************************/
/*******************************************************************************************/

TipoBase* MiVectorDinamico ::  Redimensiona(){
	const int TAM_BLOQUE = 5;

	//veo el tipo de redimension que tengo que hacer
    switch (redimension){
        case (DeUnoEnUno): // 1 casilla más
           	tam++;
            break;

        case (EnBloques): 
            tam+=TAM_BLOQUE;
            break;

        case (Duplicando): 
            tam*=2;
            break;
    }

    TipoBase *v = new TipoBase[tam];

	memcpy(v,vec, GetUsados()*sizeof(TipoBase));

	//libero la memoria del vector original
	delete [] vec;
	vec = v;

	return(vec);
}

/********************************************************************************************/
/*******************************************************************************************/

int MiVectorDinamico :: GetUsados(){
	int usados = 0;

	if(vec){
		for(int i = 0; i < tam && vec[i] != 0 ; i++)
			usados++;
	}

	return(usados);
}

/********************************************************************************************/
/*******************************************************************************************/

void MiVectorDinamico :: MismoValor(TipoBase valor){
	for(int i = 0; i < tam; i++)
		vec[i] = valor;
}

/********************************************************************************************/
/*******************************************************************************************/
//
//	MÉTODOS PRIVADOS
//	
/********************************************************************************************/
/*******************************************************************************************/

//función que reserva memoria si el argumento que se le pasa es mayor que 0
void MiVectorDinamico :: ReservaMem(int num_casillas){
	if (num_casillas > 0){
		vec = new TipoBase [num_casillas];
	}
}

/********************************************************************************************/
/*******************************************************************************************/

//funcion que libera el vector si existe
void MiVectorDinamico :: LiberaMem(){
	if(vec)
		delete [] vec;
}

/********************************************************************************************/
/*******************************************************************************************/

void MiVectorDinamico :: CopiarDatos(const MiVectorDinamico & otro_vec){
	tam = otro_vec.tam;
	//copio en vec, los datos de otr_vec.vec
	memcpy(vec,otro_vec.vec,tam*sizeof(TipoBase));
}

/********************************************************************************************/
/*******************************************************************************************/
//
//	SOBRECARGA DE OPERADORES
//	
/********************************************************************************************/
/*******************************************************************************************/


MiVectorDinamico & MiVectorDinamico :: operator = (const MiVectorDinamico & otro){
	
	if (this != &otro) { // Evitar autoasignación
		LiberaMem();
		// Reserva de memoria para los Elementos del vector
		ReservaMem(otro.tam);
		// Copia los campos privados y los elementos del vector
		CopiarDatos(otro);
	}
	return (*this);	//devuelvo el objeto implicito nuevo
}

/********************************************************************************************/
/*******************************************************************************************/

MiVectorDinamico & MiVectorDinamico :: operator = (TipoBase valor){
	//incializa todos los campos del vector al mismo valor
	LiberaMem();
	ReservaMem(tam);
	MismoValor(valor);

	return(*this);
}

/********************************************************************************************/
/*******************************************************************************************/

TipoBase & MiVectorDinamico :: operator [](const int indice){
	return(vec[indice]);
}
