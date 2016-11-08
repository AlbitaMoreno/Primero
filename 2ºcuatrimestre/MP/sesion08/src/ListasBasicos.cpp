//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
//ListasBasicos.cpp
//
/***************************************************************************/

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include "Random.h"
#include "ListasBasicos.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/

void InsertarPrimerNodo(Lista &l, TipoBase v){
	l = new Nodo;

	l->info = v;
	l->sig = 0;
}

/***************************************************************************/
/***************************************************************************/

void LeeLista(Lista &l){
	PNodo fin;
	TipoBase dato;

	l = 0;
	cout << "Vamos a rellenar la lista" << endl;
	cout << "Introduce un dato mayor que 0 " << endl;
	cin >> dato;

	if(dato >= 0){

		InsertarPrimerNodo(l,dato);

		fin = l;

		cout << "Introduce un dato (para acabar introduce un num < 0) " << endl;
		cin >> dato;

		while(dato >= 0){
			fin->sig = new Nodo;
			fin = fin->sig;

			fin->info = dato;
			fin->sig = 0;

			cout << "Introduce un dato (para acabar introduce un num < 0) " << endl;
			cin >> dato;
		}
	}
	cout << endl;
}

/***************************************************************************/
/***************************************************************************/

void PintaLista (const Lista l){
	PNodo aux = l;
	cout << "La lista es ..." << endl;
	while(aux != 0){
		cout << " " << aux->info;
		aux = aux->sig;
	}
	cout << endl;
}

/***************************************************************************/
/***************************************************************************/

void LiberaLista (Lista & l){
	if (!ListaVacia(l)) { // Prevenir de la lista vacía

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

/***************************************************************************/
/***************************************************************************/

bool ListaVacia (const Lista l){
	bool vacio = false;

	if(l == 0)
		vacio = true;

	return(vacio);
}

/***************************************************************************/
/***************************************************************************/

void RellenaListaAleatoriamente (Lista & l, int num_datos,int min, int max){
	MyRandom generador (min,max);
	l = 0;

	if(num_datos > 0){
		PNodo fin;
		InsertarPrimerNodo(l, generador.Next());
		
		fin = l;

		for(int i = 1; i < num_datos; i++){
			fin->sig = new Nodo;
			fin = fin->sig;
			fin->info = generador.Next();
			fin->sig = 0;
		}
	}	
}

/***************************************************************************/
/***************************************************************************/

int CuentaElementos (const Lista l){
	Lista aux = l;
	int cont = 0;

	while(aux != 0){
		cont++;
		aux = aux->sig;
	}
	return(cont);
}

/***************************************************************************/
/***************************************************************************/

double Media (const Lista l){
	double media = 0;
	Lista aux = l;

	if(!ListaVacia(l)){
		while(aux != 0){
			media +=aux->info;
			aux = aux->sig;
		}
		media = media/CuentaElementos(l);
	}
	else
		media = 0;

	return(media);
}

/***************************************************************************/
/***************************************************************************/

double Varianza (const Lista l){
	double varianza = 0;
	Lista aux = l;
	
	if(ListaVacia(l)){
		while(aux != 0){
			varianza = varianza + pow((aux->info-Media(l)),2);
			aux = aux->sig;
		}
		varianza = varianza/CuentaElementos(l);
	}
	else
		varianza = 0;

	return(varianza);
}

/***************************************************************************/
/***************************************************************************/

void OrdenaLista(Lista &l){
	PNodo aux, aux2;
	TipoBase tmp;

	aux = l;

	if(!ListaVacia(l)){
		//si la lista tiene un elemento esta ordenanda
	    if(CuentaElementos(l) > 1){
			while(aux->sig != 0){
				aux2 = aux->sig;

				while(aux2 != 0){
					if(aux->info > aux2->info){
						tmp = aux2->info;
						aux2->info = aux->info;
						aux->info = tmp;
					}
					aux2 = aux2->sig;
				}
				aux = aux->sig;
				aux2 = aux->sig;
			}
	    }
	}
	else
		cout << "Lista vacía" << endl;	   
}

/***************************************************************************/
/***************************************************************************/

void EliminaValor (Lista &l, TipoBase v){
	PNodo anterior,siguiente;
	anterior = l;
	siguiente = l->sig;

	if(!ListaVacia(l)){

		if(CuentaElementos(l) == 1){
			
			if(anterior->info == v)
				LiberaLista(l);
		}
		else{
			if(anterior->info == v){
				PNodo tmp = anterior;
				l = siguiente;
				delete tmp;
			}
			while(siguiente != 0 && siguiente->info != v){
				//en caso de no encontrar el valor sigo avanzando en la lista
				anterior = anterior->sig;	
				siguiente = siguiente->sig;
			}
			
			if(siguiente->info == v){
				PNodo tmp;
				tmp = siguiente->sig;	//"sujeto" el nodo al qe apunta siguiente
				delete siguiente;	//borro el nodo que tiene el valor
				anterior->sig = tmp;	//hago que anterior, apunte al nodo siguiente al borrado
			}
		}
	}
	
}

/***************************************************************************/
/***************************************************************************/

void InsertaOrdenadamente (Lista &l, TipoBase v){
	
	if(ListaVacia(l))
		InsertarPrimerNodo(l,v);	
	
	else{
		PNodo anterior, siguiente;
		PNodo tmp = new Nodo;
		anterior = l;
		siguiente = l->sig;

		//si el primer nodo es más grande que v, tenemos que reemplazar el primer nodo
		if(anterior->info > v){
			tmp->info = v;
			tmp->sig = anterior;
			l = tmp;
		}
		else{
			//busco el valor 
			while(siguiente && siguiente->info < v){
				siguiente = siguiente->sig;
				anterior = anterior->sig;
			}
			//introducir el valor ordenado
			if(siguiente->info >= v){
				tmp->info = v;
				tmp->sig = siguiente;
				anterior->sig = tmp;
			}
			//si el nuevo nodo los tengo que poner al final;
			else{
				tmp->info = v;
				siguiente->sig = tmp;
				tmp->sig = 0;
			}
		}	
	}
}

/***************************************************************************/
/***************************************************************************/

void MezclaListas (Lista &l, Lista &l1, Lista &l2){
	PNodo p;
	PNodo p1 = l1;
	PNodo p2 = l2;

	if(!ListaVacia(l1) && !ListaVacia(l2)){
		//vamos a "crear el primer nodo de l"
		if(p1->info < p2->info){
			p = p1;
			l = p;
			p = p->sig;
			p1 = p1->sig;
		}
		else{
			p = p2;
			l = p;
			p2 = p2->sig;	
		}

		//una vez creado el primer nodo empezamos a comparar
		while(p1 != 0 && p2 != 0){
			//si p1 es menor que p2, añado p1 y lo adelanto
			if(p1->info < p2->info){
				//aisgno p1 a p
				p->sig = p1;
				//avanzo p
				p = p->sig;
				//avanzo p1
				p1 = p1->sig;
			}

			else{
				p->sig = p2;
				p = p->sig;
				p2 = p2->sig;
			}
		}

		if(p1 == 0){
			p->sig = p2;
			p2 = 0;
		}
		else {
			if(p2 == 0){
				p->sig = p1;
				p1 = 0;
			}
		}
	}
	else{
		if(ListaVacia(l1) && !ListaVacia(l2)){
			p = p2;
			l = p;
			p2 = 0;
		}
		else{
			p = p1;
			l = p;
			p1 = 0;
		}
	}

	l1 = 0;
	l2 = 0;

}
