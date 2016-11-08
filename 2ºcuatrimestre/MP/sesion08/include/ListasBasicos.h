//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
//ListasBasicos.h
//
/***************************************************************************/

#ifndef ListasBasicos
#define LISTASBASICOS

typedef double TipoBase;

struct Nodo{
	TipoBase info;
	Nodo *sig;
};

typedef Nodo * Lista;	//lo uso para la lista
typedef Nodo * PNodo;	//lo voy a usar para punteros auxiliares que apunten a un solo nodo

/***************************************************************************/
/***************************************************************************/

void InsertarPrimerNodo(Lista &, TipoBase );
void LeeLista(Lista &);
void PintaLista (const Lista );
void LiberaLista (Lista &);
bool ListaVacia (const Lista );
void RellenaListaAleatoriamente (Lista & , int,int, int);
int CuentaElementos (const Lista );
double Media (const Lista);
double Varianza (const Lista );
void OrdenaLista(Lista &);
void EliminaValor (Lista &, TipoBase );
void InsertaOrdenadamente (Lista &, TipoBase);
void MezclaListas (Lista &, Lista &, Lista &);
/***************************************************************************/
/***************************************************************************/

#endif