//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
// Lista.h
// 
//
/***************************************************************************/

#ifndef Lista
#define LISTA

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
		int BuscaPos(TipoBase)const;
		
		/*************************************************/
		//
		//Sobrecarga de operadores
		//
		/************************************************/

		MiLista & operator = (const MiLista & );
		MiLista & operator = (TipoBase);
		TipoBase & operator [] (const int );
		MiLista & operator += (const TipoBase);
		MiLista & operator -= (const TipoBase);
		
		bool operator ==(const MiLista &);
		bool operator !=(const MiLista &);
		bool operator > (const MiLista &);
		bool operator < (const MiLista &);
		bool operator >= (const MiLista &);
		bool operator <= (const MiLista &);
		
		
		//Uso de funciones friend
		friend MiLista operator +(const MiLista &, const MiLista &);
		friend MiLista operator +(const MiLista &, TipoBase);
		friend MiLista operator +(TipoBase, const MiLista &);
		
		friend MiLista operator -(const MiLista &, const MiLista &);
		friend MiLista operator -(const MiLista &, TipoBase);
	private:
		
		void ReservaMem(int );
		void ReservaPrimerNodo(TipoBase);
		void LiberaMem();
		void CopiarDatos(const MiLista &);


		

};

#endif
