//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
//Matriz2D_1.h
//
/***************************************************************************/

#ifndef Matriz2D_1
#define MATRIZ2D_1

typedef int TipoBase;
//Defino el tipo Matriz2D_1
typedef struct{
	TipoBase fils;
	TipoBase cols;
	TipoBase **datos;
}Matriz2D_1;

/***************************************************************************/
/***************************************************************************/
void CreaMatrizIndefinida(Matriz2D_1 &);
void LiberaMem(Matriz2D_1 &);
void CreaMatrizConValor(Matriz2D_1 &);
void CreaMatrizAleatoria(Matriz2D_1 &);
void Pinta(Matriz2D_1 );
Matriz2D_1 CopiaMatriz(Matriz2D_1 , Matriz2D_1);
Matriz2D_1 CreaSubmatriz(Matriz2D_1 , Matriz2D_1 , int , int , int , int);
void Intercambia1(TipoBase &p1, TipoBase &p2);
Matriz2D_1 EliminaFila(Matriz2D_1 , Matriz2D_1 , int);
Matriz2D_1 EliminaColumna(Matriz2D_1 , Matriz2D_1 , int );
Matriz2D_1 MatrizTraspuesta(Matriz2D_1,Matriz2D_1 );
Matriz2D_1 InvertirFilas(Matriz2D_1 , Matriz2D_1 );
/***************************************************************************/
/***************************************************************************/

#endif