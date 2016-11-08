
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
// MiPila.h
// 
//
/***************************************************************************/

#ifndef MiPila
#define MIPILA

typedef int TipoBase;

struct Nodo{
	TipoBase info;
	Nodo *sig;
};

typedef Nodo * Pila;	//lo uso para referirme a una lista entera
typedef Nodo * PNodo;	//lo uso para referirme a nodos en concreto

class MiPila{
	private:
		Pila l;	//puntero que apuntará al primer nodo del heap
		PNodo fin;
		int num_nodos;

	public:
		/*************************************************/
		//
		//Constructores
		//
		/************************************************/
		MiPila();
		MiPila(const MiPila &);

		/*************************************************/
		//
		//Destructor
		//
		/************************************************/
		~MiPila();
		/*************************************************/
		//
		//Métodos
		//
		/************************************************/
		bool PilaVacia()const;
		TipoBase Extraer();
		void AniadeValor(TipoBase);
		TipoBase LeerTope()const;
	private:
		void ReservaMem();
		void ReservaPrimerNodo(TipoBase);
		void LiberaMem();
		void CopiarDatos(const MiPila &);
};

#endif