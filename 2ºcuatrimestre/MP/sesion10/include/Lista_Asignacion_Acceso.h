//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
// Lista_Asignacion_Acceso.h
// 
//
/***************************************************************************/

#ifndef Lista_Asignacion_Acceso
#define LISTA_ASIGNACION_ACCESO

typedef int TipoBase;

struct Nodo{
	TipoBase info;
	Nodo *sig;
};

typedef Nodo * Lista;	//lo uso para referirme a una lista entera
typedef Nodo * PNodo;	//lo uso para referirme a nodos en concreto

class MiLista{
	private:
		Lista l;	//puntero que apuntará al primer nodo del heap
		int num_nodos;

	public:
		/*************************************************/
		//
		//Constructores
		//
		/************************************************/
		
		MiLista();
		MiLista(int );
		MiLista(const MiLista &);

		/*************************************************/
		//
		//Destructor
		//
		/************************************************/
		
		~MiLista();
		
		/*************************************************/
		//
		//Métodos
		//
		/************************************************/
		bool ListaVacia()const;
		int GetNumNodos()const;
		void MismoValor(TipoBase valor = 0);
		PNodo BuscaNodo(const int )const;
		void Borra(int);
		void Elimina(TipoBase);
		void Inserta(TipoBase, int);
		int BuscaPos(TipoBase)const;
		MiLista & operator = (const MiLista & );
		MiLista & operator = (TipoBase);
		TipoBase & operator [] (const int );

	private:
		
		void ReservaMem(int );
		void ReservaPrimerNodo(TipoBase);
		void LiberaMem();
		void CopiarDatos(const MiLista &);


		

};

#endif