//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
// Lista_ConstructorCopia.cpp
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
#include "Lista_ConstructorCopia.h"
#include <iostream>

using namespace std;

MiLista :: MiLista(){
	num_nodos = 0;
	ReservaMem(num_nodos);
}

MiLista :: MiLista(int nodos){
	num_nodos = nodos;
	ReservaMem(num_nodos);
	MismoValor();
}

MiLista :: MiLista(int nodos, TipoBase valor){
	num_nodos = nodos;
	ReservaMem(num_nodos);
	MismoValor(valor);
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
	bool vacio = false;

	if(!l)
		vacio = true;

	return(vacio);
}

/********************************************************************************************/
/*******************************************************************************************/

int MiLista :: GetNodos() const{
	return(num_nodos);
}

/********************************************************************************************/
/*******************************************************************************************/

void MiLista :: InsertarValor(TipoBase valor, int pos){
	int posicion = pos - 1;
	
	if(!l && pos == 1){
		//si la lista está vacía y lo que quiero es insertar el primer nodo
		ReservaPrimerNodo(valor);
		num_nodos++;
	}	
	else{
		if(l && pos == 1){	//lista no vacía, pero quiero insertar el primer nodo
			PNodo anterior = l;
			//anterior tiene la direccion del actual primer nodo

			ReservaPrimerNodo(valor);
			l->sig = anterior;	//engancho la lista al primer nodo
			num_nodos++;
		}
		else{
			if(l && posicion < num_nodos){	//si lo que quiero es insertar un valor al final
				PNodo anterior, siguiente;
				anterior = l;
				siguiente = l->sig;

				cout << " " << anterior->info << " " << siguiente->info << endl;
				int i = 0;

				while(siguiente->sig != 0 && i < posicion){
					siguiente = siguiente->sig;
					anterior = anterior->sig;
					i++;
				}

				PNodo tmp = new Nodo;
				tmp->info = valor;
				anterior->sig = tmp;
				tmp ->sig = siguiente;
				
				num_nodos++;
			}
			else{
				if(l && posicion == num_nodos){	//si lo que quiero es insertar el valor al final 
					AniadeValor(valor);
				}
			}	
		}
	}	
}

/********************************************************************************************/
/*******************************************************************************************/

void MiLista :: AniadeValor(TipoBase valor){
	if(l){
		PNodo aux = l;	//recorrer el lista
		PNodo tmp;
		
		tmp = new Nodo;
		tmp->info = valor;

		while(aux){
			aux = aux->sig;
		}
		aux->sig = tmp;	//enlazo el nuevo nodo el finla de la lista
		tmp->sig = 0;
		num_nodos++;
	}
}

/********************************************************************************************/
/*******************************************************************************************/
void MiLista :: Borrar(int pos){
	int posicion = pos - 1;	//la lista para el usuario comienza en la posicion 1
	
	if(l && num_nodos == 1){	//sólo hay un nodo y se quiere borrar
		if(pos == 1){
			LiberaMem();
		}
	}
	else{
		if(l && pos == 1){	//se quiere borrar el primer elemento de la lista
			PNodo tmp = l->sig;	//"sujeto" el resto de la lista a patir del segundo nodo
			delete l;
			l = tmp;			//reasigno l
		}
		else{
			if(l && pos == num_nodos){	//si queremos borrar el último nodo
				PNodo tmp = l;
				while(tmp->sig != 0){	//me quedo en el penúltimo nodo
					tmp = tmp->sig;
				}
				delete tmp->sig;	//borro el último nodo
			}
			else{
				if(l && posicion < num_nodos){	//borrar un elemento cualquiera
					PNodo anterior, borra;
					anterior = l;
					borra  = l->sig;

					//el primer nodo sabemos que no lo queremos borrar
					for(int i = 1; i < posicion && borra->sig != 0; i++){
						anterior = anterior->sig;
						borra = borra->sig;
					}

					PNodo tmp = borra->sig;
					anterior->sig = tmp;
					delete borra;
				}
			}
		}
	}

	num_nodos--;
}

/********************************************************************************************/
/*******************************************************************************************/

TipoBase MiLista :: LeerValor(int pos)const{
	int posicion = pos - 1;
	PNodo aux = l;

	if(l && posicion < num_nodos){
		for(int i = 0; i < posicion; i++)
			aux = aux->sig;

		return(aux->info);
	}
}

/********************************************************************************************/
/*******************************************************************************************/

void MiLista :: ModificarValor(int pos, TipoBase valor){
	int posicion = pos - 1;
	PNodo aux;

	if(l && posicion < num_nodos){
		for(int i = 0; i < posicion; i++)
			aux = aux->sig;

		aux->info = valor;
	}
}

/********************************************************************************************/
/*******************************************************************************************/

void MiLista :: MismoValor(TipoBase valor){
	
	if(l){
		PNodo p = l;
		for(int i = 0; i < num_nodos; i++){
			p->info = valor; 	
			p = p->sig;
		}
	}	
}

/********************************************************************************************/
/*******************************************************************************************/

void MiLista :: PintaLista(){
	PNodo aux = l;

	cout << "La lista es-> ";
	for(int i = 0; i < num_nodos; i++){
		cout << " " << aux->info;
		aux = aux->sig;
	}
	cout << endl;
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
		for(int i = 0; i < num_nodos; i++){
			aux->info = aux2->info;
			aux = aux->sig;
			aux2 = aux2->sig;
		}
	}
}