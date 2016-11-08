
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
//Cola.h
// 
//
/***************************************************************************/

#ifndef Cola
#define COLA

typedef int TipoBase;

struct Nodo{
	TipoBase info;
	Nodo *sig;
};

typedef Nodo * Cola;	//lo uso para referirme a una lista entera
typedef Nodo * PNodo;	//lo uso para referirme a nodos en concreto

class CCola{
	private:
		Cola l;	//puntero que apuntará al primer nodo del heap
		int num_nodos;

	public:
		/*************************************************/
		//
		//Constructores
		//
		/************************************************/
		CCola();

		/*************************************************/
		//
		//Destructor
		//
		/************************************************/
		~CCola();
		/*************************************************/
		//
		//Métodos
		//
		/************************************************/
		bool ColaVacia()const;
		TipoBase Extraer();
		void AniadeValor(TipoBase);
		TipoBase LeerCabecera()const;
	private:
		void ReservaMem();
		void ReservaPrimerNodo(TipoBase);
		void LiberaMem();
};

#endif