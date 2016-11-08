//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
// Lista.cpp
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
#include "Lista.h"
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
	return(num_nodos);
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

void  MiLista :: Borra (int pos) {
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
	
	if(!l)
	{
		l = new Nodo;

		l->info = v;
		l->sig = 0;
	}
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

/********************************************************************************************/
/*******************************************************************************************/

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

/********************************************************************************************/
/*******************************************************************************************/

MiLista & MiLista :: operator +=(const TipoBase valor){
	
	if(l){
		PNodo aux = l;	//recorrer el lista
		PNodo tmp;
		
		tmp = new Nodo;
		tmp->info = valor;

		while(aux->sig){
			aux = aux->sig;
		}
		
		aux->sig = tmp;	//enlazo el nuevo nodo el finla de la lista
		tmp->sig = 0;
		num_nodos++;
	}
	
	return(*this);
}

MiLista & MiLista :: operator -= (const TipoBase valor){
	int pos = BuscaPos(valor);

	// Si pos > 0 se encontró el nodo buscado: eliminarlo
	if (pos > 0) 
		Borra(pos);
	
	return(*this);
}


/********************************************************************************************/
/*******************************************************************************************/
//Operadores logicos 


bool MiLista :: operator == (const MiLista &otro){
	int us1 = GetNumNodos();
	int us2 = otro.GetNumNodos();

	bool iguales = (us1 == us2 ? true : false);	//si el numero de elementos coinciden sigo comprobando
	
	PNodo p_l = l;
	PNodo p_otro = otro.l;
	
	if(iguales){
		while(iguales && p_l && p_otro){
			if(p_l->info != p_otro->info)
				iguales =false;
			
			else{
				p_l = p_l->sig;
				p_otro = p_otro->sig;
			}
		}
	}

	return(iguales);
}

bool MiLista :: operator != (const MiLista &otro){
	return (!(*this == otro));
}


bool MiLista :: operator > (const MiLista &otro){
	int contador = 0;
	int i = 0;
	bool mayor = true;
	
	PNodo p_l = l;
	PNodo p_otro = otro.l;
	
	while(p_l && p_otro){	//mientras ninguna lista llegue al final
		if(p_l->info > p_otro->info){
			contador++;
			p_l = p_l->sig;
			p_otro = p_otro->sig;
		}
		else{
			contador--;
			p_l = p_l->sig;
			p_otro = p_otro->sig;
		}
	}
	
	//si i llega al final del menor, pero quedan elementos 
	if(p_l && !p_otro){
		contador = contador + (GetNumNodos() - i);
	}
	else {
		if(!p_l && p_otro){
			contador = contador - (GetNumNodos() - i);
		}
	}
	//si el contador se ha puesto - entonces otro es mayor que el vector implicito
	if(contador < 0)
		mayor = false;
	
	return(mayor);
}


bool MiLista :: operator < (const MiLista &otro){
	return(!(*this == otro ) && !(*this > otro));
}

bool MiLista :: operator >= (const MiLista &otro){
	return((*this == otro) || (*this > otro));
}

bool MiLista :: operator <= (const MiLista &otro){
	return (!(*this > otro));
}

/********************************************************************************************/
/*******************************************************************************************/

MiLista operator +(const MiLista &l1,const MiLista &l2)
{	//hace la unión de dos listas
	int nodos = l1.GetNumNodos() + l2.GetNumNodos();
	MiLista res(nodos);	
	
	PNodo p_res = res.l;
	PNodo p_l = l1.l;
	PNodo p_otro = l2.l;
	
	//ahora mismo res.l está lleno de 0
	
	while(p_l){
		p_res->info = p_l->info;
		p_res = p_res->sig;
		p_l = p_l->sig;
	}
	
	while(p_otro){
		p_res->info = p_otro->info;
		p_res = p_res->sig;
		p_otro = p_otro->sig;
	}
		
	return(res);			
}

MiLista operator +(const MiLista &l, TipoBase valor){
	MiLista res;

	res = l;
	res+=valor;
	
	return(res);
}

MiLista operator + (TipoBase valor, const MiLista &l){
	return(l + valor);
}

MiLista operator -(const MiLista &l1, const MiLista &l2){
	MiLista res;
		
	res = l1;
	
	PNodo p_l2 = l2.l;
	PNodo p_res = res.l;
	
	while(p_l2){
		bool sigue = true;	//solo quiero borrar la primera aparicion que encuentre
		
		while(sigue && p_res->sig){
			if(p_res->info == p_l2->info){
				int pos = res.BuscaPos(p_res->info);
				res.Borra(pos);
				sigue = false;
			}
		
			p_res = p_res->sig;
		}
		
		p_l2 = p_l2->sig;
		p_res = res.l;	
	}
	
	return(res);
}


MiLista operator -(const MiLista &l, TipoBase valor){
	MiLista res, otro;
	
	otro.ReservaPrimerNodo(valor);
	
	res = l - otro;
	
	return(res);
}

//no le veo sentido a implementar la sobrecarga para el caso valor/lista



















