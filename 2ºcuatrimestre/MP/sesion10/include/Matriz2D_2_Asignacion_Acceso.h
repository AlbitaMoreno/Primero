//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
//Matriz2D_2_Asignacion_Acceso.h
//
/***************************************************************************/

#ifndef Matriz2D_2_Asignacion_Acceso
#define MATRIZ2D_2_ASIGNACION_ACCESO

typedef int TipoBase;

class Matriz2D_2{
	private:
		int filas,columnas;
		TipoBase **datos;

	public:
		/*************************************************/
		//
		//Constructores
		//
		/************************************************/
		Matriz2D_2();
		Matriz2D_2(int);
		Matriz2D_2(int ,int );
		Matriz2D_2(const Matriz2D_2 &);
		/*************************************************/
		//
		//Destructor
		//
		/************************************************/
		
		~Matriz2D_2();
		
		/*************************************************/
		//
		//Métodos
		//
		/************************************************/
		
		bool MatrizVacia()const;
		void MismoValor(TipoBase valor = 0);
		Matriz2D_2 & operator = (const Matriz2D_2 &);
		Matriz2D_2 & operator = (const TipoBase);
		TipoBase & operator () (const int , const int );
	private:
		void ReservaMem(int, int);
		void LiberaMem();
		void CopiaDatos(const Matriz2D_2 &);
};


#endif