//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
// Lista_ConstructorCopia.h
// 
//
/***************************************************************************/

#ifndef Lista_ConstructorCopia
#define LISTA_CONSTRUCTORCOPIA

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
		MiLista(int, TipoBase);
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
		int GetNodos()const;
		void InsertarValor(TipoBase ,int);
		void Borrar(int );
		void AniadeValor(TipoBase);
		TipoBase LeerValor(int )const;
		void ModificarValor(int, TipoBase);
		void MismoValor(TipoBase valor = 0);
		void PintaLista();

	private:
		void ReservaMem(int );
		void ReservaPrimerNodo(TipoBase);
		void LiberaMem();
		void CopiarDatos(const MiLista &);
		

};

#endif