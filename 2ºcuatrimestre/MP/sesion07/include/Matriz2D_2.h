//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
//Matriz2D_2.h
//
/***************************************************************************/

#ifndef Matriz2D_2
#define MATRIZ2D_2

typedef int TipoBase;

typedef struct{
	TipoBase fils;
	TipoBase cols;
	TipoBase **datos;
}Matriz2D_2;

/***************************************************************************/
/***************************************************************************/
void CreaMatrizIndefinida(Matriz2D_2 &);
void LiberaMem(Matriz2D_2 &);
void CreaMatrizConValor(Matriz2D_2 &);
void CreaMatrizAleatoria(Matriz2D_2 &);
void Pinta(Matriz2D_2 );
Matriz2D_2 CopiaMatriz(Matriz2D_2 , Matriz2D_2);
Matriz2D_2 CreaSubmatriz(Matriz2D_2 , Matriz2D_2 , int , int , int , int);
void Intercambia2(TipoBase &p1, TipoBase &p2);
Matriz2D_2 EliminaFila(Matriz2D_2 , Matriz2D_2 , int);
Matriz2D_2 EliminaColumna(Matriz2D_2 , Matriz2D_2 , int );
Matriz2D_2 MatrizTraspuesta(Matriz2D_2,Matriz2D_2 );
Matriz2D_2 InvertirFilas(Matriz2D_2 , Matriz2D_2 );
/***************************************************************************/
/***************************************************************************/

#endif