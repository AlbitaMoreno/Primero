//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
// Lista_Asignaccion_Acceso.cpp
// 
//
/***************************************************************************/


/********************************************************************************************/
/*******************************************************************************************/
//
//	Constructores y destructor
//	
/********************************************************************************************/
/*******************************************************************************************/
//sin argumentos, lista vacía
#include "Lista_Asignacion_Acceso.h"
#include <iostream>

using namespace std;

MiLista :: MiLista(){
	num_nodos = 0;
	l = 0;
}

MiLista :: MiLista(int nodos){
	num_nodos = nodos;
	ReservaMem(num_nodos);
	MismoValor();
}

MiLista :: MiLista(const MiLista &otro){
	ReservaMem(otro.num_nodos);
	CopiarDatos(otro);
}

MiLista :: ~MiLista(){
	LiberaMem();
}

/********************************************************************************************/
/*******************************************************************************************/
//
//	MÉTODOS PÚBLICOS
//	
/********************************************************************************************/
/*******************************************************************************************/
bool MiLista :: ListaVacia()const{
	return(!l);
}

/********************************************************************************************/
/*******************************************************************************************/

int MiLista :: GetNumNodos() const{
	int cont = 0;

	if(l){
		Lista aux = l;
		while(aux){
			cont++;
			aux = aux->sig;
		}
	}
	
	return(cont);
}


/********************************************************************************************/
/*******************************************************************************************/

void MiLista :: MismoValor(TipoBase valor){
	
	if(l){
		PNodo p = l;
		for(int i = 1; i <= num_nodos; i++){
			p->info = valor; 
			p = p->sig;
		}
	}	
}

/********************************************************************************************/
/*******************************************************************************************/
//funcion que uso para sobrecargar el operador [], 
//devuelve un puntero con la direccion del nodo a leer o modificar
PNodo MiLista :: BuscaNodo(const int indice)const{
	PNodo aux = l;
	
	if(l){
		if(indice < num_nodos){
			for(int i = 0; i < indice; i++)
				aux = aux->sig;
		}
	}
	
	return(aux);	//devuelvo la direccion del nodo que busco
}

int MiLista :: BuscaPos(TipoBase valor)const{
	PNodo aux = l;

    bool sigo = true;
    bool encontrado = false;
    
   	int pos = 0;
    	
    while (aux && sigo) {
      	
		pos++; // Actualizar posición

	    if (aux->info == valor) {
	        sigo = false;
	        encontrado = true;
	    }

	    else 
	        aux = aux->sig;
	}
	
	if(!encontrado)
		pos = -1;
	return (pos); 
}


/********************************************************************************************/
/*******************************************************************************************/

void MiLista :: Elimina (TipoBase valor){
	int pos = BuscaPos(valor);

	// Si pos > 0 se encontró el nodo buscado: eliminarlo
	if (pos > 0) 
		Borra(pos);
}

/********************************************************************************************/
/*******************************************************************************************/

void  MiLista :: Borra (int pos_borrar) {
	PNodo ant = l;
	PNodo pos = l;

	ant = BuscaNodo(pos_borrar-1);
	pos = BuscaNodo(pos_borrar);

	// "pos" apunta al nodo que se va a borrar
	// "ant" apunta al nodo anterior

	if (pos_borrar==1)   // Saltar el primero 
		l = l->sig;
	else 
		ant->sig = pos->sig;
		// Enlazar el anterior con el siguiente 
	delete pos; // Borrar nodo
	num_nodos--;  // Actualizar tamanio
}

/********************************************************************************************/
/*******************************************************************************************/

void  MiLista :: Inserta (TipoBase val, int pos_insertar){
	PNodo ant = l;
	PNodo resto = l;

	// Crear el nodo que se va a insertar e iniciarlo
	PNodo nuevo = new Nodo; 
	nuevo->info = val; 

	// Buscar el sitio que le corresponde 
	ant = BuscaNodo(pos_insertar-1);
	resto = BuscaNodo(pos_insertar);

	if (pos_insertar==1)   // El nuevo nodo sera el primero 
		l = nuevo;
	else		  // Enlazar el nuevo con el anterior 
		ant->sig = nuevo;
	
	nuevo->sig = resto; // Enlazar el nuevo nodo con el resto
	num_nodos++; // Actualizar tamanio
}





/********************************************************************************************/
/*******************************************************************************************/
//
//	MÉTODOS PRIVADOS
//	
/********************************************************************************************/
/*******************************************************************************************/

void MiLista :: ReservaMem(int nodos){
	//si no recive ningún argumento, crea una lista vacía
	l = 0;

	if(nodos > 0){
		PNodo fin;

		ReservaPrimerNodo(0);

		fin = l;

		for(int i = 1; i < nodos; i++){
			fin->sig = new Nodo;
			fin = fin->sig;
			fin->sig = 0;
		}
	}	
}

/********************************************************************************************/
/*******************************************************************************************/

void MiLista :: ReservaPrimerNodo(TipoBase v){
	l = new Nodo;

	l->info = v;
	l->sig = 0;
}

/********************************************************************************************/
/*******************************************************************************************/

void MiLista :: LiberaMem(){
	
	if(l) { // Prevenir de la lista vacía

		PNodo aux = l; // Colocar aux al principio

		while (aux->sig != 0) {
			aux = aux->sig;	//adelantar aux
			delete l;	//borrar l
			l = aux;	//actualizar l
		}
		delete l; // Borrar el único nodo que queda
	}

	l = 0;
}

void MiLista :: CopiarDatos(const MiLista &otro){
	num_nodos = otro.num_nodos;
	
	PNodo aux = l;
	PNodo aux2 = otro.l;

	if(l){
		for(int i = 1; i <= num_nodos; i++){
			aux->info = aux2->info;
			aux = aux->sig;
			aux2 = aux2->sig;
		}
	}
}



/********************************************************************************************/
/*******************************************************************************************/
//
//	SOBRECARGA DE OPERADORES
//	
/********************************************************************************************/
/*******************************************************************************************/

MiLista & MiLista :: operator = (const MiLista &otro){
	if(this != &otro){
		LiberaMem();

		ReservaMem(otro.num_nodos);

		CopiarDatos(otro);
	}

	return(*this);
}

MiLista & MiLista :: operator = (TipoBase valor){
	
	LiberaMem();	//libero la memoria

	ReservaMem(num_nodos);	//vuelvo a crear la lista con los nodos con valor basura

	MismoValor(valor);	//pongo todos los nodos al mismo valor

	return(*this);
}

TipoBase & MiLista :: operator [] (const int indice){
	PNodo aux = BuscaNodo(indice);

	return(aux->info);
}