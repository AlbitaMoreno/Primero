//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
// Fichero: VectorDinamico_ConstructorCopia.cpp
//
/***************************************************************************/

#include <iostream>
#include <cstring>
#include "VectorDinamico_ConstructorCopia.h"

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
	usados = 0;
	ReservaMem(tam);

}

//Constructor que recive como argumento el numero de casillas del vector dinamico
//le da valor al tamaño del vector y reserva memoria llamando al método ReservaMem 

MiVectorDinamico :: MiVectorDinamico(int num_casillas){
	tam = num_casillas;
	usados = 0;
	ReservaMem(num_casillas);
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
	bool vacio = false;

	if(!vec)
		vacio = true;

	return(vacio);
}

/********************************************************************************************/
/*******************************************************************************************/

int MiVectorDinamico :: GetUsados() const{
	return(usados);
}

int MiVectorDinamico :: GetTamanio()const{
	return(tam);
}

void MiVectorDinamico:: SetRedimension(TipoRedimension tipo){
	redimension = tipo;
}
/********************************************************************************************/
/*******************************************************************************************/

//Inserta un valor al final del vector
void MiVectorDinamico :: SetValor(TipoBase valor){
	
	if(usados == tam)
		vec = Redimensiona();
	
	if(usados < tam){		
		vec[usados] = valor;
		usados++;
	}
}

/********************************************************************************************/
/*******************************************************************************************/

//Método para obtener el valor de una posicion del vector
TipoBase MiVectorDinamico :: GetValor(int indice) const{
	
	//si el indice está dentro de las casillas usadas, devuelvo el valor
	if(indice < usados)
		return (vec[indice]);

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

	memcpy(v,vec, usados*sizeof(TipoBase));

	//libero la memoria del vector original
	delete [] vec;
	vec = v;

	return(vec);
}

/********************************************************************************************/
/*******************************************************************************************/

void MiVectorDinamico :: PintaVector() const{
	for (int i = 0; i < GetUsados(); i++)
		cout << " " << vec[i];

	cout << endl;
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

